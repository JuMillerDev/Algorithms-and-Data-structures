#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Implementation of singly linked list

typedef struct element element;
typedef struct list list;

struct element
{
    void *data;
    struct element *next;
};

struct list
{
    element *head;
    element *tail;
    int size;
};

list *init_list()
{
    struct list *created_list = malloc(sizeof(struct list));
    created_list->head = NULL;
    created_list->size = 0;
    created_list->tail = NULL;

    return created_list;
}

void push_back(void *data, list *list)
{
    struct element *new = malloc(sizeof(struct element));
    new->data = data;
    new->next = NULL;
    if (list->head == NULL)
    {
        list->head = new;
        list->tail = new;
        list->size++;
    }
    else
    {
        struct element *tmp = list->head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new;
        list->size++;
        list->tail = new;
    }
}

void push_front(void *data, list *list)
{
    struct element *new = malloc(sizeof(struct element));
    new->data = data;
    new->next = list->head;
    list->head = new;

    if (list->tail == NULL)
    {
        list->tail = new;
    }

    list->size++;
}

void *show_elem(int n, list *list)
{
    struct element *tmp = malloc(sizeof(struct element));
    if (list->head == NULL)
    {
        fprintf(stderr, "No elements in list\n");
        exit(1);
    }
    else
    {
        tmp = list->head;
        int i = 0;
        while (n < list->size)
        {
            if (i == n)
            {
                return tmp->data;
            }
            tmp = tmp->next;
            i++;
        }
        fprintf(stderr, "No such element\n");
        exit(1);
    }
}

void pop_front(list *list)
{
    printf("popped element front\n");
    struct element *tmp = list->head;
    list->head = list->head->next;
    free(tmp);
    list->size--;
}

void pop_back(list *list)
{
    printf("popped element back\n");
    struct element *tmp = list->head;
    struct element *delete = list->tail;

    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = NULL;
    list->tail = tmp;
    free(delete);
    list->size--;
}

void pop_elem_index(int n, list *list)
{
    struct element *cur_elem = list->head;
    struct element *prev_elem = NULL;

    int list_size = list->size;

    if (list->head == NULL || n > list_size - 1)
    {
        fprintf(stderr, "Cannot pop element that doesn`t exist!");
        exit(1);
    }
    else if (n == 0)
    {
        pop_front(list);
        return;
    }
    else if (n == list_size - 1)
    {
        pop_back(list);
        return;
    }

    // when element is not the starting of ending element look for it in list

    int i = 0;

    while (cur_elem->next != NULL)
    {
        if (i == n)
        {
            prev_elem->next = cur_elem->next;
            break;
        }
        prev_elem = cur_elem;
        cur_elem = cur_elem->next;
        i++;
    }

    list->size--;
    free(cur_elem);
}

void show_list(list *list)
{
    if (list->head == NULL)
    {
        printf("The list is empty");
        return;
    }
    else
    {
        struct element *tmp = list->head;
        while (tmp != NULL)
        {
            printf("%d->", *(int *)tmp->data);
            tmp = tmp->next;
            if (tmp == list->tail)
            {
                printf("%d\n", *(int *)tmp->data);
                return;
            }
        }
    }
}

list *merge(list *first, list *second)
{
    struct list *merged_list = init_list();
    struct element *tmp = first->head;

    while (tmp != NULL)
    {
        push_back(tmp->data, merged_list);
        tmp = tmp->next;
    }

    tmp = second->head;

    while (tmp != NULL)
    {
        push_back(tmp->data, merged_list);
        tmp = tmp->next;
    }

    return merged_list;
}

int main()
{

    int elements_amount = 10000;
    int elements_tested[3] = {2000, 5000, 9998};
    int elements_tested_size = sizeof(elements_tested) / sizeof(elements_tested[0]);
    int average_measuring_repetitions = 10000;
    struct list *list = init_list();
    clock_t measured_time;
    double average_time;

    for (int i = 0; i < elements_amount; i++)
    {
        int *data = malloc(sizeof(int));
        *data = rand() % elements_amount;
        push_back(data, list);
    }

    printf("\nChecking average time for predifined index\n");

    int tested_element = 0;
    for (int i = 0; i < elements_tested_size; i++)
    {
        tested_element = elements_tested[i];

        measured_time = clock();
        for (int i = 0; i < average_measuring_repetitions; i++)
        {
            show_elem(tested_element, list);
        }
        measured_time = clock() - measured_time;
        average_time = (double)(measured_time) / (CLOCKS_PER_SEC * elements_tested_size);
        printf("Average time for element index %d: %lf\n", tested_element, average_time);
    }

    printf("\nChecking average time for random index\n");

    measured_time = clock();
    for (int i = 0; i < average_measuring_repetitions; i++)
    {
        show_elem(rand() % elements_amount, list);
    }
    measured_time = clock() - measured_time;

    average_time = (double)(measured_time) / (CLOCKS_PER_SEC * elements_tested_size);
    printf("Average time for random element indexes: %lf\n", average_time);

    return 0;
}
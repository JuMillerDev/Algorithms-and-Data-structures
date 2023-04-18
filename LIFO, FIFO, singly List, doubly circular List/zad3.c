#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Implementation of doubly circular linked list

typedef struct element element;
typedef struct list list;

struct element{
    void *data;
    struct element *next;
    struct element *prev;
};

struct list{
    element *head;
    element *tail;
    int size;
};

list *init_list(){
    struct list *created_list = malloc(sizeof(struct list));
    created_list->head = NULL;
    created_list->size = 0;
    created_list->tail = NULL;

    return created_list;
}

void push_back(void *data, list *list){
    struct element *new = malloc(sizeof(struct element)); 
    new->data = data;
    //new->next = NULL;
    if(list->head == NULL){
        list->head = new;
        list->tail = new;
        list->head->prev = new;
        list->head->next = new;
        list->tail->next = new;
        list->tail->prev = new;
        list->size++;
    }else{
        struct element *tmp = list->head;
        while(tmp->next != list->head){
            tmp = tmp->next;
        }
        tmp->next = new;
        new->next = list->head;
        new->prev = tmp;
        list->head->prev = new;
        list->tail = new;
        list->size++;
    }
}

void push_front(void *data, list *list){
    struct element *new = malloc(sizeof(struct element));
    new->data = data;

    if(list->tail == NULL){
        list->tail = new;
        list->head = new;
    }else{
        new->next = list->head;
        list->head->prev = new;
        list->head = new;
    }

    list->tail->next = list->head;
    list->head->prev = list->tail;
    list->size++;
}

void *show_elem(int n, list *list){
    struct element *tmp = malloc(sizeof(struct element));
    if(list->head == NULL || n >= list->size){
        fprintf(stderr,"Wrong parameters given. Aborting\n");
        exit(1);
    }else if(n <= (list->size)/2){
        tmp = list->head;
        int i = 0;
        while(n>0){
            if(i == n){
                return tmp->data;
            }
            tmp = tmp->next;
            i++;
        }
        fprintf(stderr, "No such element!");
        exit(1);
    }else{
        tmp = list->tail;
        int i = list->size-1;
        while (n>0)
        {
            if(i == n){
                return tmp->data;
            }
            tmp = tmp->prev;
            i--;
        }
        fprintf(stderr,"No such element\n");
        exit(1);
        
    }
}

void pop_front(list *list){
    struct element *tmp = list->head;
    list->head = list->head->next;
    list->head->prev = list->tail;
    list->tail->next = list->head;
    list->size--;
    free(tmp);
}

void pop_back(list *list){
    struct element *tmp = list->tail;
    struct element *new_tail = list->tail->prev;
    new_tail->next = list->head;
    list->tail = new_tail;
    list->head->prev = list->tail; 
    list->size--;
    free(tmp);
}

void pop_elem_index(int n, list *list){
    struct element *cur_elem = list->head;
    int i = 0;

    int list_size = list->size;
    if(list->head == NULL || n>list_size-1)
    {
        fprintf(stderr,"Cannot pop element that doesn`t exist!");
        exit(1);
    }else if (n == 0){
        pop_front(list);
        return;
    }else if (n == list_size-1)
    {
        pop_back(list);
        return;
    }else if(n <= (list->size)/2)
    {
        i = 0;
        while(i>=0){
            printf(".");
            if(i == n){
                cur_elem->prev->next = cur_elem->next;
                cur_elem->next->prev = cur_elem->prev;
                break;
            }
            cur_elem = cur_elem->next;
            i++;
        }
    }else
    {
        printf(".");
        i = list->size;
        while(i>0){
            if(i == n){
                cur_elem->prev->next = cur_elem->next;
                cur_elem->next->prev = cur_elem->prev;
                break; 
            }
            cur_elem = cur_elem->prev;
            i--;
        }
    }
    
    list->size--;
    free(cur_elem);
}

void show_list(list *list){
    if(list->head == NULL){
        printf("The list is empty");
        return;
    }else{
        struct element *tmp = list->head;
        while(tmp != NULL){
            printf("%d->",*(int*)tmp->data);
            tmp = tmp->next;
            if(tmp == list->tail){
                printf("%d\n", *(int*)tmp->data);
                return;
            }
        }
    }
}

list* merge(list *first, list *second){
    struct list *merged_list = init_list();

    struct element *tmp = first->head->next;
    push_back(first->head->data, merged_list);

    while (tmp != first->head)
    {
        push_back(tmp->data, merged_list);
        tmp = tmp->next;
    }

    tmp = second->head->next;
    push_back(second->head->data,merged_list);

    while (tmp != second->head)
    {
        push_back(tmp->data,merged_list);
        tmp = tmp->next;
    }
    
    return merged_list;
}

int main(){
    /* struct list *my_list = init_list();
    struct list *my_list2 = init_list();
    

    for (int i = 0; i < 10; i++)
    {
        int *data = malloc(sizeof(int));
        *data = i;
        push_front(data, my_list);
        push_back(data, my_list2);
    }

    pop_elem_index(6,my_list);

    struct element *tmp = my_list->head;
    int next = 0;
    int prev = 0;
    int curr = 0;
    for(int i = 0; i < 10; i++){

        next = *(int*)tmp->next->data;
        prev = *(int*)tmp->prev->data;
        curr = *(int*)tmp->data;

        printf("element: %d;    prev: %d, next: %d\n", curr,prev,next);

        tmp = tmp->next;
    }

    printf("getting element. List size = %d\n", my_list->size);

    printf("search for element index %d. Result is %d\n",5,*(int*)show_elem(5,my_list));
    printf("search for element index %d. Result is %d\n",4,*(int*)show_elem(4,my_list));
    printf("search for element index %d. Result is %d\n",2,*(int*)show_elem(2,my_list));
    printf("search for element index %d. Result is %d\n",8,*(int*)show_elem(8,my_list));

    struct list *merged = merge(my_list,my_list2);

    show_list(merged);
    printf("size: %d", merged->size); */

    int elements_amount = 10000;
    int elements_tested[3] = {2000,5000,9998};
    int elements_tested_size = sizeof(elements_tested)/sizeof(elements_tested[0]);
    int average_measuring_repetitions = 10000;
    struct list *list = init_list();
    clock_t measured_time;
    double average_time;
    

    for(int i = 0; i<elements_amount; i++){
        int *data = malloc(sizeof(int));
        *data = rand() % elements_amount;
        push_back(data, list); 
    }

    printf("\nChecking average time for predifined index\n");

    int tested_element = 0;
    for(int i = 0; i < elements_tested_size; i++){
        tested_element = elements_tested[i];

        measured_time = clock();
        for (int i = 0; i < average_measuring_repetitions; i++)
        {
            show_elem(tested_element,list);
        }
        measured_time = clock() - measured_time;
        average_time = (double)(measured_time) / (CLOCKS_PER_SEC * elements_tested_size);
        printf("Average time for element index %d: %lf\n",tested_element,average_time);
        
    }

    printf("\nChecking average time for random index\n");

    measured_time = clock();
    for(int i = 0; i < average_measuring_repetitions; i++){
        show_elem(rand() % elements_amount, list);
    }
    measured_time = clock() - measured_time;

    average_time = (double)(measured_time) / (CLOCKS_PER_SEC * elements_tested_size);
    printf("Average time for  random element indexes: %lf\n",average_time);


    return 0;
}
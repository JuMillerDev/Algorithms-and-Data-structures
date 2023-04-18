#include <stdio.h>
#include <stdlib.h>

//Implementation of LIFO stack

struct elementLifo{
    void *data;
    struct elementLifo *next;
};

struct elementLifo* head = NULL;

void push(void *data){
    struct elementLifo *new =malloc(sizeof(struct elementLifo));
    new->data = data;
    new->next = head;
    head = new;
    //added-next(head):  0 - NULL; 1 - 0; 2 - 1; 3 - 2; 4 - 3; 5 - 4
}

void* popLifo(){
    if(head == NULL){
        return NULL;
    }
    struct elementLifo *tmp = head;
    head = head->next;
    void *data = tmp->data;
    free(tmp);
    return data;
}

//--------------------------------------------------------------

//Implementation of FIFO queue

struct elementFifo{
    void *data;
    struct elementFifo *next;
};

struct elementFifo* queue = NULL;

void push_back(void *data){
    struct elementFifo *new = malloc(sizeof(struct elementFifo));
    new->data = data;
    new->next = NULL;
    if(queue == NULL){
        queue = new;
    }else{
        struct elementFifo *tmp = queue;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

void* popFifo(){
    if(queue == NULL){
        return NULL;
    }
    struct elementFifo *tmp = queue;
    void *data = tmp->data;
    queue = queue->next;
    free(tmp);
    return data;
}

//--------------------------------------------------------------

//Test

int main(){
    //Thanks to data type void* we can store any type of data in our stack and queue
    //In this example we will store integers

    //LIFO stack
    //Adding 100 elements to stack. Ints from 0 to 99
    int dataSize = 100;

    printf("LIFO stack:\n");

    for(int i = 0; i < dataSize; i++){
        int *data = malloc(sizeof(int));
        *data = i;
        push(data);
        printf("Pushed %d to stack\n", i);
    }

    //Processing stack
    //Popping 100 elements from stack
    for(int i = 0; i < dataSize; i++){
        int data = *(int*)popLifo();
        printf("Popped %d from stack\n", data);
    }

    //FIFO queue
    //Adding 100 elements to queue. Ints from 0 to 99

    printf("FIFO queue:\n");

    for(int i = 0; i < dataSize; i++){
        int *data = malloc(sizeof(int));
        *data = i;
        push_back(data);
        printf("Pushed %d to queue\n", i);
    }

    //Processing queue
    //Popping 100 elements from queue
    for(int i = 0; i < dataSize; i++){
        int *data = (int*)popFifo();
        printf("Popped %d from queue\n", *data);
    } 

    return 0;
}
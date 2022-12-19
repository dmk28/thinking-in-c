#include <stdio.h>

//Fila/Queue

//Fila de banco;
//O elemento que entra primeiro sai primeiro
//Sempre que um elemento é adicionado  à fila, ele fica no fim dela
//Sempre que removemos um elemento, o primeiro é removido

//FIFO -- FIRST IN FIRST OUT

//enqueue() //adds element to queue
//dequeue() //removes element from queue
//clear() // clears queue


// Queue structure
//fila[10] - [0][1][2][3][4][5][6][7][8][9]
//head -> top of queue, indicates who is the first
//tail -> bottom of queue, indicates the last element

//Application: any situation where we have to organize the elements

#define QUEUE_SIZE 15
int queue[QUEUE_SIZE] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int head = 0;
int tail = 0;

void list_elements() {
    printf("\n=================CURRENT QUEUE===================\n");
    for (int i = 0; i < QUEUE_SIZE; i++) {
        printf("-");
        printf("|%d|", queue[i]);
        printf("-");
        
    }
    printf("\nHead: %d\n", head);
    printf("Tail: %d\n", tail);
    printf("\n\n");
}

void enqueue() {
    int val;
    if (tail < QUEUE_SIZE) {
        printf("Inform the element you wish to add");
        scanf("%d", &val);
        queue[tail] = val;
        tail++;
        list_elements();
    } else {
        printf("Queue is full\n");
    }

    
}

void dequeue() {
    if(head < tail) {
        queue[head] = 0;
        head++;
        tail--;
        
        
        for (int i = 0; i < QUEUE_SIZE-1; i++) {
            queue[i] = queue[i+1];
            queue[i+1] = 0;
            
        }
       
    } else {
        printf("Queue is empty");
    }
}

void clear() {
    for (int i = 0; i < QUEUE_SIZE; i++) {
        queue[i] = 0;
    }
    head = 0;
    tail = 0;
}

int main() {
    int option = 0;

    do {
    printf("Choose:\n");
    printf("(1) - QUEUE\n");
    printf("(2) - DEQUEUE\n");
    printf("(3) - CLEAR QUEUE\n");
    printf("(4) - LIST ELEMENTS\n");
    printf("(-1) - EXIT\n");
    printf("Option: ");
    scanf("%d", &option);
    switch(option) {
        case 1:
                enqueue();
                break;
        case 2:
                dequeue();
                break;

        case 3: 
                clear();
                break;
        case 4:
                list_elements();
                break;
        case -1:
            printf("Bye");
            break;
        default:
            printf("Bye");
            break;
    }
   } while (option != -1);
    

    return 0;
}
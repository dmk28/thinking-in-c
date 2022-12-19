// STACK

//FILO - FIRST IN, LAST OUT
//LIFO -- LAST IN, FIRST OUT

//You always add to the top of the stack, while all the other elements go to the bottom.

//...
//[1]
//...


//Data is inserted always at the top
//Whenever a new element is inserted
//he is the next top of the stack.

//We can only access the element at the top.

//The insertion of the next element is called a 'push'.
//holy shit, JS is Stack-based lol
//The removal process of an element is called a 'pop'

//What are Stacks good for?

//Example: I just wrote this text.
//if I press CTRL+Z, what I just wrote is undone, and if I do it again, the line before that is wiped
//In other words, CTRL+Z or undo removes the last command, aka the last command written into the stack.

#include <stdio.h>
#include <stdlib.h>
/* 
#define TAMPILHA 15
int pilha[TAMPILHA] = {0};

 */
int top = 0;
int size = 0;
int *pilha;


void list_elements() {
    printf("+++++++++++++ C U R R E N T S T A C K ++++++++++++\n\n");
    for (int i = size; i >= 0; i--) {
        printf("-");
        printf("[%d]", pilha[i]);
        printf("-");
        printf("\n");
        
    }
    printf("\n\n");
    printf("Topo: %d", top);
   
}


void push() {
    int val;

   
    printf("Informe o valor");
    scanf("%d", &val);

    if (top < size) {
        pilha[top] = val;
        top++;
        list_elements();
        
    } else {
        printf("Pilha cheia");
    }
} 

void pop() {
    if (top >= 0) {
        pilha[top-1] = 0;
        top--;
        list_elements();

    } else {
        printf("Stack empty");
    }
    
}

void clear() {
    for (int i = 0; i < size; i++) {
        pilha[i] = 0;
    }
    top = 0;
}

int main() {
    int qtd = 0;
    pilha = calloc(qtd, sizeof(int));
    printf("Write the number of elements to this\n");
    scanf("%d", &qtd);
    size = qtd;
    
    for (int i = 0; i < qtd; i++) {
        pilha[i] = 0;
    }

    //options

    int opcao = 0;

    do {
        printf("Selecione a opcao:\n");
        printf("[1] - push\n");
        printf("[2] - pop\n");
        printf("[3] - list\n");
        printf("[4] - clear\n");
        printf("[-1] - QUIT");
        printf("\nDigite opcao:   ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                list_elements();
                break;
            case 4: 
                clear();
                break;
            case -1:
                break;
            default:
                printf("Invalida");
                break;

        }


    
    } while (opcao != -1);


    return 0;
}

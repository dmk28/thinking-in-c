#include <stdio.h>
#include <stdlib.h>


//Linked Lists possess a value and a pointer to the next element in the list
//the last element's pointer goes to NULL as that is the end of the list;
//We can insert elements at the start or at the end of the linked list.
struct st_knot {
    int value;
    struct st_knot *next;
};

typedef struct st_knot knot;

int empty(knot *ll) {
    if(ll->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void initialize(knot *ll) {
    ll->next = NULL;
}

void clearUp(knot *ll) {
    if (!empty(ll)) {
        knot *nextKnot, *current;
        current = ll->next;
        while (current != NULL) {
            nextKnot = current->next;
            free(current);
            current = nextKnot;
        }
    }
}

void display(knot *ll) {
    if(empty(ll)) {
        printf("List is empty\n\n");
        return;
    }

    knot *tmp;
    tmp = ll->next;


    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }

    printf("\n\n");
}

void insertStart(knot *ll) {
    knot *new = (knot*)malloc(sizeof(knot));
    if (!new) {
        printf("No memory available!\n");
        exit(1);
    } 
    printf("Inform the value: ");
    scanf("%d", &new->value);

    knot *oldHead = ll->next;
    ll->next = new;
    new->next = oldHead;


    }

void insertEnd(knot *ll) {
    knot *new = (knot*)malloc(sizeof(knot));
    if(!new) {
        printf("No memory available.");
        exit(1);

    }
    printf("Inform the value: ");
    scanf("%d", &new->value);
    new->next = NULL;

    if (empty(ll)) {
        ll->next = new;
    } else {
        knot *tmp = ll->next;

        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
    
}

void option(knot *ll, int op) {
    switch(op) {
        case 0:
            clearUp(ll);
            break;
        case 1:
            display(ll);
            break;
        case 2:
            insertStart(ll);
            break;
        case 3:
            insertEnd(ll);
            break;
        case 4:
            initialize(ll);
            break;
        default:
            printf("Invalid command\n\n");
    }
}


int menu(){
    int opt;

    printf("Choose: \n\n");
    printf("[0] - Exit\n");
    printf("[1] - List\n");
    printf("[2] - Add at the Start\n");
    printf("[3] - Add at the End\n");
    printf("[4] - Clear List\n");
    printf("Choice:  ");
    scanf("%d", &opt);

    return opt;
}


int main() {
    knot *ll = (knot *)malloc(sizeof(knot));
    
    if(!ll) {
        printf("No available memory");
        exit(1);
    }
    initialize(ll);

    int opt;

    do {
        opt=menu();
        option(ll, opt);
    } while(opt);

    free(ll);

    return 0;
}
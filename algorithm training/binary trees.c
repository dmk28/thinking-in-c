#include <stdlib.h>
#include <stdio.h>
// Arvore Binária

//Binary Tree

//São estruturas de dados caracterizados por:

//ou nao tem elemento algum (arvore vazia)
//ou tem um elemento distinto, denominado raiz, 
//com dois apontamentos para duas estruturas diferentes
//denominadas sub arvore esquerda e sub arvore direita

//a árvore binária só aponta, no máximo, para 2 elementos

//os elementos mais abaixo que não apontam para ninguém são chamados de folhas

//os apontamentos são chamados de arestas 

struct treeNode {
    int value;
    struct treeNode *rightNode;
    struct treeNode *leftNode;
};

typedef struct treeNode tree;

tree* createTree() {
    return NULL;
}

int treeIsEmpty(tree* t) {
    return t == NULL;
}

void showTree(tree* t) {
    printf("<");
    if(!treeIsEmpty(t)){
        printf("%d ", t->value);
        showTree(t->rightNode);
        showTree(t->leftNode);

    }

    printf(">");
}


void insertDataInTree(tree** t, int num) {
    if (*t == NULL) {
        *t = (tree*)malloc(sizeof(tree));
        (*t)->leftNode = NULL;
        (*t)->rightNode = NULL;
        (*t)->value = num;

    } else {
        if (num < (*t)->value) {
            insertDataInTree(&(*t)->leftNode, num);
        }
        if (num > (*t)->value) {
            insertDataInTree(&(*t)->leftNode,num);
        }
    }
}

int isInTree(tree* t, int num) {
    if(treeIsEmpty(t)) {
        return 0;
    }

    return t->value==num || isInTree(t->leftNode, num) || isInTree(t->rightNode, num);
}

int main() {

    tree *t = createTree();

    insertDataInTree(&t, 12);
    insertDataInTree(&t, 15);
    insertDataInTree(&t, 10);
    insertDataInTree(&t, 13);
    
    showTree(t);

    if (treeIsEmpty(t)) {
        printf("\n\nEmpty tree\n\n");
    } else {
        printf("\n\nTree not empty!\n");

    }

    int checkElement;

    printf("Type a number");
    scanf("%d", &checkElement);

    if (isInTree(t, checkElement)) {
        printf("Element %d is in tree", checkElement);
    } else {
        printf("Element %d is not in tree", checkElement);
        printf("\nWe'll add it for you");
        insertDataInTree(&t, checkElement);
        

    }
    showTree(t);
    return 0;
}


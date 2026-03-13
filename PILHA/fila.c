#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

#define MAXTAM 5

struct fila{
    int item[MAXTAM];
    int inicio, fim, qtd;
};

Fila* criarFila(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if(f != NULL){
        f->inicio= 0;
        f->fim = -1;
        f->qtd = 0;
    }

    return f;
}

int filaCheia(Fila* f){
    return f->qtd == MAXTAM;
}

int filaVazia(Fila* f){
    return f->qtd == 0;
}

int enfileirar(Fila *f, int valor){
    if(filaCheia(f))
        return ERROR;

    f->fim = (f->fim+1) % MAXTAM;
    f->item[f->fim] = valor;
    f->qtd++;
    return SUCCESS;
}

int desenfileirar(Fila *f, int *valor){
    if (filaVazia(f))
        return ERROR;
        
    *valor = f->item[f->inicio];
    f->inicio = (f->inicio+1) % MAXTAM;
    f->qtd--;
    return SUCCESS;
}

int obterPrimeiro(Fila* f, int *valor){
    if (filaVazia(f))
        return ERROR;
        
    *valor = f->item[f->inicio];
    return SUCCESS;
}

void liberarFila(Fila* f){
    free(f);
}

void mostrarFila(Fila* f){
    if(filaVazia(f))
        printf("Fila vazia!");
    else{
        int i = f->inicio;
        for(int cont = 1; cont <= f->qtd; cont++){
            printf("%d \n", f->item[i]);
            i = (i + 1) % MAXTAM;
        }
    }
}
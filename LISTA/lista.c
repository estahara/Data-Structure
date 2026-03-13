#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

#define MAX_SIZE 5

struct lista {
    int item[MAX_SIZE];
    int quantidade;
};

Lista* criarLista() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    if (lista)
        lista->quantidade = 0;
    return lista;
}

int listaCheia(Lista *lista) {
    return lista->quantidade == MAX_SIZE;
}

int listaVazia(Lista *lista) {
    return lista->quantidade == 0;
}

int inserir(Lista *lista, int valor, int pos) {
    if (listaCheia(lista))
        return ERROR;

    if (pos < 0 || pos > lista->quantidade) 
        return ERROR;
    
    for (int i = lista->quantidade; i > pos; i--) 
        lista->item[i] = lista->item[i - 1];

    lista->item[pos] = valor;
    lista->quantidade++;

    return SUCCESS;
    
}

int remover(Lista *lista, int pos, int *valorRemovido) {
    if (listaVazia(lista))
        return ERROR;

    if (pos < 0 || pos >= lista->quantidade)
        return ERROR;
    
    *valorRemovido = lista->item[pos];

    for (int i = pos; i < lista->quantidade - 1; i++) 
        lista->item[i] = lista->item[i + 1];

    lista->quantidade--;

    return SUCCESS;
    
}

int buscar(Lista *lista, int valorProcurado, int *pos) {
    if (listaVazia(lista))
        return ERROR;
    
    for (int i = 0; i < lista->quantidade; i++) {
        if (lista->item[i] == valorProcurado) {
            *pos = i;
            return SUCCESS;
        }
        
    }

    return ERROR;

}

void liberarLista(Lista *lista) {
    free(lista);
}

void mostrarLista(Lista *lista) {
    if (listaVazia(lista)) 
        printf("Lista vazia!");
    else 
        for (int i = 0; i < lista->quantidade; i++)
            printf("%d \n", lista->item[i]);
}




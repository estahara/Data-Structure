#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {

    Lista *lista = criarLista();
    if (!lista){
        printf("Não foi possivel criar a lista");
        return 1;
    }

    inserir(lista, 10, 0);
    inserir(lista, 20, 1);
    inserir(lista, 30, 0);

    mostrarLista(lista);
    printf("\n");

    int index = -1;
    buscar(lista, 20, &index);
    printf("Valor encontrado na pos: %d", index);

    int valorRemovido;
    remover(lista, 0, &valorRemovido);
    printf("\n Valor removido: %d \n", valorRemovido);

    mostrarLista(lista);
    printf("\n");

    liberarLista(lista);
    
    return 0;
}
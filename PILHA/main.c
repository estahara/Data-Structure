#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int main(){
    Fila *f = criarFila();
    if(f == NULL){
        printf("Não foi possível criar a fila");
        return 1;
    }

    enfileirar(f, 10);
    enfileirar(f, 100);
    enfileirar(f, 30);
    enfileirar(f, 50);
    mostrarFila(f);

    return 0;
}
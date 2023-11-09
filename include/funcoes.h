#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./registros.h"



void inserir_pessoa_fim(int x, pessoas*&lst){
    pessoas *novo, *p;
    // novo = (celula*) malloc(sizeof(celula));
    novo->prox = NULL;
    novo = (pessoas*) calloc(1, sizeof(pessoas));
    novo->chave = x;
    if(lst == NULL) /*lista esta vazia*/
        lst = novo;
    else{
        p = lst;
        while(p->prox != NULL)
           p = p->prox;
        p->prox = novo;
    }
}


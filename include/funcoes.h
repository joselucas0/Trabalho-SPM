#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./registros.h"



void inserir_pessoa_fim(pessoas*lst, pessoas*adicionado){
        pessoas*p;
        if(lst==NULL){
            lst=adicionado;
        }else{
            p=lst;
            while(p->prox != NULL){
                p=p->prox;
            }
            p->prox=adicionado;
        }
}

void inserir_policial_fim(policiais*lst, policiais*adicionado){
        policiais*p;
        if(lst==NULL){
            lst=adicionado;
        }else{
            p=lst;
            while(p->prox != NULL){
                p=p->prox;
            }
            p->prox=adicionado;
        }
}


void inserir_viatura_fim(viaturas*lst, viaturas*adicionado){
        viaturas*p;
        if(lst==NULL){
            lst=adicionado;
        }else{
            p=lst;
            while(p->prox != NULL){
                p=p->prox;
            }
            p->prox=adicionado;
        }
}

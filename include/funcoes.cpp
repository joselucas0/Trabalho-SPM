#include <stdio.h>
#include <stdlib.h>
#include "registros.h" 

void ViaturaLogin(int tipo)
{
    int cod_viatura, qntd;
    policiais *pms;
    printf("            SPM - Viatura Login \n");
    printf("Codigo da Viatura: ");
    scanf("%d", &cod_viatura);
    printf("Quantidade de Policiais: ");
    scanf("%d", &qntd);

    // Aloca memória para os policiais
    pms = (policiais *)malloc(qntd * sizeof(policiais));

    if (tipo == 1)
    {
        if (qntd > 4 || qntd < 2)
        {
            printf("Autorizacao de embarque negada\n");
        }
    }
    if (tipo == 2)
    {
        if (qntd != 4)
        {
            printf("Autorizacao de embarque negada\n");
        }
    }
    printf("            SPM - Viatura Login \n");
    printf("Identificacao dos PMs: \n");
    for (int i = 0; i < qntd; i++)
    {
        printf("Nome do Policial %d: ", i + 1);
        scanf(" %[^\n]", pms[i].nome);
        
    }
    printf("            SPM - Viatura Estado Neutro \n");

    int opc;
    printf("1 - Apto para atender ocorrencia");
    printf("2 - Cancelar Embarcacao");
    scanf("%d", &opc);
    if(opc == 1){

    }
    else if(opc == 2){
        //voltar para o menu
    }
    else{
        printf("opcao indisponivel");
        //finalizar
    }

    free(pms);
}

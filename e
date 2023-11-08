#include <stdio.h>
#include <stdlib.h>

// Definição das estruturas de dados
typedef struct
{
    int id;
    char nome[100];
    char endereco[100];
    char email[100];
} Pessoa;

typedef struct
{
    int id;
    char nome[100];
    char localizacao[100];
    int id_pessoa;
} Policial;

typedef struct
{
    int id;
    char nome[100];
    char localizacao[100];
    int id_pessoa;
} Viatura;

// Funções para carregar os dados das pessoas, policiais e viaturas
Pessoa *carregar_dados_pessoas(const char *arquivo, int *qtd)
{
    FILE *fp = fopen(arquivo, "r");
    if (!fp)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fscanf(fp, "%d", qtd);

    Pessoa *pessoas = (Pessoa *)malloc(*qtd * sizeof(Pessoa));
    if (!pessoas)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < *qtd; i++)
    {
        fscanf(fp, "%d %s %s %s", &pessoas[i].id, pessoas[i].nome, pessoas[i].endereco, pessoas[i].email);
    }

    fclose(fp);
    return pessoas;
}

Viatura *carregar_dados_viaturas(const char *arquivo, int *qtd)
{
    FILE *fp = fopen(arquivo, "r");
    if (!fp)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fscanf(fp, "%d", qtd);

    Viatura *viaturas = (Viatura *)malloc(*qtd * sizeof(Viatura));
    if (!viaturas)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < *qtd; i++)
    {
        fscanf(fp, "%d %s %s %d", &viaturas[i].id, viaturas[i].nome, viaturas[i].localizacao, &viaturas[i].id_pessoa);
    }

    fclose(fp);
    return viaturas;
}

Policial *carregar_dados_policiais(const char *arquivo, int *qtd)
{
    FILE *fp = fopen(arquivo, "r");
    if (!fp)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fscanf(fp, "%d", qtd);

    Policial *policiais = (Policial *)malloc(*qtd * sizeof(Policial));
    if (!policiais)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < *qtd; i++)
    {
        fscanf(fp, "%d %s %s %d", &policiais[i].id, policiais[i].nome, policiais[i].localizacao, &policiais[i].id_pessoa);
    }

    fclose(fp);
    return policiais;
}

// Função para verificar o login da viatura
void viaturaLogin(Viatura *viaturas, int qtd_viaturas)
{
    int cod_viaturas;
    int qntd_PMs;

    printf("Código da Viatura: ");
    scanf("%d", &cod_viaturas);
    printf("Quantidade de PMs: ");
    scanf("%d", &qntd_PMs);

    for (int i = 0; i < qtd_viaturas; i++)
    {
        if (viaturas[i].id == cod_viaturas)
        {
            printf("Viatura: %s\n", viaturas[i].nome);
            printf("Localização: %s\n", viaturas[i].localizacao);
            printf("PMs: %d\n", qntd_PMs);
            return;
        }
    }

    printf("Viatura não encontrada.\n");
}

int main()
{
    int qtd_pessoas;
    int qtd_viaturas;
    int qtd_policiais;

    Pessoa *pessoas = carregar_dados_pessoas("pessoas.txt", &qtd_pessoas);
    Viatura *viaturas = carregar_dados_viaturas("viaturas.txt", &qtd_viaturas);
    Policial *policiais = carregar_dados_policiais("policiais.txt", &qtd_policiais);

    // Menu para selecionar a função desejada
    int opcao;
    do
    {
        printf("Menu:\n");
        printf("1 - Verificar login da viatura\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            viaturaLogin(viaturas, qtd_viaturas);
            break;
        case 0:
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    // Liberar a memória alocada
    free(pessoas);
    free(viaturas);
    free(policiais);

    return 0;
}

#include "funcoes.h"

void viaturaLogin(Viatura *viaturas)
{
    int cod_viaturas;
    int qntd_PMs;

    printf("Código da Viatura: ");
    scanf("%d", &cod_viaturas);
    printf("Quantidade de PMs: ");
    scanf("%d", &qntd_PMs);

    int count = 0;
    for (int i = 0; i < qtd_viaturas; i++)
    {
        if (viaturas[i].id == cod_viaturas)
        {
            printf("Viatura: %s\n", viaturas[i].nome);
            printf("Localização: %s\n", viaturas[i].localizacao);
            printf("PMs: %d\n", qntd_PMs);
            return;
        }
        count++;
    }

    if (count == qtd_viaturas)
    {
        printf("Viatura não encontrada.\n");
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "registros.h" 


int pegarTamanhoArquivoDados(const char* arquivoNome) {
    FILE* arquivo;
    int tamanho = 0;
    int codigoCurso;

    arquivo = fopen(arquivoNome, "r");

    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s", arquivoNome);
        return 0;
    } else {
        fscanf(arquivo, "%d", &codigoCurso);

        while (!feof(arquivo)) {
            struct pessoas pessoa;
            fscanf(arquivo, "%[^\n]%*c", pessoa.nome);
            fscanf(arquivo, "%s", pessoa.cpf);
            fscanf(arquivo, "%[^\n]%*c", pessoa.cidade);
            fscanf(arquivo, "%d", &pessoa.idade);
            fscanf(arquivo, "%d", &pessoa.nPassagens);

            for (int i = 0; i < pessoa.nPassagens; i++) {
                fscanf(arquivo, "%[^\n]%*c", pessoa.passagens[i].crime);
            }

            fscanf(arquivo, "%d", &pessoa.inadimplencias[0].situacao);

            if (pessoa.inadimplencias[0].situacao) {
                fscanf(arquivo, "%[^\n]%*c", pessoa.inadimplencias[0].crime);
            }

            tamanho++;
        }
    }

    fclose(arquivo);

    return tamanho;
}

void ler_e_inserir(const char* arquivoNomePessoas, const char* arquivoNomePoliciais, const char* arquivoNomeViaturas) {
    FILE* arquivoPessoas, *arquivoPoliciais, *arquivoViaturas;

    arquivoPessoas = fopen(arquivoNomePessoas, "r");
    arquivoPoliciais = fopen(arquivoNomePoliciais, "r");
    arquivoViaturas = fopen(arquivoNomeViaturas, "r");

    if (!(arquivoPessoas && arquivoPoliciais && arquivoViaturas)) {
        printf("Erro ao abrir os arquivos!");
        return;
    } else {
        int tamanhoPessoas = pegarTamanhoArquivoDados(arquivoNomePessoas);
        int tamanhoPoliciais;

        fscanf(arquivoPoliciais, "%d", &tamanhoPoliciais);

        // Leitura dos dados do arquivo pessoas
        struct pessoas pessoas[tamanhoPessoas];

        for (int i = 0; i < tamanhoPessoas; i++) {
            fscanf(arquivoPessoas, "%[^\n]%*c", pessoas[i].nome);
            fscanf(arquivoPessoas, "%s", pessoas[i].cpf);
            fscanf(arquivoPessoas, "%[^\n]%*c", pessoas[i].cidade);
            fscanf(arquivoPessoas, "%d", &pessoas[i].idade);
            fscanf(arquivoPessoas, "%d", &pessoas[i].nPassagens);

            for (int j = 0; j < pessoas[i].nPassagens; j++) {
                fscanf(arquivoPessoas, "%[^\n]%*c", pessoas[i].passagens[j].crime);
            }

            fscanf(arquivoPessoas, "%d", &pessoas[i].inadimplencias[0].situacao);

            if (pessoas[i].inadimplencias[0].situacao) {
                fscanf(arquivoPessoas, "%[^\n]%*c", pessoas[i].inadimplencias[0].crime);
            }
        }

        // Leitura dos dados do arquivo policiais
        struct policiais policiais[tamanhoPoliciais];

        for (int i = 0; i < tamanhoPoliciais; i++) {
            fscanf(arquivoPoliciais, "%[^\n]%*c", policiais[i].nome);
            fscanf(arquivoPoliciais, "%s", policiais[i].cpf);
            fscanf(arquivoPoliciais, "%[^\n]%*c", policiais[i].nome_de_guerra);
            fscanf(arquivoPoliciais, "%[^\n]%*c", policiais[i].cidade);
            fscanf(arquivoPoliciais, "%d", &policiais[i].idade);
            fscanf(arquivoPoliciais, "%[^\n]%*c", policiais[i].cargo);
            fscanf(arquivoPoliciais, "%s", policiais[i].senha);
        }

        // Leitura dos dados do arquivo viaturas
        struct viaturas viaturas[MAX];
        int tamanhoViaturas = 0;

        while (!feof(arquivoViaturas)) {
            fscanf(arquivoViaturas, "%d", &viaturas[tamanhoViaturas].cod);
            fscanf(arquivoViaturas, "%s", viaturas[tamanhoViaturas].tipo);
            tamanhoViaturas++;
        }

        fclose(arquivoPessoas);
        fclose(arquivoPoliciais);
        fclose(arquivoViaturas);

        
    }
}






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


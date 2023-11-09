#include "funcoes.h"
#include "registros.h"




pessoas *carregarPessoas(pessoas* inicioLista) {
  FILE *arq;

  arq = fopen("./arquivos_entrada/pessoas.txt", "r");

  if (arq == NULL) {
    printf("O arquivo de cursos e pesos não foi encontrado!\n\n");
    return 0;
  }

  int i, in;
  pessoas* p;
  char nome[50];
  //*p representa o novo nó



  char passagem[50];
  in = fscanf(arq, "%s", nome);

  while (in != EOF) {
    p= (pessoas*)calloc(1, sizeof(pessoas));
    strcpy(p->nome, nome);
    fscanf(arq, " %s", p->cpf);
    fscanf(arq, "%s", p->cidade);
    fscanf(arq, "%d", &p->idade);
    fscanf(arq, "%d", &p->nPassagens);

    //ler passagens
    if(p->nPassagens>0){
        p->passagens = (passagem*)calloc(p->nPassagens, sizeof(passagem));
        for(i=0; i<p->nPassagens; i++){
          fscanf(arq, "%s", passagem);
          strcpy(p->passagens[i].nomePassagem, passagem);
        }
    }
    fscanf(arq, "%d", &p->nInadimplencia);
    //ler inadimplencias
    i++;

    //colocar p em iniciolista
    inserir_pessoa_fim(inicioLista, p);

    in = fscanf(arq, "%s", nome);

  }

  fclose(arq);
  return inicioLista;
}



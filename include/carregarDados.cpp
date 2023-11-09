#include "funcoes.h"
#include "registros.h"



//LER ARQUIVO DE PESSOAS
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


//LER ARQUIVO DE POLICIAIS
policiais *carregarPoliciais(policiais* inicioLista) {
  FILE *arq;

  arq = fopen("./arquivos_entrada/policiais.txt", "r");

  if (arq == NULL) {
    printf("O arquivo de cursos e pesos não foi encontrado!\n\n");
    return 0;
  }

  int i, in;
  policiais* p;
  char nome[50];
  //*p representa o novo nó


  in = fscanf(arq, "%s", nome);

  while (in != EOF) {
    p= (policiais*)calloc(1, sizeof(policiais));
    strcpy(p->nome, nome);
    fscanf(arq, " %s", p->cpf);
    fscanf(arq, "%s", p->nome_de_guerra);
    fscanf(arq, "%s", &p->cidade);
    fscanf(arq, "%d", &p->idade);
    fscanf(arq, "%s", &p->cargo);
    fscanf(arq, "%s", &p->senha);
    i++;

    //colocar p em iniciolista
    inserir_policial_fim(inicioLista, p);

    in = fscanf(arq, "%s", nome);

  }

  fclose(arq);
  return inicioLista;
}




//LER ARQUIVO DE VIATURAS
viaturas *carregarViaturas(viaturas* inicioLista) {
  FILE *arq;

  arq = fopen("./arquivos_entrada/viaturas.txt", "r");

  if (arq == NULL) {
    printf("O arquivo de cursos e pesos não foi encontrado!\n\n");
    return 0;
  }

  int i, in;
  viaturas* p;
  int cod;
  //*p representa o novo nó


  in = fscanf(arq, "%d", cod);

  while (in != EOF) {
    p= (viaturas*)calloc(1, sizeof(viaturas));
    p->cod = cod;
    fscanf(arq, " %s", p->tipo);

    i++;

    //colocar p em iniciolista
    inserir_viatura_fim(inicioLista, p);

    in = fscanf(arq, "%d", cod);

  }

  fclose(arq);
  return inicioLista;
}
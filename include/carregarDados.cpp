#include "./funcoes.h"
#include "./registros.h"



void adicionar(pessoas pessoa, pessoaNode *&lst)
{
    pessoaNode *nova;

    nova = (pessoaNode *) calloc(1, sizeof (pessoa));
    nova->pessoa = pessoa;
    nova->prox = lst;
    lst = nova;
}


pessoas *carregarPessoas() {
  FILE *arq;

  arq = fopen("./arquivos/pessoas.txt", "r");

  if (arq == NULL) {
    printf("O arquivo de cursos e pesos não foi encontrado!\n\n");
    return 0;
  }

  int i = 0;
  pessoaNode inicioLista;
  pessoas* p;

  while (p != EOF) {
    p = fscanf(arq, "%s", &p[i].nome);

    if (p == EOF)
      break;

    fscanf(arq, " %s", &p[i].cpf);
    fscanf(arq, "%s", &p[i].cidade);
    fscanf(arq, "%d", &p[i].idade);
    fscanf(arq, "%d", &p[i].nPassagens);
    //ler as passagens
    fscanf(arq, "%d", &p[i].nInadimplencia);
    //ler inadimplencias
    i++;
  }

  fclose(arq);
  return lPessoas;
}

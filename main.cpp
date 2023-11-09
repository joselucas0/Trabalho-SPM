#include "./include/funcoes.h"


int main()
{

  

tArquivos arquivosNomes;
FILE *arquivo01, *arquivo02, *arquivo04, *arquivo05;
tTamanhos tamanhos;
int op = -1;

do
{
  menu(programa);
} while (programa->opc != 0);
printf("Programa encerrado.\n");
}

// Definindo os nomes dos arquivos
strcpy(arquivosNomes.nome01, "pessoas.txt");
strcpy(arquivosNomes.nome02, "policiais.txt");
strcpy(arquivosNomes.nome03, "viatura.txt");
strcpy(arquivosNomes.nome04, "acertos.txt");
strcpy(arquivosNomes.nome05, "alteracaoNotaRedacao.txt");

// Abrindo os arquivos para leitura
arquivo01 = fopen(arquivosNomes.nome01, "r");
arquivo02 = fopen(arquivosNomes.nome02, "r");
arquivo04 = fopen(arquivosNomes.nome04, "r");
arquivo05 = fopen(arquivosNomes.nome05, "r");




if (!(arquivo01 && arquivo02 && arquivo04))
{
  printf("Erro ao abrir os arquivos!");
  return 0;
}
else
{
  // Lendo os valores dos arquivos e armazenando nas variáveis
  fscanf(arquivo01, "%d", &tamanhos.max01);
  fscanf(arquivo02, "%d", &tamanhos.max02);
  tamanhos.max03 = pegarTamanhoArquivoDados(arquivosNomes.nome03);
  fscanf(arquivo04, "%d", &tamanhos.max04);
  fscanf(arquivo05, "%d", &tamanhos.max05);

  // Exibindo os valores lidos dos arquivos
  printf("max01: %d\n", tamanhos.max01);
  printf("max02: %d\n", tamanhos.max02);
  printf("max03: %d\n", tamanhos.max03);
  printf("max04: %d\n", tamanhos.max04);
  printf("max05: %d\n", tamanhos.max05);

  fclose(arquivo01);
  fclose(arquivo02);
  fclose(arquivo04);
  fclose(arquivo05);
}
void menu(principal *programa)
{
  printf(".+*****+.Menu.+******+\n");
  if (!programa->dadosCarregados)

    printf("1 - Viatura Login\n");
  printf("2 - Viatura em uso\n");
  printf("3 - COPOM\n");
  printf("4 - Policial Militar\n");
  printf("5 - Oficial\n");
  printf("6 - Comandante Geral\n");
  printf("0 - Encerrar programa\n");

  scanf("%d", &programa->opc);
  printf("\n");

  if (programa->opc == 1 && !programa->dadosCarregados)
  {
  }

  if (programa->opc > 0 && programa->opc < 7 && !programa->dadosCarregados)
  {
    printf("Por favor carregue os dados antes que possa executar qualquer "
           "outra função!\n\n");
  }

  if (programa->opc == 2)
  {
  }

  if (programa->opc == 3)
  {
  }

  if (programa->opc == 4)
  {
  }

  if (programa->opc == 5)
  {
  }

  if (programa->opc == 6)
  {
  
  }
  free(pessoas);
  free(viaturas);
  free(policiais);
}
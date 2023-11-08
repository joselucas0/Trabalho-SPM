#include "./include/funcoes.h"

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

int main()
{
  int qtd_pessoas;
  int qtd_viaturas;
  int qtd_policiais;

  Pessoa *pessoas = carregar_dados_pessoas("pessoas.txt", &qtd_pessoas);
  Viatura *viaturas = carregar_dados_viaturas("viaturas.txt", &qtd_viaturas);
  Policial *policiais = carregar_dados_policiais("policiais.txt", &qtd_policiais);

  do
  {
    menu(programa);
  } while (programa->opc != 0);
  printf("Programa encerrado.\n");
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
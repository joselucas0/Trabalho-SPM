#include "./include/funcoes.h"


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
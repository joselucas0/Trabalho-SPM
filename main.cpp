#include "./include/funcoes.h"
#include "./include/registros.h"
#include "./include/carregarDados.cpp"


int main() {
  principal *programa = ( principal *)calloc(sizeof(principal));
  programa->dadosCarregados = false;

  programa->pessoas = carregarPessoas(programa->pessoas);

  if(programa->pessoas != NULL &&
     programa->policiais != NULL &&
     programa->viaturas != NULL){
        programa->dadosCarregados = true;
     }else{
      printf("ERRO AO CARREGAR ARQUIVOS");
     }

  do {
    menu(programa);
  } while (programa->opc != 0);
  printf("Programa encerrado.\n");
}

void menu(principal *programa) {
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

  if (programa->opc == 1) {
    
  }

  if (programa->opc == 2) {
    
  }

  if (programa->opc == 3) {
    
  }

  if (programa->opc == 4) {
    
  }

  if (programa->opc == 5) {
    
  }

  if (programa->opc == 6) {
    
  }

}
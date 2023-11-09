#include "./include/funcoes.h"



/*  COMO CARREGAR
    programa->dadosCarregados = true;
    programa->cursos_e_pesos = carregar_cursos_e_pesos();
    programa->cursos_e_vagas = carregar_cursos_e_vagas();
    programa->candidatos = carregar_dados(programa->qntdInscritos);
    programa->notas = carregar_acertos(programa->qntdCandidatos);
    calcularNotasArea(programa->notas, programa->candidatos,
    programa->cursos_e_pesos, programa->qntdCandidatos);
    ordenarCandidatos(programa->notas, programa->qntdCandidatos);   
*/
int main() {
  principal *programa = (struct principal *)calloc(sizeof(principal));
  programa->dadosCarregados = false;

  programa->pessoas = carregarPessoas(programa->pessoas);

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

  if (programa->opc == 1 && !programa->dadosCarregados) {
    
  }

  if (programa->opc > 0 && programa->opc < 7 && !programa->dadosCarregados) {
    printf("Por favor carregue os dados antes que possa executar qualquer "
           "outra função!\n\n");
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
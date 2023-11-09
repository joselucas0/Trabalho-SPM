#define MAX 80

struct policiais {
    char nome[50];
    char cpf[12];
    char nome_de_guerra[20];
    char cidade[50];
    int idade;
    char cargo[30];
    char senha[20];
    policiais*prox;
};


struct pessoas{
    char nome[50];
    char cpf[12];
    char cidade[50];
    int idade;
    int nPassagens;
    passagem *passagens;
    int nInadimplencia;
    inadimplencia *inadimplencias;
    pessoas * prox;
};

struct passagem{
    char nomePassagem[30];
};


struct viaturas{
    int cod;
    char tipo[20];
    viaturas*prox;
};




struct inadimplencia{
    char nomeInadimplencia[50];
};



struct principal {
  int opc;
  bool dadosCarregados;
  pessoas *pessoas;
  policiais *policiais;
  viaturas *viaturas;

};
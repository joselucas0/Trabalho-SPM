#define MAX 80

struct policiais {
    char nome[50];
    char cpf[12];
    char nome_de_guerra[20];
    char cidade[50];
    int idade;
    char cargo[30];
    char senha[20];
};


struct pessoas{
    char nome[50];
    char cpf[12];
    char cidade[50];
    int idade;
    int nPassagens;
    passagem passagens[2];
    inadimplencia inadimplencias[];
};

struct viaturas{
    int cod;
    char tipo[20];
};

struct passagem
{
    char crime[50];
};

struct inadimplencia
{
    int situacao;
    char crime[50];
};

struct
{
    char nome01[50];
    char nome02[50];
    char nome03[50];
    char nome04[50];
    char nome05[50];
} tArquivos;

struct
{
    int max01;
    int max02;
    int max03;
    int max04;
    int max05;
} tTamanhos;
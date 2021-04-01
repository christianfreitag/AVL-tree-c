#ifndef DEF_ARVORE_TRAB
#define DEF_ARVORE_TRAB

struct No{
    int num;
    int FB;
    struct No *fesq;
    struct No *fdir;
};

int CalcularBalanceamento(struct No* arv);
struct No* verificarBalanceamento(struct No* arv);

struct No* inserir(struct No * arv, int num);
struct No* remover(struct No* arv, int num);

struct No* rotacionarDireita(struct No*arv);
struct No* rotacionarEsquerda(struct No*arv);

void ordem_central(struct No *arv);
void imprimir(struct No *arv);

#endif
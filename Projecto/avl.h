#ifndef AVL_H
#define AVL_H

// Estruturas da AVL
typedef struct noAvl
{
    int chave;
    // Usuario user;
    struct noAvl *esq;
    struct noAvl *dir;
    int altura;
} NoAvl;
typedef struct AVL
{
    NoAvl *raiz;
    int tamanho;
} AVL;

// Funções da AVL
// Criação
AVL *criarAVL();
NoAvl *criarNoAVL(int valor);

// Auxiliares
int alturaAVL(NoAvl *raiz);
int maximoAVL(int a, int b);
int fatorBalanceamento(NoAvl *raiz);
NoAvl *menorNoAVL(NoAvl *raiz);

// Rotações
NoAvl *rotacaoDireita(NoAvl *y);
NoAvl *rotacaoEsquerda(NoAvl *x);

// Operações
NoAvl *inserirAVL(NoAvl *raiz, int valor);
NoAvl *removerAVL(NoAvl *raiz, int valor);
NoAvl *buscarAVL(NoAvl *raiz, int valor);

// Percursos
void emOrdem(NoAvl *raiz);
void preOrdem(NoAvl *raiz);
void posOrdem(NoAvl *raiz);

// Utilidades
void mostrarAVL(NoAvl *raiz, int nivel);
int contarNos(NoAvl *raiz);
int arvoreVazia(NoAvl *raiz);
void destruirAVL(NoAvl *raiz);

#endif
<h1 align="center"> MPega </h1>

<h2 align="center">  Sistema Inteligente de Partilha de Viagens</h2>

---

## **INTEGRANTES**

- **Briane Vicente** : 2023 - 2111;
- **Delfina Ramos** : 2023 - 0596;
- **Rodolfo Guzman** : 2023 - 0090;

---

## **Sobre o Projeto**

O sistema consiste numa plataforma de intermediação de boleias que permite a publicação e gestão de viagens por parte dos motoristas e a pesquisa e reserva dessas viagens por parte dos passageiros. Diferentemente dos serviços tradicionais de transporte sob demanda, o destino da viagem é previamente definido pelo motorista, cabendo ao passageiro selecionar uma rota já existente que satisfaça as suas necessidades de deslocação. O objetivo é otimizar a ocupação dos veículos, reduzir custos de transporte, diminuir o número de automóveis em circulação e incentivar a mobilidade partilhada.

---

## **Funcionalidades**

O presente sistema possui as seguintes funcionalidades:

- Registar Usuários;
- Registar Vias;
- Iniciar viagem;
- ...;

---

## **Tecnologias**

- Linguagem C;

---

## **Estrutura de Dados**

- Listas Ligadas
- Tabelas Hash
- Árvores AVL
- Grafos
- Filas

---

## **Estrutura do Projecto**

```text
ExameEDII_T2_G13
    ├── Projecto
    │   ├── avl.c
    │   ├── avl.h
    │   ├── executavel
    │   ├── fila.h
    │   ├── grafo.c
    │   ├── grafo.h
    │   ├── hash.c
    │   ├── hash.h
    │   ├── lista.c
    │   ├── lista.h
    │   ├── mainMPega.c
    │   ├── menu.h
    │   └── menus.c
    ├── README.md
    └── TrabalhoFinal_EDII_2026.pdf
```

---

## **Ficheiros**

- usuario.txt;
- rotas.txt;
  -...

### Ainda em fase de discussão, pois pensamos em acrescentar mais um.

---

## **Tipos**

**1 - AVL**

- NoAvl;
- AVL;

**2 - Fila**

- NoFila;
- Fila;

**3 - Grafo**

- Adjacencia;
- Vertice;
- Grafo;

**4 - Hastable Encadeado**
...

**5 - Lista**

- Usuario;
- No;
- Lista;

**6 - Menu**

- ...

## **Métodos**

**1 - AVL**

```bash
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
void posOrdem(NoAvl \*raiz);

// Utilidades
void mostrarAVL(NoAvl *raiz, int nivel);
int contarNos(NoAvl *raiz);
int arvoreVazia(NoAvl *raiz);
void destruirAVL(NoAvl *raiz);
```

**2 - Fila**

```bash
...
```

**3 - Grafo**

```bash
...
```

**4 - Hastable Encadeado**

```bash
void inicializarTabela(Lista t[]);
int funcaoHash(int id);

void inserir_usuario(Lista t[], Usuario u);
No \*buscarUsuario(Lista t[], int id);
int remover(Lista t[], int id);
void imprimirTabela(Lista t[]);

// Funções de controle do sistema (Cadastro, Menus e Login)
void cadastrar_usuario(Lista t[]);
void fazerLogin(Lista t[]);
Usuario \*login(Lista t[], char email[], char senha[]);

// Menus
void menuPassageiro(Usuario u);
void menuAdmin(Usuario u);
void menuCondutor(Usuario u);
void sessao();

// auxiliares
void limparTela();
void aguardarEnter();
```

**5 - Lista**

```bash
void inicializar(Lista *l);
void inserir_Lista(Lista *l, Usuario u);
No *buscar(Lista *l, int id);
int remover_Lista(Lista *l, int id);
void imprimir(Lista *l);
```

**6 - Menu**

```bash
int menuADM();
int menuConduto();
int menuPassageir();
```

## **Como Executar**

Caso já tenha o GitHub instalado e configurado no terminal do VSCode, é só copiar e colar os seguintes códigos no terminal do VSCode:

Para compilar:

```bash
gcc \*.c -Wall -Wextra -Werror -o executavel
```

Para Executar:

```bash
./executavel
```

## **Futuras melhorias**

### Tornar mais inteligente a procura, e criar mais funcionalidades.

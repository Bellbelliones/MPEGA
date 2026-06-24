<h1 align="center"> MPega </h1>

<h2 align="center"> Sistema: MPega – Sistema Inteligente de Partilha de Viagens & Boleia </h2>

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

## **Estrutura do Projecto**

´´md
ExameEDII_T2_G13
├── Projecto
│ │
│ ├── include
│ │ └── mpega.h
│ │
│ │
│ ├── interface
│ │ └── menus.c
│ │
│ │
│ ├── mainDeTeste
│ │ ├── maintest1.c
│ │ ├── maintest2.c
│ │ └── maintest3.c
│ │
│ │
│ ├── src
│ │ ├── avl.c
│ │ ├── grafo.c
│ │ └── hastableDuplo.c
│ │
│ ├── mainMPega.c
│ └── Executavel
│
├── README.md
└── TrabalhoFinal_EDII_2026.pdf
´´

---

## **Ficheiros**

- Biblioteca
- Livro
- Usuario
- Emprestimo

---

## **Atributos**

1. Biblioteca

- listaLivros
- listaUsuarios
- listaEmprestimos

2. Livro

- id
- titulo
- autor
- genero
- disponivel

3. Usuario

- id
- nome
- email
- bi
- nivelAcesso
- ativo

4. Emprestimo

- id
- livro
- usuario
- dataEmprestimo
- dataDevolucao
- devolvido

---

## **Métodos**

1. Biblioteca

- menu()
- adicionarLivro()
- atualizarLivro()
- eliminarLivro()
- listarLivros()
- adicionarUsuario()
- atualizarUsuario()
- bloquearUsuario()
- eliminarUsuario()
- adicionarEmprestimo()
- devolverLivro()
- verificarMulta()
- carregarLivros()
- carregarUsuarios()
- carregarEmprestimos()

2. Livro

- Registar()
- atualizar()
- remover()
- listar()

3. Usuario

- Registar()
- atualizar()
- bloquear()
- remover()

4. Emprestimo

- realizarEmprestimo()
- devolverLivro()
- calcularMulta()

---

## **Ficheiros**

- Livro;
- Usuario;
- Emprestimo;

---

## **Como Executar**

## **Futuras melhorias**

- Adicionar Login Para funcionarios(para ter controle de usuários)

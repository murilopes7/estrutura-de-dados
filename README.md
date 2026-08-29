# 📚 Estrutura de Dados — UFLA

> Repositório destinado ao armazenamento de implementações, rotinas de estudos, exercícios de fixação e trabalhos práticos da disciplina de **Estrutura de Dados** da **Universidade Federal de Lavras (UFLA)**.

---

## 📌 Sobre o Repositório

Este repositório contém os códigos desenvolvidos ao longo do semestre, cobrindo os conceitos fundamentais de estruturas de dados lineares e não lineares, armazenamento em memória e em disco, e análise de eficiência. As implementações priorizam a construção das estruturas "do zero" (sem uso da STL) para fins didáticos.

---

## 🧠 Ementa e Módulos do Curso

O repositório está organizado de acordo com o cronograma oficial da disciplina. Acompanhe o progresso das implementações:

- [ ] **Revisão de Conceitos**
- [ ] **Tipos Abstratos de Dados (TAD)**
- [ ] **Pilhas**
- [ ] **Filas**
- [ ] **Heaps e Torneios**
- [ ] **Listas**
- [ ] **Hash (Tabelas de Espalhamento)**
- [ ] **Árvores Não Balanceadas**
- [ ] **Árvores Binárias Balanceadas (Árvores AVL)**
- [ ] **Árvores Balanceadas (Árvores B)**
- [ ] **Ordenação Externa**

---

## 📂 Estrutura de Diretórios

```text
.
├── 01-pilhas/              # Implementações de Pilhas
├── 02-filas/               # Implementações de Filas encadeadas/vetor
├── 03-heaps-torneios/      # Filas de prioridade, Heaps e estrutura de Torneio
├── 04-listas/              # Listas simplesmente e duplamente encadeadas
├── 05-hash/                # Tratamento de colisões e funções de espalhamento
├── 06-arvores-basicas/     # Árvores binárias de busca (BST) não balanceadas
├── 07-arvores-avl/         # Árvores AVL com rotações
├── 08-arvores-b/           # Árvores B e suas variações
├── 09-ordenacao-externa/   # Algoritmos para arquivos grandes (Intercalação, etc.)
└── README.md
```

⚙️ Como Compilar e Executar

Certifique-se de ter o compilador g++ instalado no seu sistema.

1. Clone o repositório:

   ```bash
   git clone [https://github.com/murilopes7/estrutura-de-dados.git)](https://github.com/murilopes7/estrutura-de-dados.git)
   cd estrutura-de-dados

2. Navegue até a pasta da estrutura desejada e compile o arquivo .cpp:
  ```bash
    g++ -Wall -std=c++17 02-pilhas-filas/fila.cpp -o executavel
  ```

3. Execute a aplicação:
```bash
  ./executavel
 

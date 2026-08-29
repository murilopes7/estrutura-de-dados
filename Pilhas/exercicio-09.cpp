#include <iostream>
#include <limits> // Para utilizar o menor valor possível de um inteiro

using namespace std;

// Definição da Classe Pilha
class Pilha {
private:
  int vetor[10];
  int topo;
  int capacidade;

public:
  // Construtor
  Pilha() {
    capacidade = 10;
    topo = -1; // -1 indica que a pilha está vazia
  }

  bool vazia() const { return topo == -1; }

  bool cheia() const { return topo == capacidade - 1; }

  void empilhar(int x) {
    if (!cheia()) {
      topo++;
      vetor[topo] = x;
    }
  }

  // Retorna true se conseguiu desempilhar e armazena o resultado na variável
  // passada por referência
  bool desempilhar(int &valor) {
    if (vazia()) {
      return false;
    }
    valor = vetor[topo];
    topo--;
    return true;
  }
};

// Método para encontrar e imprimir o maior valor utilizando uma pilha auxiliar
void imprimirMaior(Pilha &principal) {
  if (principal.vazia()) {
    cout << "VAZIA" << endl;
    return;
  }

  Pilha auxiliar;
  int maior = numeric_limits<int>::min();
  int valor;

  // 1. Desempilha da principal para a auxiliar
  while (principal.desempilhar(valor)) {
    if (valor > maior) {
      maior = valor;
    }
    auxiliar.empilhar(valor);
  }

  // 2. Restaura a pilha principal voltando os elementos
  while (auxiliar.desempilhar(valor)) {
    principal.empilhar(valor);
  }

  cout << maior << endl;
}

// Método para esvaziar a pilha imprimindo seus valores
void imprimirTudo(Pilha &principal) {
  if (principal.vazia()) {
    cout << endl;
    return;
  }

  bool primeiro = true;
  int valor;

  // Imprime do topo para a base
  while (principal.desempilhar(valor)) {
    if (!primeiro) {
      cout << " ";
    }
    cout << valor;
    primeiro = false;
  }
  cout << endl;
}

int main() {
  Pilha principal;
  char op;

  // Leitura contínua das operações até EOF ou comando 's'
  while (cin >> op) {
    if (op == 'e') {
      int valor;
      cin >> valor;
      principal.empilhar(valor);

    } else if (op == 'd') {
      int valor;
      if (principal.desempilhar(valor)) {
        cout << valor << endl;
      } else {
        cout << "VAZIA" << endl;
      }

    } else if (op == 'm') {
      imprimirMaior(principal);

    } else if (op == 's') {
      imprimirTudo(principal);
      break; // Encerra o loop e o programa
    }
  }

  return 0;
}

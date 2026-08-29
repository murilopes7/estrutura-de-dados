/* Código base para estrutura de dados Fila
 *
 * by Juliana Galvani Greghi
 *                                nov/2018
 */

#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

class Noh {
  friend class Fila;

private:
  string dado;
  Noh *proximo;

public:
  Noh(string info) {
    dado = info;
    proximo = NULL;
  }

  ~Noh() {}
};

class Fila {
private:
  Noh *inicio;
  Noh *fim;
  int tamanho;

public:
  Fila();
  ~Fila();
  void enfileira(string info);
  string desenfileira();
  bool estaVazia();
};

Fila::Fila() {
  this->inicio = nullptr;
  this->fim = nullptr;
  this->tamanho = 0;
}

Fila::~Fila() {
  while (!estaVazia()) {
    desenfileira();
  }
}

void Fila::enfileira(string info) {
  Noh *NewNode = new Noh(info);
  NewNode->dado = info;
  NewNode->proximo = nullptr;

  if (estaVazia())
    inicio = NewNode;
  else
    fim->proximo = NewNode;

  fim = NewNode;
  tamanho++;
}

string Fila::desenfileira() {
  if (estaVazia())
    return "";

  Noh *temp = inicio;
  string valor = temp->dado;
  inicio = inicio->proximo;

  if (inicio == nullptr)
    fim = nullptr;

  temp->proximo = nullptr;
  delete temp;
  tamanho--;

  return valor;
}

bool Fila::estaVazia() { return tamanho == 0; }

int main() {
  Fila filaNormal;
  Fila filaPrioridade;
  string opcao;
  string nome;

  int numero_prioridade = 0;

  while (cin >> opcao && opcao != "fim") {
    if (opcao == "normal") {
      cin >> nome;
      filaNormal.enfileira(nome);

    }

    else if (opcao == "prioridade") {
      cin >> nome;
      filaPrioridade.enfileira(nome);
    }

    else if (opcao == "atender") {
      if (filaPrioridade.estaVazia() && filaNormal.estaVazia())
        cout << "AGUARDE" << endl;

      else if (numero_prioridade < 3 && !filaPrioridade.estaVazia()) {
        cout << filaPrioridade.desenfileira() << endl;
        numero_prioridade++;
      }

      else if (!filaNormal.estaVazia()) {
        cout << filaNormal.desenfileira() << endl;
        numero_prioridade = 0;
      }

      else
        cout << filaPrioridade.desenfileira() << endl;
    }
  }
}

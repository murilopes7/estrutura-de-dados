#include <cstddef>
#include <iostream>
using namespace std;
typedef int Dado;

class Node {
  friend class Fila;

private:
  Dado mDado;
  Node *mPointerNext;
};

class Fila {
private:
  Node *inicio;
  Node *fim;
  unsigned tamanho;

public:
  Fila() {
    this->inicio = nullptr;
    this->fim = nullptr;
    this->tamanho = 0;
  }

  ~Fila() { limparTudo(); }

  void enqueue(const Dado &valor);
  Dado dequeue();

  bool isEmpty() const { return tamanho == 0; }

  void limparTudo() {
    while (!isEmpty())
      dequeue();
  }

  unsigned obterTamanho() const { return tamanho; }

  void removerElementosDe(Fila &f2) {
    if (this->isEmpty() || f2.isEmpty()) {
      return;
    }

    unsigned tamanhoF1 = this->obterTamanho();
    unsigned tamanhoF2 = f2.obterTamanho();

    for (unsigned i = 0; i < tamanhoF1; i++) {
      Dado elementoF1 = this->dequeue();
      bool encontrado = false;

      for (unsigned j = 0; j < tamanhoF2; j++) {
        Dado elementoF2 = f2.dequeue();

        if (elementoF1 == elementoF2) {
          encontrado = true;
        }

        f2.enqueue(elementoF2);
      }

      if (!encontrado) {
        this->enqueue(elementoF1);
      }
    }
  }

  void imprimir() const {
    Node *atual = inicio;
    bool primeiro = true;
    while (atual != nullptr) {
      if (!primeiro) {
        cout << " ";
      }
      cout << atual->mDado;
      primeiro = false;
      atual = atual->mPointerNext;
    }
    cout << endl;
  }
};

void Fila::enqueue(const Dado &valor) {
  Node *newNode = new Node;

  newNode->mDado = valor;
  newNode->mPointerNext = nullptr;

  if (isEmpty())
    inicio = newNode;
  else
    fim->mPointerNext = newNode;

  fim = newNode;
  tamanho++;
}

Dado Fila::dequeue() {
  if (isEmpty())
    return '\0';

  Node *temp = inicio;
  Dado valor = temp->mDado;

  inicio = inicio->mPointerNext;
  if (inicio == nullptr)
    fim = nullptr;

  delete temp;
  tamanho--;

  return valor;
}

int main() {
  int n1;
  Fila F1;

  Dado valor;
  cin >> n1;
  for (int i = 0; i < n1; i++) {
    cin >> valor;
    F1.enqueue(valor);
  }

  int n2;
  Fila F2;

  cin >> n2;
  for (int i = 0; i < n2; i++) {
    cin >> valor;
    F2.enqueue(valor);
  }

  F1.removerElementosDe(F2);
  F1.imprimir();
  return 0;
}

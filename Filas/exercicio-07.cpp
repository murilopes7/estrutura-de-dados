#include <cstddef>
#include <iostream>
using namespace std;
typedef int Dado;

class Node {
  friend class Fila;

private:
  Dado mDado;
  Node *mPtProx;

public:
  Node(Dado info) {
    this->mDado = info;
    this->mPtProx = nullptr;
  }
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

  ~Fila() {
    while (!isEmpty()) {
      deQueue();
    }
  }

  bool isEmpty() const { return tamanho == 0; }

  Dado deQueue();
  void enQueue(Dado dado);
  unsigned obterTamanho() { return this->tamanho; }

  void printQueue() {
    Node *current = this->inicio;
    while (current != nullptr) {
      cout << current->mDado << " ";
      current = current->mPtProx;
    }
    cout << endl;
  }

  void mesclar(const Fila &f1, const Fila &f2) {
    Node *p1 = f1.inicio;
    Node *p2 = f2.inicio;

    while (p1 != nullptr && p2 != nullptr) {
      if (p1->mDado <= p2->mDado) {
        enQueue(p1->mDado);
        p1 = p1->mPtProx;
      } else {
        enQueue(p2->mDado);
        p2 = p2->mPtProx;
      }
    }

    while (p1 != nullptr) {
      enQueue(p1->mDado);
      p1 = p1->mPtProx;
    }

    while (p2 != nullptr) {
      enQueue(p2->mDado);
      p2 = p2->mPtProx;
    }
  }
};

void Fila::enQueue(Dado dado) {
  Node *newNode = new Node(dado);

  if (isEmpty())
    inicio = newNode;
  else
    fim->mPtProx = newNode;

  fim = newNode;
  tamanho++;
}

Dado Fila::deQueue() {
  if (isEmpty())
    return 0;

  Node *temp = inicio;
  Dado valor = temp->mDado;

  inicio = inicio->mPtProx;

  if (inicio == nullptr)
    fim = nullptr;

  temp->mPtProx = nullptr;
  delete temp;

  tamanho--;

  return valor;
}

int main() {
  Fila a;
  Fila b;

  char op;
  char idFila;

  Dado m;
  while (cin >> op && op != 't') {
    if (op == 'i') {
      cin >> idFila;
      cin >> m;
      if (idFila == 'a')
        a.enQueue(m);

      else if (idFila == 'b')
        b.enQueue(m);
    }

    else if (op == 'e') {
      cin >> idFila;
      if (idFila == 'a')
        a.printQueue();
      else
        b.printQueue();
    }

    else if (op == 'm') {
      Fila ordem;
      ordem.mesclar(a, b);
      ordem.printQueue();
    }
  }
}

#include <iostream>
using namespace std;

typedef int Dado;

class Node {
  friend class Fila;

private:
  Dado mDado;
  Node *proximo;
};

class Fila {
private:
  unsigned tamanho;
  Node *inicio;
  Node *fim;

public:
  Fila() {
    this->inicio = nullptr;
    this->fim = nullptr;
    this->tamanho = 0;
  }

  ~Fila() { limparTudo(); }

  void limparTudo() {
    while (!isEmpty())
      dequeue();
  }

  bool isEmpty() const { return tamanho == 0; }

  Dado obterInicio() { return this->inicio->mDado; }

  void enqueue(const Dado &dado) {
    Node *newNode = new Node;
    newNode->mDado = dado;
    newNode->proximo = nullptr;

    if (isEmpty())
      inicio = newNode;
    else
      fim->proximo = newNode;
    fim = newNode;
    tamanho++;
  }

  Dado dequeue() {
    if (isEmpty())
      return 0;

    Node *temp = inicio;
    Dado valor = temp->mDado;
    inicio = inicio->proximo;

    if (inicio == nullptr)
      fim = nullptr;

    delete temp;
    tamanho--;

    return valor;
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
      atual = atual->proximo;
    }
    cout << endl;
  }
};

int main() {
  int n1;
  cin >> n1;
  Fila F1;
  Dado valores;
  for (int i = 0; i < n1; i++) {
    cin >> valores;
    F1.enqueue(valores);
  }

  int n2;
  cin >> n2;
  Fila F2;
  for (int i = 0; i < n2; i++) {
    cin >> valores;
    F2.enqueue(valores);
  }

  Fila aux;
  Dado ultimoNumero = -1;
  while (!F1.isEmpty() && !F2.isEmpty()) {
    if (F1.obterInicio() <= F2.obterInicio()) {
      Dado valor = F1.dequeue();
      if (aux.isEmpty() || valor != ultimoNumero) {
        aux.enqueue(valor);
        ultimoNumero = valor;
      }
    }

    else {
      Dado valor = F2.dequeue();
      if (aux.isEmpty() || valor != ultimoNumero) {
        aux.enqueue(valor);
        ultimoNumero = valor;
      }
    }
  }

  while (!F1.isEmpty()) {
    Dado valor = F1.dequeue();
    if (aux.isEmpty() || valor != ultimoNumero) {
      aux.enqueue(valor);
      ultimoNumero = valor;
    }
  }

  while (!F2.isEmpty()) {
    Dado valor = F2.dequeue();
    if (aux.isEmpty() || valor != ultimoNumero) {
      aux.enqueue(valor);
      ultimoNumero = valor;
    }
  }

  aux.imprimir();
  return 0;
}

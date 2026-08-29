#include <iostream>
using namespace std;

typedef string Dado;

class Node {
  friend class Fila;

private:
  Dado mDado;
  Node *proximo;

public:
  Node(Dado dado) {
    this->mDado = dado;
    proximo = nullptr;
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

  ~Fila() { limparTudo(); }

  void limparTudo() {
    while (!isEmpty()) {
      deQueue();
    }
  }

  bool isEmpty() { return this->tamanho == 0; }
  Dado deQueue();
  void enQueue(const Dado &dado);
  unsigned obterTamanho() { return this->tamanho; }
};

void Fila::enQueue(const Dado &dado) {
  Node *newNode = new Node(dado);
  if (isEmpty())
    inicio = newNode;
  else
    fim->proximo = newNode;

  fim = newNode;
  tamanho++;
}

Dado Fila::deQueue() {
  if (isEmpty())
    return "";

  Node *temp = inicio;
  Dado valor = temp->mDado;
  inicio = inicio->proximo;

  if (inicio == nullptr)
    fim = nullptr;

  temp->proximo = nullptr;
  delete temp;
  tamanho--;

  return valor;
}

int main() {
  Fila fila;
  int N;
  cin >> N;

  Dado inicio = "1";
  fila.enQueue(inicio);

  for (int i = 0; i < N; i++) {
    Dado atual = fila.deQueue();
    cout << atual << " ";

    if (i + fila.obterTamanho() < N)
      fila.enQueue(atual + "0");

    if (i + fila.obterTamanho() < N)
      fila.enQueue(atual + "1");
  }

  return 0;
}

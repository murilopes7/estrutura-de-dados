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

  int espiaInicio() {
    if (isEmpty())
      return -1;
    return inicio->mDado;
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
  Fila fila;
  int N;
  cin >> N;
  int *vetor = new int[N];

  for (int i = 0; i < N; i++) {
    cin >> vetor[i];
  }

  int k;
  cin >> k;

  for (int i = 0; i < N; i++) {
    if (vetor[i] < 0)
      fila.enQueue(i);

    if (i >= k - 1) {
      int inicioJanela = i - k + 1;

      while (!fila.isEmpty() && fila.espiaInicio() < inicioJanela)
        fila.deQueue();

      if (!fila.isEmpty())
        cout << vetor[fila.espiaInicio()] << " ";

      else
        cout << "inexistente ";
    }
  }

  cout << endl;
  delete[] vetor;
  return 0;
}

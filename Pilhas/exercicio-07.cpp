#include <iostream>
using namespace std;

typedef int Dado;

class Noh {
  friend class Pilha;

private:
  Dado mNumber;
  Noh *mPtProx;
};

class Pilha {
private:
  Noh *mPtTop;
  unsigned mSize;

public:
  Pilha() {
    this->mPtTop = nullptr;
    this->mSize = 0;
  }

  ~Pilha() { cleanStack(); }

  bool isEmpty() const { return mSize == 0; }
  void cleanStack() {
    while (!isEmpty())
      Desempilhar();
  }

  void Empilhar(const Dado number);
  Dado Desempilhar();

  void Inverter(Pilha *&pilha);
  void depura();
};

void Pilha::Empilhar(const Dado n) {
  Noh *newNoh = new Noh;
  newNoh->mNumber = n;
  newNoh->mPtProx = mPtTop;
  mPtTop = newNoh;

  mSize++;
}

Dado Pilha::Desempilhar() {
  if (isEmpty())
    return '\0';

  Noh *temp = mPtTop;
  Dado valor = temp->mNumber;
  mPtTop = temp->mPtProx;
  delete temp;
  mSize--;
  return valor;
}

void Pilha::Inverter(Pilha *&pilha) {
  Pilha P2;

  while (!pilha->isEmpty()) {
    P2.Empilhar(pilha->Desempilhar());
  }

  while (!P2.isEmpty()) {
    pilha->Empilhar(P2.Desempilhar());
  }
}

void Pilha::depura() {
  Noh *current = mPtTop;

  if (current == nullptr) {
    cout << "Stack is empty" << endl;
    return;
  }

  while (current != nullptr) {
    cout << current->mNumber << " ";
    current = current->mPtProx;
  }
  cout << endl;
}

int main() {

  int numero;
  Pilha *P1 = new Pilha();

  cin >> numero;

  Dado valor;
  for (int i = 0; i < numero; i++) {
    cin >> valor;
    P1->Empilhar(valor);
  }

  P1->Inverter(P1);

  P1->depura();

  delete P1;
  return 0;
}

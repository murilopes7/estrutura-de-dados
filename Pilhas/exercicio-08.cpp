#include <cstddef>
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

  Dado leastValue();
  void Inverter(Pilha *&pilha);
  void imprimirTudo();
};

void Pilha::Empilhar(const Dado n) {
  Noh *newNoh = new Noh;
  newNoh->mNumber = n;
  newNoh->mPtProx = mPtTop;
  mPtTop = newNoh;

  mSize++;
}

Dado Pilha::Desempilhar() {
  if (isEmpty()) {
    cout << "VAZIA" << endl;
    return '\0';
  }

  Noh *temp = mPtTop;
  Dado valor = temp->mNumber;
  mPtTop = temp->mPtProx;
  delete temp;
  mSize--;
  return valor;
}

Dado Pilha::leastValue() {
  if (isEmpty()) {
    return -1;
  }

  Pilha aux;
  Dado menor = mPtTop->mNumber;

  while (!this->isEmpty()) {
    Dado atual = this->Desempilhar();

    if (atual < menor)
      menor = atual;

    aux.Empilhar(atual);
  }

  while (!aux.isEmpty()) {
    this->Empilhar(aux.Desempilhar());
  }

  return menor;
}

// Imprime todos os valores do topo ao fundo
void Pilha::imprimirTudo() {
  Noh *current = mPtTop;
  while (current != nullptr) {
    cout << current->mNumber << " ";
    current = current->mPtProx;
  }
  cout << endl;
}

int main() {
  Pilha minhaPilha;
  char operacao;
  Dado valor;

  // Loop de comandos baseado nas entradas (e, d, m, s)
  while (cin >> operacao) {
    if (operacao == 'e') {
      cin >> valor;
      minhaPilha.Empilhar(valor);
    } else if (operacao == 'd') {
      if (minhaPilha.isEmpty()) {
        cout << "VAZIA" << endl;
      } else {
        cout << minhaPilha.Desempilhar() << endl;
      }
    } else if (operacao == 'm') {
      if (minhaPilha.isEmpty()) {
        cout << "VAZIA" << endl;
      } else {
        cout << minhaPilha.leastValue() << endl;
      }
    } else if (operacao == 's') {
      minhaPilha.imprimirTudo();
      break;
    }
  }

  return 0;
}

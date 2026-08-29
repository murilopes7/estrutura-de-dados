#include <iostream>
using namespace std;
typedef char Dado;

class Noh {
  friend class Pilha;

private:
  Dado mDado;
  Noh *mPtProx;
};

class Pilha {
private:
  Noh *mPtTopo;
  unsigned mTamanho;

public:
  Pilha() {
    this->mPtTopo = nullptr;
    this->mTamanho = 0;
  }

  ~Pilha() { LimparTudo(); }

  void Empilhar(const Dado &d) {
    Noh *novoNoh = new Noh;
    novoNoh->mDado = d;
    novoNoh->mPtProx = mPtTopo;
    mPtTopo = novoNoh;
    mTamanho++;
  }

  Dado Desempilhar() {
    if (Vazia())
      return '\0'; // Retorna nulo se vazia
    Noh *temp = mPtTopo;
    Dado valor = temp->mDado;
    mPtTopo = mPtTopo->mPtProx;
    delete temp;
    mTamanho--;
    return valor;
  }

  void LimparTudo() {
    while (!Vazia())
      Desempilhar();
  }

  bool Vazia() const { return mTamanho == 0; }
  unsigned Tamanho() const { return mTamanho; }
};

int main() {
  Pilha pilhaA;
  Pilha pilhaC;

  char letra;
  bool reconhecido = true;
  int estado = 1;

  while (cin >> letra && letra != 'X') {
    if (!reconhecido) {
      break;
    }

    if (estado == 1) {
      if (letra == 'A') {
        pilhaA.Empilhar('A');
      } else if (letra == 'B') {
        if (pilhaA.Vazia()) {
          reconhecido = false;
          break;
        } else {
          estado = 2;
        }
      } else {
        reconhecido = false;
        break;
      }
    }

    else if (estado == 2) {
      if (letra == 'C') {
        pilhaC.Empilhar('C');

        if (pilhaC.Tamanho() == 2) {

          if (pilhaA.Vazia()) {
            reconhecido = false;
            break;
          } else {
            pilhaC.Desempilhar();
            pilhaC.Desempilhar();
            pilhaA.Desempilhar();
          }
        }
      } else {
        reconhecido = false;
        break;
      }
    }
  }

  if (reconhecido && estado == 2 && pilhaA.Vazia() && pilhaC.Vazia()) {
    cout << "sim" << endl;
  } else {
    cout << "nao" << endl;
  }

  cout << pilhaA.Tamanho() << endl;
  cout << pilhaC.Tamanho() << endl;

  return 0;
}

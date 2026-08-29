#include <cstddef>
#include <iostream>

typedef int Dado;

class Noh {
  friend class Pilha;

private:
  Dado mDado; // poderia ser outro tipo de variável
  Noh *mPtProx;
};

class Pilha {
public:
  // Constrói pilha vazia.
  Pilha();
  // Destrutor que desaloca memória.
  ~Pilha();
  // Retira e retorna o valor que estiver no mPtTopo da pilha.
  // Escreve uma mensagem de erro se não for possível desempilhar.
  Dado Desempilhar(); // retorna o mPtTopo da Pilha
  // Insere um valor na pilha.
  void Empilhar(const Dado &d);
  // Apagar todos os dados da pilha.
  void LimparTudo();
  // Informa quantos valores existem na pilha.
  unsigned Tamanho() { return mTamanho; }
  // Retorna o valor que está no mPtTopo sem desempilhar.
  Dado Topo() const;
  // Informa se a pilha está Vazia.
  bool Vazia() const;

private:
  Noh *mPtTopo;
  unsigned mTamanho;
};

using namespace std;

Pilha::Pilha() {
  this->mPtTopo = nullptr;
  this->mTamanho = 0;
}

Pilha::~Pilha() { LimparTudo(); }

Dado Pilha::Desempilhar() {
  if (Vazia()) {
    cerr << "Erro: Não foi possivel desempilhar. A pilha esta vazia!" << endl;
    return -1; // Retorna um valor simbólico, pois a função exige um retorno
  }

  Noh *temp = mPtTopo;
  Dado valor = temp->mDado;

  mPtTopo = mPtTopo->mPtProx;

  delete temp;

  mTamanho--;

  return valor;
}

void Pilha::Empilhar(const Dado &d) {
  Noh *newNoh = new Noh;
  newNoh->mDado = d;
  newNoh->mPtProx = mPtTopo;

  mPtTopo = newNoh;
  mTamanho++;
}

void Pilha::LimparTudo() {
  while (!Vazia()) {
    Desempilhar();
  }
}

Dado Pilha::Topo() const {
  if (Vazia()) {
    cerr << "Erro: A pilha esta vazia!" << endl;
    return -1;
  }
  return mPtTopo->mDado;
}

bool Pilha::Vazia() const { return mTamanho == 0; }

int main() {
  Pilha pilha;
  Dado valor;
  char comando;
  do {
    cin >> comando;
    switch (comando) {
    case 'i': // inserir
      cin >> valor;
      pilha.Empilhar(valor);
      break;
    case 'r': // remover
      cout << pilha.Desempilhar() << endl;
      break;
    case 'l': // limpar tudo
      pilha.LimparTudo();
      break;
    case 't': // consultar tamanho
      cout << pilha.Tamanho() << endl;
      break;
    case 'e': // espiar
      cout << pilha.Topo() << endl;
      break;
    case 'f': // finalizar
      // checado no do-while
      break;
    default:
      cerr << "comando inválido\n";
    }
  } while (comando != 'f'); // finalizar execução
  while (not pilha.Vazia()) {
    cout << pilha.Desempilhar() << ' ';
  }
  cout << endl;
  return 0;
}

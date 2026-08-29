#include <iostream>

typedef int Dado;

class Noh {
  friend class Fila;

private:
  Dado mDado;
  Noh *mPtProx;
};

class Fila {
public:
  // Constroi uma fila vazia.
  Fila();
  // Desaloca memória de todos os nós da fila.
  ~Fila();
  // Remove e retorna o primeiro item da fila.
  Dado Remover();
  // Insere um item no final da fila.
  void Inserir(const Dado &d);
  // Retorna o primeiro item da fila sem remover.
  Dado Proximo() const;
  // Remove todos os itens da fila.
  void LimparTudo();
  // Consulta a quantidade de itens na fila.
  unsigned Tamanho() const { return mTamanho; }
  // Consulta se a fila está vazia.
  bool Vazia() const;

private:
  Noh *mPrimeiro;
  Noh *mUltimo;
  unsigned mTamanho;
};

using namespace std;

Fila::Fila() {
  mPrimeiro = nullptr;
  mUltimo = nullptr;
  mTamanho = 0;
}

Fila::~Fila() { LimparTudo(); }

void Fila::Inserir(const Dado &d) {
  Noh *novo = new Noh;
  novo->mDado = d;
  novo->mPtProx = nullptr;

  if (Vazia()) {
    mPrimeiro = novo;
  } else {
    mUltimo->mPtProx = novo;
  }

  mUltimo = novo;
  mTamanho++;
}

Dado Fila::Remover() {
  if (Vazia()) {
    cerr << "Erro: Fila vazia!" << endl;
    return Dado();
  }

  Noh *temp = mPrimeiro;
  Dado valor = temp->mDado;

  mPrimeiro = mPrimeiro->mPtProx;

  if (mPrimeiro == nullptr) {
    mUltimo = nullptr;
  }

  temp->mPtProx = nullptr; // Desconecta o nó antes de deletar
  delete temp;
  mTamanho--;

  return valor;
}

Dado Fila::Proximo() const {
  if (Vazia()) {
    cerr << "Erro: Fila vazia!" << endl;
    return Dado();
  }
  return mPrimeiro->mDado;
}

void Fila::LimparTudo() {
  while (not Vazia()) {
    Remover();
  }
}

bool Fila::Vazia() const { return mTamanho == 0; }

int main() {
  Fila fila;
  Dado valor;
  char comando;
  do {
    cin >> comando;
    switch (comando) {
    case 'i': // inserir
      cin >> valor;
      fila.Inserir(valor);
      break;
    case 'r': // remover
      cout << fila.Remover() << endl;
      break;
    case 'l': // limpar tudo
      fila.LimparTudo();
      break;
    case 't': // escrever tamanho
      cout << fila.Tamanho() << endl;
      break;
    case 'e': // espiar proximo
      cout << fila.Proximo() << endl;
      break;
    case 'f': // finalizar
      // vai verificar adiante
      break;
    default:
      cerr << "comando inválido\n";
    }
  } while (comando != 'f'); // finalizar execução
  while (not fila.Vazia()) {
    cout << fila.Remover() << ' ';
  }
  cout << endl;
  return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Noh {
  friend class Fila;

private:
  string placa;
  Noh *proximo;

public:
  Noh(string p) {
    placa = p;
    proximo = nullptr;
  }
  ~Noh() {}
};

class Fila {
private:
  Noh *inicio;
  Noh *fim;
  int tamanho;

public:
  Fila();
  ~Fila();
  void enfileira(string p);
  string desenfileira();
  bool estaVazia();
  int getTamanho();
  void retirarCarro(string placaAlvo);
  void imprimir();
};

Fila::Fila() {
  inicio = nullptr;
  fim = nullptr;
  tamanho = 0;
}

Fila::~Fila() {
  while (!estaVazia()) {
    desenfileira();
  }
}

bool Fila::estaVazia() { return tamanho == 0; }

int Fila::getTamanho() { return tamanho; }

void Fila::enfileira(string p) {
  Noh *novo = new Noh(p);

  if (estaVazia())
    inicio = novo;
  else
    fim->proximo = novo;

  fim = novo;
  tamanho++;
}

string Fila::desenfileira() {
  if (estaVazia())
    return "";

  Noh *temp = inicio;
  string valor = temp->placa;
  inicio = inicio->proximo;

  if (inicio == nullptr)
    fim = nullptr;

  temp->proximo = nullptr;
  delete temp;
  tamanho--;

  return valor;
}

void Fila::imprimir() {
  Noh *atual = inicio;
  while (atual != nullptr) {
    cout << atual->placa << endl;
    atual = atual->proximo;
  }
}

void Fila::retirarCarro(string placaAlvo) {
  if (estaVazia()) {
    cout << "NAO ENCONTRADO" << endl;
    return;
  }

  Fila aux;
  bool encontrado = false;
  int contadorRemovidos = 0;
  int totalOriginal = tamanho;

  // Desenfileira da frente da fila principal até encontrar o carro alvo
  for (int i = 0; i < totalOriginal; i++) {
    string carroAtual = desenfileira();
    contadorRemovidos++;

    if (carroAtual == placaAlvo) {
      encontrado = true;
      break; // Encontrou o carro; ele é removido definitivamente
    } else {
      aux.enfileira(carroAtual); // Move temporariamente para a rua paralela
    }
  }

  // Se o carro não foi encontrado na fila
  if (!encontrado) {
    // Restaura os carros da rua paralela de volta para a fila original
    while (!aux.estaVazia()) {
      enfileira(aux.desenfileira());
    }
    cout << "NAO ENCONTRADO" << endl;
    return;
  }

  // Recoloca os carros da rua paralela no final da fila principal
  while (!aux.estaVazia()) {
    enfileira(aux.desenfileira());
  }

  // Imprime a quantidade de carros movimentados e a nova configuração
  cout << contadorRemovidos << endl;
  imprimir();
}

int main() {
  Fila estacionamento;
  char operacao;
  string placa;

  while (cin >> operacao && operacao != 'S') {
    if (operacao == 'E') {
      cin >> placa;
      estacionamento.enfileira(placa);
    } else if (operacao == 'D') {
      cin >> placa;
      estacionamento.retirarCarro(placa);
    }
  }

  return 0;
}

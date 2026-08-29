#include <iostream>

using namespace std;

class FilaCircular {
private:
  int *dados;
  int capacidade;
  int tamanho;
  int inicio;
  int fim;

public:
  FilaCircular(int cap) {
    capacidade = cap;
    dados = new int[capacidade];
    tamanho = 0;
    inicio = 0;
    fim = -1;
  }

  ~FilaCircular() { delete[] dados; }

  void enfileirar(int valor) {
    if (tamanho == capacidade) {
      return;
    }

    if (tamanho == 0) {
      inicio = 0;
      fim = 0;
    } else {
      fim = (fim + 1) % capacidade;
    }

    dados[fim] = valor;
    tamanho++;
  }

  void desenfileirar() {
    if (tamanho == 0) {
      return; // Fila vazia
    }

    cout << dados[inicio] << endl;
    inicio = (inicio + 1) % capacidade;
    tamanho--;

    if (tamanho == 0) {
      inicio = 0;
      fim = -1;
    }
  }

  void imprimirInformacoes() {
    cout << "tamanho=" << tamanho << " capacidade=" << capacidade
         << " inicio=" << inicio << " fim=" << (tamanho == 0 ? -1 : fim)
         << endl;

    for (int i = 0; i < tamanho; i++) {
      int idx = (inicio + i) % capacidade;
      cout << dados[idx] << (i == tamanho - 1 ? "" : " ");
    }
    cout << endl;
  }
};

int main() {
  int capacidade;
  if (!(cin >> capacidade))
    return 0;

  FilaCircular fila(capacidade);
  char comando;

  while (cin >> comando && comando != 't') {
    if (comando == 'e') {
      int valor;
      cin >> valor;
      fila.enfileirar(valor);
    } else if (comando == 'd') {
      fila.desenfileirar();
    } else if (comando == 'i') {
      fila.imprimirInformacoes();
    }
  }

  return 0;
}

#include <iostream>

using namespace std;

typedef int Dado;

class pilhav {
private:
    int capacidade;
    Dado *dados;
    int tamanho;
    int posTopo;

public:
    pilhav(int cap = 100) {
        capacidade = cap;
        dados = new Dado[capacidade];
        tamanho = 0;
        posTopo = -1;
    }

    ~pilhav() {
        delete[] dados;
    }

    void empilha(Dado valor);
    Dado desempilha();
    Dado espia();

    void sortPilha();
    void imprime();
};


void pilhav::empilha(Dado valor) {
    posTopo++;
    dados[posTopo] = valor;
    tamanho++;
}


Dado pilhav::desempilha() {
    tamanho--;
    return dados[posTopo--];
}


Dado pilhav::espia() {
    return dados[posTopo];
}


void pilhav::sortPilha() {
    pilhav aux(capacidade);

    while (tamanho > 0) {

        Dado temp = desempilha();
        while (aux.tamanho > 0 && aux.espia() > temp) {
            empilha(aux.desempilha());
        }

        aux.empilha(temp);
    }

    while (aux.tamanho > 0) {
        empilha(aux.desempilha());
    }
}


void pilhav::imprime() {
    while (tamanho > 0) {
        cout << desempilha() << " ";
    }

    cout << endl;
}


int main() {
    int numero;
    cin >> numero;

    pilhav pilha(numero);

    for (int i = 0; i < numero; i++) {
        Dado dado;
        cin >> dado;

        pilha.empilha(dado);
    }

    pilha.sortPilha();

    pilha.imprime();

    return 0;
}
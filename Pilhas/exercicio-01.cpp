#include <iostream>

using namespace std;

typedef int Dado;

class pilhav
{
    private:
        int capacidade;
        Dado *dados;
        int tamanho;
        int posTopo;

    public:
        pilhav(int cap = 100){
            capacidade = cap;
            dados = new Dado[capacidade];
            tamanho = 0;
            posTopo = -1;
        }

        ~pilhav(){
            delete[] dados;
        }

        void empilha(Dado valor);
        Dado desempilha();
        Dado espia();
        void depura();
        void info();
};

void pilhav::empilha(Dado valor){
    posTopo++;
    dados[posTopo] = valor;
    tamanho++;
}

Dado pilhav::desempilha(){
    tamanho--;
    return dados[posTopo--];
}

Dado pilhav::espia(){
    return dados[posTopo];
}

void pilhav::depura(){
    for(int i = 0; i <= posTopo; ++i){
        cout << dados[i] << " ";
    }

    cout << endl;
}

void pilhav::info(){
    cout << tamanho << " " << posTopo << endl;
}

int main(){
    pilhav pilha(20);

    Dado dado;

    for (int i = 0; i < 5; i++){
        cin >> dado;
        pilha.empilha(dado);
    }

    //Desempilhamento de 3 valores e impressão destes
    cout << pilha.desempilha() << " " <<  pilha.desempilha() << " " << pilha.desempilha() << endl;

    for (int i = 0; i < 4; i++){
        cin >> dado;
        pilha.empilha(dado);
    }

    //Desempilhamento de 3 valores e impressão destes
    cout << pilha.desempilha() << " " <<  pilha.desempilha() << " " << pilha.desempilha() << endl;

    cout << pilha.espia() << endl;

    pilha.depura();
    pilha.info();
    return 0;
}
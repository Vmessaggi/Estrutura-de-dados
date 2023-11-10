#include <iostream>

using namespace std;

double somaVetor(const double vetor[], int x) {
    if (x == 0) {
        return 0.0;
    }
    else {
        return vetor[x - 1] + somaVetor(vetor, x - 1);
    }
}

int main(){
    int x;
    double somar;
    cout<<"Digite a quantidade de iten no vetor: "<<endl;
    cin>>x;
    if(x <= 0){
        cout << "Tamanho inválido. Encerrando o programa." <<endl;
        return 1;
    }
    double vetor[x];
    for(int i=0;i<x;i++){
        cout<<"Digite o valor da posição "<<i<<": "<<endl;
        cin>>vetor[i];
    }
    somar=somaVetor(vetor,x);
    cout<<"A soma de todos os itens do vetor: "<<somar<<endl;
    return 0;
}
#include <iostream>

using namespace std;

int somatorio(int n){
    if(n == 1){
        return 1;
    }else{
        return n+somatorio(n-1);
    }
}
int main(){
    int n, soma;
    cout<<"Digite um numero para saber o somatorio de 1 ate ele:"<<endl;
    cin>>n;
    soma = somatorio(n);
    cout<<"O valor do somatorio e de: "<<soma<<"."<<endl;
}
#include <iostream>

using namespace std;

int elevado(int x,int n){
    if(n == 0){
        return 1;
    }else if(n == 1){
        return x;
    }else{
        return x*elevado(x,n-1);
    }
}
int main(){
    int x, n, exponencial;
    cout<<"Digite o valor de X: "<<endl;
    cin>>x;
    cout<<"Digite o valor de n: "<<endl;
    cin>>n;
    exponencial = elevado(x,n);
    cout<<"O valor de X^n: "<<exponencial<<"."<<endl;
}
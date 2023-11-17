#include <iostream>

using namespace std;

class Mult_Russa{
    public:
        int multi_russa(int num1,int num2);
};

int Mult_Russa::multi_russa(int a, int b){
    if(a == 0 || b == 0){
        return 0;
    }else if(a % 2 == 0){
        return multi_russa(a/2,b*2);
    }else{
        return b + multi_russa(a/2,b*2);
    }
}

int main(){
    Mult_Russa multiplicacao;
    int a, b;
    cout << "Digite o valor A:" << endl;
    cin >> a;
    cout << "Digite o valor B:" << endl;
    cin >> b;
    cout << "Resultado: " << multiplicacao.multi_russa(a,b) << endl;
}
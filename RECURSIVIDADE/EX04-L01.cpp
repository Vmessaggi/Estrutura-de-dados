#include <iostream>
#include <locale>

using namespace std;

class multiplicacao{
    public:
        int Mult_Rec(int num1, int num2);
};

int multiplicacao::Mult_Rec(int x, int y){
    if(x == 0 || y == 0){
        return 0;
    }
    if(y > 1){
        return (x + Mult_Rec(x, y-1));
    }else{
        return x;
    }
}

int main(){
    setlocale (LC_ALL,"");
    multiplicacao multiplication;
    int x, y;
    cout << "Insira o valor de x:" << endl;
    cin >> x;
    cout << "Insira o valor de y:" << endl;
    cin >> y;
    cout << "Sua multiplicação resulta em: " << multiplication.Mult_Rec(x, y);
}
#include <iostream>
//contida no ex8
using namespace std;

class Padovan{
    public:
        int padovan(int num);
};

int Padovan::padovan(int n){
    if(n <= 2){
        return 1;
    }
    if(n > 2){
        return padovan(n-2) + padovan(n-3);
    }
}

int main(){
    Padovan nesimo;
    int n;
    cout << "Digite o valor N:" << endl;
    cin >> n;
    cout << "Padovan: " << nesimo.padovan(n) << endl;
}
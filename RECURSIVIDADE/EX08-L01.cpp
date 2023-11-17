#include <iostream>

using namespace std;

class Tribonacci{
    public:
        int tribonacci(int num);
        int padovan(int num);
};

int Tribonacci::tribonacci(int n){
    if(n >= 0 && n < 2){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    if(n > 2){
        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
}

int Tribonacci::padovan(int n){
    if(n <= 2){
        return 1;
    }
    if(n > 2){
        return padovan(n-2) + padovan(n-3);
    }
}

int main(){
    Tribonacci seq;
    int n;
    cout << "Digite o valor de n:" << endl;
    cin >> n;
    cout << "Tribonacci: " << seq.tribonacci(n) << endl;
    cout << "Padovan: " << seq.padovan(n) << endl;
}
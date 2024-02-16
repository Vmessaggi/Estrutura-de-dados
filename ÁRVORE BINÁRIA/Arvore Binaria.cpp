#include <iostream>
#include <stdlib.h>
#include <locale.h>
using namespace std;

class No {
private:
    No *esq, *dir;
    int chave;
public:
    No(int chave) {
        this->chave = chave;
        esq = 0;
        dir = 0;
    }
    int getChave() {
        return chave;
    }
    void setChave(int chave) {
        this->chave = chave;
    }
    No *getEsq() {
        return esq;
    }
    No *getDir() {
        return dir;
    }
    void setEsq(No *no) {
        esq = no;
    }
    void setDir(No *no) {
        dir = no;
    }
};

class Arvore {
private:
    No *raiz;
public:
    Arvore() {
        raiz = 0;
    }
    void inserir(int chave) {
        if (raiz == 0) {
            raiz = new No(chave);
        } else {
            inserirAux(raiz, chave);
        }
    }
    void inserirAux(No *no, int chave) {
        if (chave < no->getChave()) {
            if (no->getEsq() == 0) {
                No *novo_no = new No(chave);
                no->setEsq(novo_no);
            } else {
                inserirAux(no->getEsq(), chave);
            }
        } else if (chave > no->getChave()) {
            if (no->getDir() == 0) {
                No *novo_no = new No(chave);
                no->setDir(novo_no);
            } else {
                inserirAux(no->getDir(), chave);
            }
        } else if (chave == no->getChave()) {
            cout << "Numero ja existe..." << endl;
        }
    }
    No *getRaiz() {
        return raiz;
    }
    void preOrdem(No *no) {
        if (no != 0) {
            cout << no->getChave() << " | ";
            preOrdem(no->getEsq());
            preOrdem(no->getDir());
        }
    }
    void emOrdem(No *no) {
        if (no != 0) {
            emOrdem(no->getEsq());
            cout << no->getChave() << " | ";
            emOrdem(no->getDir());
        }
    }
    void posOrdem(No *no) {
        if (no != 0) {
            posOrdem(no->getEsq());
            posOrdem(no->getDir());
            cout << no->getChave() << " | ";
        }
    }
    void remover(int chave) {
        removerAux(raiz, chave);
    }
    No* removerAux(No *no, int chave) {
        if (no == nullptr) return no;
        if (chave < no->getChave()) {
            no->setEsq(removerAux(no->getEsq(), chave));
        } else if (chave > no->getChave()) {
            no->setDir(removerAux(no->getDir(), chave));
        } else {
            if (no->getEsq() == nullptr) {
                No *temp = no->getDir();
                delete no;
                return temp;
            } else if (no->getDir() == nullptr) {
                No *temp = no->getEsq();
                delete no;
                return temp;
            }
            No *temp = minimoValorNo(no->getDir());
            no->setChave(temp->getChave());
            no->setDir(removerAux(no->getDir(), temp->getChave()));
        }
        return no;
    }
    No* minimoValorNo(No *no) {
        No* atual = no;
        while (atual->getEsq() != nullptr) {
            atual = atual->getEsq();
        }
        return atual;
    }
};

int main() {
    setlocale(LC_ALL,"Portuguese");
    Arvore arbin;
    int opcao;
    int item;
    cout << "Gerador de arvore binaria" << endl;
    do {
        cout << "1 - Inserir valor" << endl;
        cout << "2 - Remover valor" << endl;
        cout << "3 - Imprimir percursos" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;
        switch(opcao) {
            case 1:
                system("clear");
                cout << "Digite o valor:" << endl;
                cin >> item;
                arbin.inserir(item);
                cout << "Valor inserido: " << item << endl;
                break;
            case 2:
                system("clear");
                cout << "Digite o valor a ser removido:" << endl;
                cin >> item;
                arbin.remover(item);
                cout << "Valor removido: " << item << endl;
                break;
            case 3:
                system("clear");
                cout << "Pré-ordem: ";
                arbin.preOrdem(arbin.getRaiz());
                cout << endl;
                cout << "Em-ordem: ";
                arbin.emOrdem(arbin.getRaiz());
                cout << endl;
                cout << "Pós-ordem: ";
                arbin.posOrdem(arbin.getRaiz());
                cout << endl;
                break;
            case 0:
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while(opcao != 0);
    return 0;
}

#include <iostream>
#include <string>
#include <locale>

using namespace std;

class GrafoNode{
    public:
        GrafoNode(){
            prox = nullptr;
        }
        GrafoNode(string estado, GrafoNode *ptr = nullptr){
            nome = estado; prox = ptr;
        }
        string nome;
        GrafoNode *prox;
};

class GrafoList{
    public:
        GrafoList(){
            topo = resto = nullptr;
        }
        ~GrafoList();
        void addToGrafo(string);
        int countFront() const;
        void printAll() const;
    private:
        GrafoNode *topo, *resto;    
};

GrafoList::~GrafoList(){
    //Método destrutor.
    while(topo != nullptr){
        GrafoNode *tmp = topo;
        topo = topo->prox;
       delete tmp;
    }
    resto = nullptr;
}

void GrafoList::addToGrafo(string estado){
    //Igual a todos os addToTopo das listas.
    topo = new GrafoNode(estado,topo);
    if(resto == nullptr){
        resto = topo;
    }
}

int GrafoList::countFront() const{
    //Contador;
    int fronteiras = 0;
    GrafoNode *tmp = topo;
    while (tmp != nullptr){
        fronteiras++;
        tmp = tmp->prox;
    }
    return fronteiras;
}

void GrafoList::printAll() const{
    for (GrafoNode* tmp = topo; tmp != nullptr; tmp = tmp->prox) {
        if(tmp->prox == nullptr){
            cout<< " " << tmp->nome << ".";
            break;
        }
        cout << " " << tmp->nome << ",";
        
    }
    cout << endl;
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    string nomes[9];
    GrafoList estados[9];
    int op;
    do{
        
        cout << "0) Sair" << endl;
        cout << "1) Adicionar estado" << endl;
        cout << "2) Adicionar fronteira" << endl;
        cout << "3) Mostrar estados e fronteiras" << endl;
        cout << "4) Liberar espaço" << endl;
        cin >> op;
        system("cls");
        switch(op){
            case 1:
                for (int i = 0; i < 9; i++) {
                    cout << "Digite o estado " << i << ": ";
                    cin >> nomes[i];
                }
                system("cls");
                break;
            case 2:
                int state, fronteira;
                for (int i = 0; i < 9; i++) {
                    cout << "Estado " << i << " :"<<nomes[i]<<endl;
                    estados[i].printAll();
                }
                cout << "Digite o indice do estado (vertice): ";
                cin >> state;
                cout << "Digite o indice da fronteira (ligação): ";
                cin >> fronteira;
                estados[state].addToGrafo(nomes[fronteira]);
                system("cls");
                break;
            case 3:
                for (int i = 0; i < 9; i++) {
                    cout << "O estado de indice "<< i << "("<< nomes[i] << ")"<< " faz " << estados[i].countFront() << " fronteira(s) com: ";
                    estados[i].printAll();
                }
                break;
            case 4:
                for (int i = 0; i < 9; i++) {
                    estados[i].~GrafoList();
                }
                system("cls");
                break;
            case 0:
                break;
            default:
                cout << "Opção incorreta" << endl;
                system("cls");
                break;
        }
    }while (op != 0);

    return 0;
}
#include <iostream>
#include <string>
#include <locale>

using namespace std;

class GrafoNode{
    public:
        GrafoNode(){
            prox = nullptr;
        }
        GrafoNode(string follower, GrafoNode *ptr = nullptr){
            nome = follower; prox = ptr;
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

void GrafoList::addToGrafo(string follower){
    //Igual a todos os addToTopo das listas.
    topo = new GrafoNode(follower,topo);
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
    GrafoList pessoas[9];
    int op;
    do{
        
        cout << "0) Sair" << endl;
        cout << "1) Adicionar pessoa" << endl;
        cout << "2) Adicionar quem a pessoa segue" << endl;
        cout << "3) Mostrar membros e quem segue" << endl;
        cout << "4) Liberar espaço" << endl;
        cout << "5) Pessoa com mais seguidores" <<endl;
        cin >> op;
        system("cls");
        switch(op){
            case 1:
                for (int i = 0; i < 9; i++) {
                    cout << "Digite o nome da pessoa " << i << ": ";
                    cin >> nomes[i];
                }
                system("cls");
                break;
            case 2:
                int person, following;
                for (int i = 0; i < 9; i++) {
                    cout << "Pessoa " << i << " :"<<nomes[i]<<endl;
                    pessoas[i].printAll();
                }
                cout << "Digite o indice da pessoa (vertice): ";
                cin >> person;
                cout << "Digite o indice de quem ela segue (ligação): ";
                cin >> following;
                pessoas[person].addToGrafo(nomes[following]);
                system("cls");
                break;
            case 3:
                for (int i = 0; i < 9; i++) {
                    cout << "A pessoa de indice "<< i << "("<< nomes[i] << ")"<< " segue " << pessoas[i].countFront() << " pessoas, esses sendo: ";
                    pessoas[i].printAll();
                }
                break;
            case 4:
                for (int i = 0; i < 9; i++) {
                    pessoas[i].~GrafoList();
                }
                system("cls");
                break;
            case 5:

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
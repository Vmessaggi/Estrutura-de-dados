#include <iostream>

using namespace std;

class IntDLLNode{
public:
    IntDLLNode(){
        prox = 0;
        ante = 0;
    }
    IntDLLNode(int el, IntDLLNode *ptr = 0, IntDLLNode *ant = 0){
        info = el;
        prox = ptr;
        ante = ant;
    }
    int info;
    IntDLLNode *prox;
    IntDLLNode *ante;
};

class IntDLList {
public:
    IntDLList(){
        topo = resto = 0;
    }
    int isEmpty(){
        return topo == 0;
    }
    void addToTopo(int);
    void addToResto(int);
    void deleteFromTopo();
    void deleteFromResto();
    void deleteNode();
    bool isInList(int) const;
    void printALL() const;

private:
    IntDLLNode *topo, *resto;
};

bool IntDLList::isInList(int el) const{

}

void IntDLList::deleteNode(){
    int num;
    bool existe;
    cout << "Digite o numero que deseja excluir: ";
    cin >> num;
    existe = isInList(num);
    if(existe == false){
        cout<<"Elemento nao esta na lista!";
    }else{
        
    }
}

void IntDLList::addToTopo(int el){
    if (topo != 0){
        topo->ante = new IntDLLNode(el);
        topo->ante->prox = topo;
        topo = topo->ante;
    }else{
        topo = resto = new IntDLLNode(el);
    }
}

void IntDLList::addToResto(int el){
    if (resto != 0){
        resto->prox = new IntDLLNode(el);
        resto->prox->ante = resto;
        resto = resto->prox;
    }else{
        topo = resto = new IntDLLNode(el);
    }
}

void IntDLList::deleteFromTopo(){
    if (resto == 0 && topo == 0){
        cout<<"Lista vazia!";
    }
    IntDLLNode *tmp = topo;
    if(topo == resto){
        topo = resto = 0;
    }else{
        topo->prox->ante = 0;
        topo = topo->prox;
    }
    delete tmp;
}

void IntDLList::deleteFromResto(){
    if (resto == 0 && topo == 0){
        cout << "Lista vazia!";
    }
    if(topo == resto){
        delete topo;
        topo = resto = 0;
    }else{
        IntDLLNode *tmp = resto;
        resto = resto->ante;
        resto->prox = 0;
        delete (tmp);
    }
}

void IntDLList::printALL() const{
    for(IntDLLNode *tmp = topo; tmp != 0; tmp = tmp->prox){
        cout << tmp->info << " ";
    }
    cout << endl;
    for(IntDLLNode *tmp = resto; tmp != 0; tmp = tmp->ante){
        cout << tmp->info << " ";
    }
    cout << endl;
}

int main(){
    //int el;
    IntDLList list;
    list.addToTopo(10);
    list.addToTopo(20);
    list.addToResto(50);
    list.addToResto(70);
    list.deleteFromTopo();
    list.deleteFromResto();
    list.addToTopo(100);
    list.printALL();
    list.deleteNode();
}
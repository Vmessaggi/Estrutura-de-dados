#include <iostream>

using namespace std;

class IntSLLNode{
public:
    IntSLLNode(){
        prox = 0;
    }
    IntSLLNode(int el, IntSLLNode *ptr =0){
        info = el;
        prox = ptr;
    }
    int info;
    IntSLLNode *prox;
};

class IntSLList {
public:
    IntSLList(){
        topo = resto = 0;
    }
    int isEmpty(){
        return topo == 0;
    }
    void addToTopo(int);
    void addToResto(int);
    void deleteFromTopo();
    void deleteFromResto();
    void deleteNode(int);
    bool isInList(int) const;
    void printALL() const;

private:
    IntSLLNode *topo, *resto;
};

void IntSLList::addToTopo(int el){
    topo = new IntSLLNode(el,topo);
    if (resto == 0){
        resto = topo;
    }
}

void IntSLList::addToResto(int el){
    if (resto != 0){
        resto->prox = new IntSLLNode(el);
        resto = resto->prox;
    }else{
        topo = resto = new IntSLLNode(el);
    }
}

void IntSLList::deleteFromTopo(){
    if (resto == 0 && topo == 0){
        cout<<"Lista vazia!";
    }
    IntSLLNode *tmp = topo;
    if(topo == resto){
        topo = resto = 0;
    }else{
        topo = topo->prox;
    }
    delete tmp;
}

void IntSLList::deleteFromResto(){
    if (resto == 0 && topo == 0){
        cout << "Lista vazia!";
    }
    if(topo == resto){
        delete topo;
        topo = resto = 0;
    }else{
        IntSLLNode *tmp;
        for(tmp = topo; tmp->prox != resto; tmp = tmp->prox){
            delete resto;
        }
        resto = tmp;
        resto->prox = 0;
    }
}

void IntSLList::printALL() const{
    for(IntSLLNode *tmp = topo; tmp != 0; tmp = tmp->prox){
        cout << tmp->info << " ";
    }
    cout << endl;
}

int main(){
    //int el;
    IntSLList list;
    list.addToTopo(10);
    list.addToTopo(20);
    list.addToResto(50);
    list.addToResto(70);
    list.deleteFromTopo();
    list.deleteFromResto();
    list.addToTopo(100);
    list.printALL();
}
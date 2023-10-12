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
    void addOrdered();
    void deleteFromTopo();
    void deleteFromResto();
    void deleteNode();
    bool isInList(int) const;
    void printALL() const;
    void organize();

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

void IntSLList::addOrdered(){
    organize();
    int el;
    cout<<"Digite um valor a ser inserido na lista: ";
    cin>>el;
    IntSLLNode* novoNode = new IntSLLNode(el);
    if(topo == nullptr || el <= topo->info){
        novoNode->prox = topo;
        topo = novoNode;
    }else{
       IntSLLNode* tmp = topo;
       while(tmp->prox != nullptr && tmp->prox->info < el){
        tmp = tmp->prox;
       }
       novoNode->prox = tmp->prox;
       tmp->prox = novoNode;
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

void IntSLList::organize(){
    if (topo == 0 || topo->prox == 0) {
        return; // Lista vazia ou com apenas um elemento já está ordenada
    }
    bool troca;
    IntSLLNode* ptr1;
    IntSLLNode* lptr = nullptr;
    do {
        troca = false;
        ptr1 = topo;
        while (ptr1->prox != lptr) {
            if (ptr1->info > ptr1->prox->info) {
                // Troca os dados dos nós
                int temp = ptr1->info;
                ptr1->info = ptr1->prox->info;
                ptr1->prox->info = temp;
                troca = true;
            }
            ptr1 = ptr1->prox;
        }
        lptr = ptr1;
    } while (troca);
}

void IntSLList::deleteNode(){
    IntSLLNode* atual = topo;
    IntSLLNode* anterior = nullptr;
    int el;
    cout<<"Digite um valor a ser removido da lista: ";
    cin>>el;
    while(atual != nullptr && atual->info != el){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual != nullptr){
        if(anterior != nullptr){
            anterior->prox = atual->prox;
        }else{
            topo = atual->prox;
        }
        delete atual;
    }else{
        cout<<"Elemento nao esta na lista.";
    }
    printALL();
}

int main(){
    IntSLList list;
    list.addToTopo(10);
    list.addToTopo(20);
    list.addToResto(50);
    list.addToResto(70);
    list.deleteFromTopo();
    list.deleteFromResto();
    list.addToTopo(100);
    cout<<"Lista antes de ser organizada: "<<endl;
    list.printALL();
    list.organize();
    cout<<"Lista apos de ser organizada: "<<endl;
    list.printALL();
    list.deleteNode();
    list.addOrdered();
    list.printALL();
    return 0;
}
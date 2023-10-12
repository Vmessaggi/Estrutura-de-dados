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
    void addOrdered();
    void deleteFromTopo();
    void deleteFromResto();
    void deleteNode();
    void printALL() const;
    void organize();

private:
    IntDLLNode *topo, *resto;
};

void IntDLList::organize(){
    if (topo == 0 || topo->prox == 0) {
        return; // Lista vazia ou com apenas um elemento já está ordenada
    }
    bool troca;
    IntDLLNode* ptr1;
    IntDLLNode* lptr = nullptr;
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

void IntDLList::deleteNode() {
    int num;
    cout << "Digite o número que deseja excluir: ";
    cin >> num;
    IntDLLNode* atual = topo;
    while(atual != nullptr && atual->info != num) {
        atual = atual->prox;
    }
    if(atual != nullptr) {
        if(atual->ante != nullptr && atual->prox != nullptr) {
            atual->ante->prox = atual->prox;
            atual->prox->ante = atual->ante;
        }else if(atual->ante == nullptr){
            topo = atual->prox;
            topo->ante = nullptr;
        }else if(atual->prox == nullptr){
            resto = atual->ante;
            resto->prox = nullptr;
        }
        
        delete atual;
    } else {
        cout << "Elemento não está na lista.";
    }
    printALL();
}

void IntDLList::addOrdered() {
    organize();
    int el;
    cout << "Digite um valor a ser inserido na lista: ";
    cin >> el;
    IntDLLNode* novoNode = new IntDLLNode(el);
    if (topo == nullptr || el <= topo->info) {
        novoNode->prox = topo;
        if (topo != nullptr) {
            topo->ante = novoNode;
        }
        topo = novoNode;
    }else {
        IntDLLNode* tmp = topo;
        while (tmp->prox != nullptr && tmp->prox->info < el) {
            tmp = tmp->prox;
        }
        if(tmp->prox == nullptr){
            resto->prox = novoNode;
            novoNode->ante = resto;
            resto = novoNode;
        }else{
            novoNode->prox = tmp->prox;
        novoNode->ante = tmp;
        if (tmp->prox != nullptr) {
            tmp->prox->ante = novoNode;
        }
        tmp->prox = novoNode;
        }
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
    cout << "Ordem crescente: \n";
    for(IntDLLNode *tmp = topo; tmp != 0; tmp = tmp->prox){
        cout << tmp->info << " ";
        cout <<endl;
    }
    cout << endl;
    cout << "Ordem decrescente: \n";
    for(IntDLLNode *tmp = resto; tmp != 0; tmp = tmp->ante){
        cout << tmp->info << " ";
        cout <<endl;
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
    cout<<"Lista antes de ser organizada: "<<endl;
    list.printALL();
    list.organize();
    cout<<"Lista apos de ser organizada: "<<endl;
    list.printALL();
    list.deleteNode();
    list.addOrdered();
    list.printALL();
}
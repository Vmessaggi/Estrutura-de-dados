#include <iostream>
#include <string>
#include <locale>

using namespace std;

class GrafoNode {
public:
    GrafoNode() {
        prox = nullptr;
    }
    GrafoNode(int vert, GrafoNode *ptr = nullptr) {
        vertice = vert; prox = ptr;
    }
    int vertice;
    GrafoNode *prox;
};

class GrafoList {
public:
    GrafoList() {
        topo = resto = nullptr;
    }
    ~GrafoList();
    void addToGrafo(int);
    int countFront() const;
    void printAll() const;
    void BuscaProfundidade(int ini) const;
    void DFS(int vertice, bool visitados[]) const;
private:
    GrafoNode *topo, *resto;    
};

GrafoList::~GrafoList() {
    while (topo != nullptr) {
        GrafoNode *tmp = topo;
        topo = topo->prox;
        delete tmp;
    }
    resto = nullptr;
}

void GrafoList::addToGrafo(int vertice) {
    topo = new GrafoNode(vertice, topo);
    if (resto == nullptr) {
        resto = topo;
    }
}

int GrafoList::countFront() const {
    int arestas = 0;
    GrafoNode *tmp = topo;
    while (tmp != nullptr) {
        arestas++;
        tmp = tmp->prox;
    }
    return arestas;
}

void GrafoList::printAll() const {
    for (GrafoNode* tmp = topo; tmp != nullptr; tmp = tmp->prox) {
        if (tmp == topo) {
            cout << " -> (" << tmp->vertice << ")";
        } else {
            cout << " -> (" << tmp->vertice << ")";
        }
    }
    cout << " -> NULL";
    cout << endl;
}

void GrafoList::DFS(int vertice, bool visitados[]) const {
    visitados[vertice] = true;
    cout << vertice << " ";
    for (GrafoNode *tmp = topo; tmp != nullptr; tmp = tmp->prox) {
        int adjacente = tmp->vertice;
        if (!visitados[adjacente]) {
            DFS(adjacente, visitados);
        }
    }
}

void GrafoList::BuscaProfundidade(int ini) const {
    bool *visitados = new bool[countFront()];
    for (int i = 0; i < countFront(); i++) {
        visitados[i] = false;
    }

    cout << "Busca em Profundidade a partir do vértice " << ini << ": ";
    DFS(ini, visitados);
    cout << endl;

    delete[] visitados;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int vert[5];
    GrafoList vertices[5];
    int op;
    do {
        cout << "0) Sair" << endl;
        cout << "1) Adicionar vértice" << endl;
        cout << "2) Adicionar aresta" << endl;
        cout << "3) Mostrar vértices e arestas" << endl;
        cout << "4) Busca em Profundidade (DFS)" << endl;
        cout << "5) Liberar espaço" << endl;
        cin >> op;
        system("clear");
        switch (op) {
            case 1:
                for (int i = 0; i < 5; i++) {
                    cout << "Digite o vértice " << i << ": ";
                    cin >> vert[i];
                }
                system("clear");
                break;
            case 2:
                int choosen, aresta;
                for (int i = 0; i < 5; i++) {
                    cout << "vértice " << i << " :";
                    vertices[i].printAll();
                }
                cout << "Digite o índice do vértice: ";
                cin >> choosen;
                cout << "Digite o índice da aresta (ligação): ";
                cin >> aresta;
                vertices[choosen].addToGrafo(vert[aresta]);
                system("clear");
                break;
            case 3:
                for (int i = 0; i < 5; i++) {
                    cout << "(" << vert[i] << ")";
                    vertices[i].printAll();
                }
                break;
            case 4:
                int vertinicial;
                cout << "Digite o vértice de início para a busca em profundidade: ";
                cin >> vertinicial;
                vertices[vertinicial].BuscaProfundidade(vertinicial);
                break;
            case 5:
                for (int i = 0; i < 5; i++) {
                    vertices[i].~GrafoList();
                }
                system("clear");
                break;
            case 0:
                break;
            default:
                cout << "Opção incorreta" << endl;
                system("clear");
                break;
        }
    } while (op != 0);

    return 0;
}

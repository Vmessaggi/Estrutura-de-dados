#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <locale.h>

using namespace std;

class Grafo {
private:
    int vertices;
    vector<vector<pair<int, int>>> listaAdj;

public:
    Grafo(int v) : vertices(v), listaAdj(v) {}

    void adicionarAresta(int origem, int destino, int peso) {
        listaAdj[origem].emplace_back(destino, peso);
    }

    void dijkstra(int origem) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> filaPrioridade;
        vector<int> distancias(vertices, numeric_limits<int>::max());

        filaPrioridade.push(make_pair(0, origem));
        distancias[origem] = 0;

        while (!filaPrioridade.empty()) {
            int u = filaPrioridade.top().second;
            filaPrioridade.pop();

            for (const auto& vizinho : listaAdj[u]) {
                int v = vizinho.first;
                int pesoUV = vizinho.second;

                if (distancias[v] > distancias[u] + pesoUV) {
                    distancias[v] = distancias[u] + pesoUV;
                    filaPrioridade.push(make_pair(distancias[v], v));
                }
            }
        }
        cout << "Distâncias mínimas a partir do vértice " << origem << ":\n";
        for (int i = 0; i < vertices; ++i) {
            cout << "Para o vértice " << i << ": " << distancias[i] << '\n';
        }
    }
};

int main() {
    setlocale(LC_ALL, "Portuguese");
    Grafo grafo(5);

    grafo.adicionarAresta(0, 1, 48);
    grafo.adicionarAresta(0, 3, 33);
    grafo.adicionarAresta(1, 2, 52);
    grafo.adicionarAresta(3, 2, 16);
    grafo.adicionarAresta(2, 4, 108);

    int verticeOrigem = 0;
    grafo.dijkstra(verticeOrigem);

    return 0;
}

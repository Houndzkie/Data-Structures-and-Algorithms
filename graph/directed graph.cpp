#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;  // number of vertices
    vector<vector<int>> adj;  // adjacency list

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);  // Only u → v (directed)
    }

    void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << "Node " << i << " has edges to: ";

            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }

            cout << endl;
        }
    }
};

int main() {
    Graph g(5);  // 5 nodes: 0 to 4

    g.addEdge(0, 1);  // 0 → 1
    g.addEdge(0, 4);  // 0 → 4
    g.addEdge(1, 2);  // 1 → 2
    g.addEdge(1, 3);  // 1 → 3
    g.addEdge(1, 4);  // 1 → 4
    g.addEdge(2, 3);  // 2 → 3
    g.addEdge(3, 4);  // 3 → 4

    g.printGraph();

    return 0;
}
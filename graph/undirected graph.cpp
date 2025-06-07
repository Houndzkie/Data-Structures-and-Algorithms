#include <iostream>
#include <vector>
using namespace std;

class Graph {
  private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

  public:
    Graph(int vertices) {
      V = vertices;
      adj.resize(V);
    }

    void addEdge(int u, int v) {
      adj[u].push_back(v); // Add v to u's list
      adj[v].push_back(u); // Add u to v's list (since undirected)
    }

    void printGraph() {
      for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": ";

        for (int neighbor : adj[i]) {
          cout << neighbor << " ";
        }

        cout << endl;
      }
    }
};

int main() {
    Graph g(5);  // Create a graph with 5 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}

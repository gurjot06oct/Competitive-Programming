#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<int> *adj;
    void APUtil(int u, vector<bool> &visited, vector<int> &disc,
                vector<int> &low, int parent, vector<bool> &ap);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void findAP();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::APUtil(int u, vector<bool> &visited, vector<int> &disc,
                   vector<int> &low, int parent, vector<bool> &ap) {
    static int time = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            APUtil(v, visited, disc, low, u, ap);
            low[u] = min(low[u], low[v]);
            if (parent != -1  && low[v] >= disc[u]) ap[u] = true;
        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }
    if(parent == -1 && children > 1) ap[u] = true;
}

void Graph::findAP() {
    vector<bool> visited(V, false);
    // disc[u]: Discovery time of vertex u
    // low[u]: Earliest visited vertex reachable from u
    // parent[u]: Parent vertex in DFS tree
    // ap[u]: Boolean array to store articulation points
    vector<int> disc(V, -1), low(V, -1);
    vector<bool> ap(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            APUtil(i, visited, disc, low, -1, ap);
    }

    cout << "Discovery Points: ";
    for (int i = 0; i < V; i++) {
            cout << disc[i] << " ";
    }
    cout<<endl;
    cout << "LOW Points: ";
    for (int i = 0; i < V; i++) {
            cout << low[i] << " ";
    }
    cout<<endl;
    cout << "Articulation Points: ";
    for (int i = 0; i < V; i++) {
        if (ap[i])
            cout << i << " ";
    }
    cout << endl;
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(3, 4);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.findAP();
    return 0;
}
// DFS Traversal: O(V + E)
// Each edge is visited once
// Overall Complexity: O(V + E)
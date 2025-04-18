int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;
    
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;
    
    cout << "Dijkstra's Algorithm Output:\n";
    g.dijkstra(source);

    return 0;
}
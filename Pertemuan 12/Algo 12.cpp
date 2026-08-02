#include <iostream>
#include <climits>
using namespace std;

const int V = 6;

int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        cout << j + 1;
        return;
    }

    printPath(parent, parent[j]);
    cout << " -> " << j + 1;
}

void dijkstra(int graph[V][V], int src, int dest) {
    int dist[V];
    bool visited[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {

        int u = minDistance(dist, visited);

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < V; v++) {

            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Shortest distance from node "
         << src + 1 << " to node "
         << dest + 1 << " = "
         << dist[dest] << endl;

    cout << "Path : ";
    printPath(parent, dest);
    cout << endl;
}

int main() {

    int graph[V][V] = {
        {0,4,2,0,0,0},
        {4,0,1,5,0,0},
        {2,1,0,8,10,0},
        {0,5,8,0,2,6},
        {0,0,10,2,0,3},
        {0,0,0,6,3,0}
    };

    dijkstra(graph, 0, 4);

    return 0;
}

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void depthFirstSearch(int vertex, const vector<vector<int>>& adjacency,
                      vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex << ' ';

    for (int neighbour : adjacency[vertex]) {
        if (!visited[neighbour]) {
            depthFirstSearch(neighbour, adjacency, visited);
        }
    }
}

void breadthFirstSearch(int start, const vector<vector<int>>& adjacency) {
    vector<bool> visited(adjacency.size(), false);
    queue<int> pending;

    visited[start] = true;
    pending.push(start);

    while (!pending.empty()) {
        int vertex = pending.front();
        pending.pop();
        cout << vertex << ' ';

        for (int neighbour : adjacency[vertex]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true; 
                pending.push(neighbour);
            }
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of buildings (vertices) and roads (edges): ";
    if (!(cin >> vertices >> edges) || vertices <= 0 || edges < 0) {
        cout << "Invalid graph dimensions.\n";
        return 1;
    }

    vector<vector<int>> adjacency(vertices);
    cout << "Enter each road as two vertex numbers (0 to " << vertices - 1 << "):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        if (!(cin >> u >> v) || u < 0 || u >= vertices || v < 0 || v >= vertices) {
            cout << "Invalid road endpoint.\n";
            return 1;
        }
        adjacency[u].push_back(v);
        adjacency[v].push_back(u); 
    }

    int start;
    cout << "Enter the starting building: ";
    if (!(cin >> start) || start < 0 || start >= vertices) {
        cout << "Invalid starting building.\n";
        return 1;
    }

    vector<bool> visited(vertices, false);
    cout << "Depth-First Search (DFS): ";
    depthFirstSearch(start, adjacency, visited);
    cout << '\n';

    cout << "Breadth-First Search (BFS): ";
    breadthFirstSearch(start, adjacency);
    cout << '\n';

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Function to add an edge between two vertices in the graph.
void addEdge(vector<vector<int>>& adjList, int u, int v) {

    adjList[u].push_back(v);
    adjList[v].push_back(u);

}

// Breadth-First Search (BFS) algorithm to find the shortest path between two vertices.
vector<int> findShortestPath(const vector<vector<int>>& adjList, int start, int end) {

    queue<int> q; // Queue to perform BFS
    vector<bool> visited(adjList.size(), false); // Track visited vertices
    vector<int> parent(adjList.size(), -1); // Track parents to reconstruct the path

    q.push(start); // Start BFS from the 'start' vertex
    visited[start] = true; // Mark 'start' as visited

    while (!q.empty()) {
        int current = q.front(); // Dequeue the current vertex
        q.pop();

        if (current == end) {
            // If we reached the 'end' vertex, stop the BFS
            // The shortest path has been found.
            break;
        }

        for (int neighbor : adjList[current]) {
            // Explore all unvisited neighbors of the current vertex
            if (!visited[neighbor]) {
                q.push(neighbor); // Enqueue the neighbor for further exploration
                visited[neighbor] = true; // Mark the neighbor as visited
                parent[neighbor] = current; // Set the current vertex as the parent of the neighbor
            }
        }
    }

    // Reconstruct the shortest path from 'start' to 'end'
    vector<int> shortestPath;
    int current = end;
    while (current != -1) {
        shortestPath.push_back(current); // Add the current vertex to the path
        current = parent[current]; // Move to the parent vertex
    }

    reverse(shortestPath.begin(), shortestPath.end()); // Reverse the path to get the correct order
    return shortestPath;

}

int main() {

    int vertices, edges;
    cout << "Enter the number of vertices in the graph : ";
    cin >> vertices;
    cout << "Enter the number of edges in the graph : ";
    cin >> edges;

    vector<vector<int>> adjList(vertices); // Adjacency list representation of the graph

    cout << "Enter the edges (format: u v) where u and v are connected vertices :" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adjList, u, v); // Add edges to the adjacency list
    }

    int start, end;
    cout << "Enter the source and destination vertices to find the shortest path : ";
    cin >> start >> end;

    vector<int> shortestPath = findShortestPath(adjList, start, end); // Find the shortest path

    cout << "Shortest path from " << start << " to " << end << ": ";
    for (int vertex : shortestPath) {
        cout << vertex << " ";
    }
    cout << endl;
    return 0;

}

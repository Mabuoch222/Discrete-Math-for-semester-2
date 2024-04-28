#include <iostream>
#include <vector>

using namespace std;

// Function to check if a graph is a complete graph
bool isCompleteGraph(vector<vector<int>>& adjList) {
    int numVertices = adjList.size();

    // Check for each vertex if it is connected to all other vertices
    for (int i = 0; i < numVertices; i++) {
        // Check if the number of adjacent vertices is equal to the number of remaining vertices
        if (adjList[i].size() != numVertices - 1) {
            return false;
        }
    }

    return true;
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> adjList(numVertices);

    cout << "Enter the edges (vertex1 vertex2):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;

        // Adding the edges to the adjacency list
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
    }

    // Check if the graph is complete
    if (isCompleteGraph(adjList)) {
        cout << "The graph is a complete graph." << endl;
    } else {
        cout << "The graph is not a complete graph." << endl;
    }

    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

// Function to compute the in-degree and out-degree of each vertex
void computeDegree(const vector<vector<int>>& adjList, vector<int>& inDegree, vector<int>& outDegree) {
    int numVertices = adjList.size();

    for (int i = 0; i < numVertices; i++) {
        // Computing out-degree of vertex i
        outDegree[i] = adjList[i].size();

        // Computing in-degree of vertex i by traversing the adjacency list
        for (int j = 0; j < numVertices; j++) {
            for (int k = 0; k < adjList[j].size(); k++) {
                if (adjList[j][k] == i) {
                    inDegree[i]++;
                }
            }
        }
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> adjList(numVertices);
    vector<int> inDegree(numVertices, 0);
    vector<int> outDegree(numVertices, 0);

    cout << "Enter the edges (source destination):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        cin >> source >> destination;

        // Adding the directed edge to the adjacency list
        adjList[source].push_back(destination);
    }

    // Compute the in-degree and out-degree
    computeDegree(adjList, inDegree, outDegree);

    // Displaying the in-degree and out-degree of each vertex
    cout << "Vertex\tIn-Degree\tOut-Degree" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << i << "\t" << inDegree[i] << "\t\t" << outDegree[i] << endl;
    }

    return 0;
}


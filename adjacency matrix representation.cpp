#include <iostream>
#include <vector>

using namespace std;


bool isCompleteGraph(const vector<vector<int>>& adjacencyMatrix) {
    int numVertices = adjacencyMatrix.size();

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            // Skip checking self-loops
            if (i == j)
                continue;

            // If there is no edge between vertices i and j, return false
            if (adjacencyMatrix[i][j] == 0)
                return false;
        }
    }

    return true;
}

int main() {
    // Get the number of vertices from the user
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    // Create the adjacency matrix with initial values as 0
    vector<vector<int>> adjacencyMatrix(numVertices, vector<int>(numVertices, 0));

    // Get the adjacency matrix values from the user
    cout << "Enter the adjacency matrix values (0 or 1):\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    // Check if the graph is complete
    bool isComplete = isCompleteGraph(adjacencyMatrix);

    // Print the result
    if (isComplete)
        cout << "The graph is a complete graph." << endl;
    else
        cout << "The graph is not a complete graph." << endl;

    return 0;
}



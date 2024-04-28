#include <iostream>
#include <vector>

using namespace std;

void findSolutions(int n, int C) {
    vector<int> solution(n, 0); // Initialize solution vector with all zeros
    int totalSolutions = 0;

    while (true) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += solution[i];
        }

        if (sum == C) {
            ++totalSolutions;
            cout << "Solution " << totalSolutions << ": ";
            for (int i = 0; i < n; ++i) {
                cout << solution[i] << " ";
            }
            cout << endl;
        }

        // Generate next combination of values
        int index = n - 1;
        while (index >= 0 && solution[index] == C) {
            solution[index] = 0;
            --index;
        }

        if (index < 0) {
            break; // All combinations generated
        }

        ++solution[index];
    }

    cout << "Total solutions: " << totalSolutions << endl;
}

int main() {
    int n, C;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Enter the value of C (C <= 10): ";
    cin >> C;

    cout << "Solutions for x1 + x2 + x3 + ... + xn = " << C << endl;
    findSolutions(n, C);

    return 0;
}


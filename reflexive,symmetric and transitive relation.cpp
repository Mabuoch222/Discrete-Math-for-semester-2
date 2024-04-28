#include <iostream>
#include <vector>

using namespace std;

class RELATION {
private:
    vector<vector<int>> matrix;

public:
    RELATION(vector<vector<int>> inputMatrix) : matrix(inputMatrix) {}

    bool isReflexive() {
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][i] != 1) {
                return false;
            }
        }
        return true;
    }

    bool isSymmetric() {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isAntiSymmetric() {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 1 && matrix[j][i] == 1 && i != j) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isTransitive() {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 1) {
                    for (int k = 0; k < matrix[j].size(); ++k) {
                        if (matrix[j][k] == 1 && matrix[i][k] != 1) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    string checkEquivalence() {
        if (isReflexive() && isSymmetric() && isTransitive()) {
            return "Equivalence Relation";
        } else {
            return "Not an Equivalence Relation";
        }
    }

    string checkPartialOrder() {
        if (isReflexive() && isAntiSymmetric() && isTransitive()) {
            return "Partial Order Relation";
        } else {
            return "Not a Partial Order Relation";
        }
    }

    string checkRelationType() {
        if (isReflexive() && isSymmetric() && isAntiSymmetric() && isTransitive()) {
            return "Equivalence Relation and Partial Order Relation";
        } else if (isReflexive() && isSymmetric() && isTransitive()) {
            return "Equivalence Relation";
        } else if (isReflexive() && isAntiSymmetric() && isTransitive()) {
            return "Partial Order Relation";
        } else {
            return "None";
        }
    }
};

int main() {
    vector<vector<int>> inputMatrix = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    RELATION relation(inputMatrix);

    cout << "Checking Relation Type: " << relation.checkRelationType() << endl;

    return 0;
}

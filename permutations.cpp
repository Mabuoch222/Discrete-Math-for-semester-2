#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generatePermutations(vector<int>& digits, bool withRepetition) {
    sort(digits.begin(), digits.end());

    do {
        for (int digit : digits) {
            cout << digit << " ";
        }
        cout << endl;
    } while (withRepetition ? next_permutation(digits.begin(), digits.end()) : next_permutation(digits.begin(), digits.end(), greater<int>()));
}

int main() {
    int n;
    cout << "Enter the number of digits: ";
    cin >> n;

    vector<int> digits(n);
    cout << "Enter the digits: ";
    for (int i = 0; i < n; ++i) {
        cin >> digits[i];
    }

    bool withRepetition;
    cout << "Do you want permutations with repetition? (0 - No, 1 - Yes): ";
    cin >> withRepetition;

    cout << "Permutations:" << endl;
    generatePermutations(digits, withRepetition);

    return 0;
}

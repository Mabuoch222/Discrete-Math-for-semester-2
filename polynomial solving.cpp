#include <iostream>
#include <cmath>

using namespace std;

// Function to evaluate a polynomial given its coefficients and the value of x
double evaluatePolynomial(const double coefficients[], int degree, double x) {
    double result = 0.0;

    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, i);
    }

    return result;
}

int main() {
    // Define the coefficients of the polynomial
    double coefficients[] = {9, 2, 4};  // Coefficients of f(x) = 4n^2 + 2n + 9

    // Specify the degree of the polynomial
    int degree = sizeof(coefficients) / sizeof(coefficients[0]) - 1;

    // Specify the value of n
    double n = 5;

    // Evaluate the polynomial for the given value of n
    double result = evaluatePolynomial(coefficients, degree, n);

    // Print the result
    cout << "f(" << n << ") = " << result << endl;

    return 0;
}


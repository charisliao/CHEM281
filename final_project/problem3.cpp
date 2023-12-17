/**
 * @file problem3.cpp
 * @author Charis Liao (charisliao@berkeley.edu)
 * @brief 
 * @version 0.1
 * @date 2023-12-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cmath>

using namespace std;

// PROBLEM 3 PROMPT:

// Compute the length of the curve described by sin(x). Due to Symmetry of this curve
// we just need to compute the length of a quarter arc. (The length of the entire cycle is 4 times this value). 
// l = sqrt(2) * E(sqrt(2) / 2); E is the evaluation of the complete elliptic integral of the second kind.

double doubleFactorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * doubleFactorial(n - 2);
}

double estimateQuarterArcLength(double E) {
    return sqrt(2) * E;
}


/**
 * @brief 3a. Compute the length of a quarter arc of the sin() function using the formula sqrt(2)*E(sqrt(2)/2). 
 * Determine how many terms to use in the E(k) series. 
 * 
 * @param k: the argument of the E(k) function
 * @param n: determine how many terms to use in the E(k) series
 */

double E_left_to_right(double k, int n) {
    double sum = 0.0; 

    for (int i = 0; i < n; i++) {

        if (i == 0) {
            sum += 1.0;
        }
        else {
            sum -= (pow(doubleFactorial(2 * i - 1) / doubleFactorial(2 * i), 2) * (pow(k, 2 * i) / (2 * i - 1)));
            
        }
    }
    return M_PI / 2 * sum;
}

/**
 * @brief 3b. Compute the length of a quarter arc of the sin() function using the formula sqrt(2)*E(sqrt(2)/2). 
 * Determine how many terms to use in the E(k) series. 
 * 
 * @param k: the argument of the E(k) function
 * @param n: determine how many terms to use in the E(k) series
 */

double E_right_to_left(double k, int n) {
    double sum = 0.0; 

    for (int i = n; i > 0; i--) {

        if (i == n) {
            sum += 1.0;
        }
        else {
            sum -= (pow(doubleFactorial(2 * i - 1) / doubleFactorial(2 * i), 2) * (pow(k, 2 * i) / (2 * i - 1)));
        }
    }
    return M_PI / 2 * sum ;
}

int main() {

    // Estimate the length of the quarter arc of the sin() function using E from left to right. 
    // PROBLEM 3a. 
    cout << "PROBLEM 3a." << endl;
    double k = sqrt(2) / 2;
    int n = 50;
    double E = E_left_to_right(k, n);
    double length = estimateQuarterArcLength(E);
    cout << "The length of the quarter arc is (left to right): " << length << endl;

    cout << endl;

    // Estimate the length of the quarter arc of the sin() function using E from right to left.
    // PROBLEM 3b.
    cout << "PROBLEM 3b." << endl;
    k = sqrt(2) / 2;
    n = 50;
    E = E_right_to_left(k, n);
    length = estimateQuarterArcLength(E);
    cout << "The length of the quarter arc is (right to left): " << length << endl;
    
    cout << endl;
    cout << "After different trials, I found that was n goes larger, the result converges to 1.91." << endl;
    return 0;

}





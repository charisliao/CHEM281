
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

// using float for single precision - 32 bits
float euler(float n) {    
    return pow(1.0f + 1.0f/n, n);
}

float euler_improved(float n) {
    // ln(1+x) approx x when x is very small
    float x = 1.0f/n;
    float y = 1.0f + x;
    if (x < 10e-5) {
        return exp(y);
    } else {
        return exp(n * log(y));
    }
}

// problem 2 
float square_root(float x, int range) {

    for (int i = 0; i < range; i++) {
        x = sqrt(x);
    }
    return x;
}

float square(float x, int range) {
    for (int i = 0; i < range; i++) {
        x = pow(x, 2);
    }
    return x;
}

double compute_z(double x) {
    double e_x = exp(x);
    return (e_x - 1.0)/x; 
}

double alternative_compute_z(double x) {
    double y = exp(x);   
    if (y==1.0f) {
        return 1.0;
    } else {
        return (y -1.0)/log(y); 
    }
}

double estimate_log(double x) {
    return log2(x);
}

double alternative_estimate_log(double x) {
    
    // translate x into bits 
    uint64_t bits = *reinterpret_cast<uint64_t*>(&x);

    // Extract exponent bits and get rid of the mantissa
    uint64_t exponent_bits = (bits >> 52) & 0x7FF; // Assuming a double-precision floating-point number


    // subtract 1023 to get the exponent
    int exponent = static_cast<int>(exponent_bits) - 1023;


    // return the exponent
    return exponent;

    
}

int main() {

    // Problem 1a - print a table of e versus n
    cout << "Problem 1a" << endl;
    cout << endl;
    cout << "n\t" << "e" << endl;
    cout << "----------------" << endl;
    for (int i = 1; i <= 8; i++) {
        cout << powf(10, i) << "\t" << euler(powf(10, i)) << endl;
    }

    // Problem 1b - print a table of e versus n
    cout << endl;
    cout << "Problem 1b" << endl;
    cout << endl;
    cout << "n\t" << "e" << endl;
    cout << "----------------" << endl;
    for (int i = 1; i <= 8; i++) {
        cout << powf(10, i) << "\t" << euler_improved(powf(10, i)) << endl;
    }


    // Problem 2 - print a table of square root versus n
    cout << endl;
    cout << "Problem 2 - square-rooting x" << endl;
    cout << endl;
    vector<int> n = {2, 5, 10, 20, 30, 40};
    cout << "n\t" << "sqrt(x)\t" << "square(x)\t" << endl;
    cout << "------------------------------" << endl;
    float x = 100.0f; 
    for (int i : n) { 
        float square_root_x = square_root(x, i);
        float square_x = square(square_root_x, i);
        cout << i << "\t" << square_root_x << "\t" << square_x << endl;
    }

    // Problem 3 - print a table of z versus x

    cout << endl;
    cout << "Problem 3" << endl;
    cout << endl;
    cout << setw(3) << "n" << setw(12) << "z" << setw(12) << "alt_y" << endl;
    cout << "------------------------------" << endl;

    for (int i = -5; i >= -15; i--) { 
        double x = pow(10, i);
        double z = compute_z(x);
        double alt_z = alternative_compute_z(x);
        cout << x << setw(12) << z << setw(12) << alt_z << endl;
    }

    // problem 4 
    cout << endl;
    cout << "Problem 4" << endl;
    cout << endl;
    cout << setw(3) << "x" << setw(12) << "log(x)\t" << setw(12) << "alt_log(x)\t" << endl;
    cout << "------------------------------------" << endl;

    for (int i = 1; i <= 10; i++) { 
        double x = i;
        double log_x = estimate_log(x);
        double alt_log_x = alternative_estimate_log(x);
        cout << setw(3)<< i << setw(12) << log_x << setw(12) << alt_log_x << endl;
    }

    return 0; 


}
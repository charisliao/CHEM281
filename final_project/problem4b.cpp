/**
 * @file problem4b.cpp
 * @author Charis Liao (charisliao@berkeley.edu)
 * @brief 
 * @version 0.1
 * @date 2023-12-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <math.h>

using namespace std;


template <class T>
T func(const T x) {
    return sqrt(1 - pow(sqrt(2) / 2, 2) * pow(sin(x), 2));
}

template <class T>
T evalfunc(const T stepsize, const unsigned int step) {
    return func(step * stepsize);
}

template <class T>
T trinteg(const T stepsize, const unsigned int nsteps) {
    T sum = 0.0;
    for (int i = 0; i < nsteps; i++) {
        sum += evalfunc(stepsize, i);
    }
    return (sum * stepsize - 0.5 * (evalfunc(stepsize, 0) + evalfunc(stepsize, nsteps - 1)) * stepsize) * sqrt(2);
}

int main(int argc, char* argv[]) {
    const unsigned int default_nsteps = 1000000;
    unsigned int nsteps_param = 0;
    
    for (unsigned int k = 1; k < argc;) {
        if (strcmp(argv[k], "--steps") == 0) {
            if (argc < k + 2) {
                printf("error: --steps has to be followed by a number\n");
                exit(1);
            } else {
                nsteps_param = atoi(argv[k + 1]);
            }
            k += 2;
            continue;
        }
        if (strcmp(argv[k], "--threads") == 0) {
            if (argc < k + 2) {
                printf("error: --threads has to be followed by a number\n");
                exit(1);
            } 
            k += 2;
            continue;
        } else {
            printf("error: %s unrecognized keyword\n", argv[k]);
            exit(1);
        }
    }
    std::cout.precision(std::numeric_limits<double>::max_digits10 - 1);
    // call cei to get the reference value

    

    double lower_limit = 0.e+00;
    double upper_limit = M_PI / 2.e+00;

    const unsigned int nsteps = nsteps_param ? nsteps_param : default_nsteps;
   

    double double_step_size = (upper_limit - lower_limit) / (nsteps - 1);
    float float_step_size = (upper_limit - lower_limit) / (nsteps - 1);
    auto start = std::chrono::high_resolution_clock::now();
    double intval = trinteg(double_step_size, nsteps);
    double intval_float = trinteg(float_step_size, nsteps);
    auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsed_seconds{end - start};
    cout << "Integration uses " << nsteps << " steps" << endl;
    cout << "double integ: " << intval << endl;
    cout << "float integ: " << intval_float << endl;
    cout << "elapsed time: " << elapsed_seconds.count() << "s" << endl;
    

    return 0;
}
/**
 * @file hw3.2.cpp
 * @author Charis Liao (charisliao@berkeley.edu)
 * @brief Given a number x, print a list of all non-increasing
 * sequences of numbers that sum to x. The program gets the 
 * value of x from the command line.
 * @version 0.1
 * @date 2023-11-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVector(vector<int> v){
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

}

void printAllNonIncreasingSequences(int x, vector<int> v){
    if (x == 0){
        printVector(v);
        return;
    }
    for (int i = 1; i <= x; i++){
        if (v.size() == 0 || i <= v[v.size()-1]){
            v.push_back(i);
            printAllNonIncreasingSequences(x-i, v);
            v.pop_back();
        }
    }
}

int main(int argc, char* argv[]){
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <x>" << endl;
        return 1; // Exit with an error code
    }

    int x = stoi(argv[1]);
    vector<int> v;
    printAllNonIncreasingSequences(x, v);
    return 0;
}

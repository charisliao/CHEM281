/**
 * @file problem1.cpp
 * @author Charis Liao (charisliao@berkeley.edu)
 * @brief 
 * @version 0.1
 * @date 2023-12-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// In a particular game, n participants decide to arrange themselves in a circle in positions number from 0 to n-1.
// The game goes as follows: Startint from a given participants, a judge starts counting participants and removes the m-th
// person from the circle. Then, the judge starts counting again going around the circle until only one participant, the winner,
// is left. Write a C++ program that takes n and m as integers and determines which position corresponds to the only player 
// remaining in the game. 
// HINT: Use a circular queue where after all the participants are added, the head is connected to the tail. 

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int whosTheLuckyOne(int num_participants, int m) {
    // create a queue such that the head is connected to the tail
    queue<int> participants;
    for (int i = 0; i < num_participants; i++) {
        participants.push(i);
    }

    // remove the m-th person from the circle
    while (participants.size() > 1) {
        for (int i = 0; i < m - 1; i++) {
            participants.push(participants.front());
            participants.pop();
        }
        participants.pop();
    }

    return participants.front();
}

int main() {
    int num_participants = 9995;
    int m = 500;
    int winner = whosTheLuckyOne(num_participants, m);
    cout << "The winner is: " << winner << endl;
    return 0;
}
/*
 * File: MakeChange.cpp
 * ----------------------------
 * Name: [TODO: Amy R. Weiner]
 * Section: [TODO: Sammy Nguyen]
 * This program implements a function MakeChange that 
 * uses recursion in order to determine the minimum 
 * number of coins required to make the given amount
 * of change.  
 */

#include <iostream>
#include <string>
#include "vector.h"
#include "console.h"

using namespace std;

/* Funciton prototypes */
int MakeChange(int amount, Vector<int>& denominations); 
int getCoinsUsed(int coinsUsed, int amount, Vector<int> & denominations);

/* Main function */
int main() {
	int amount = 31;
    Vector<int> denominations;
    denominations += 2;
    denominations += 10;
    denominations += 20;
	int numCoins = MakeChange(amount, denominations);
    cout << numCoins;
	return 0;
}

/* Function: int MakeChange(int amount, Vector<int>& denominations)
 * ==================================================================
 * Takes an amount along with the Vector of available coin values,
 * and returns the minimum number of coins required.
 */
int MakeChange(int amount, Vector<int> & denominations) {
    if (amount < 0) {
        return -1;
    } else if (amount == 0) {
        return 0;
    } else {
        int min = -1;
        for(int i = 0; i < denominations.size(); i++){ 
            int result = MakeChange(amount - denominations[i] , denominations);
            if (min < 0 || (result >= 0 && result < min)) {
                min = result;
            }
        }
        if (min < 0) {
            return -1;
        }
        return min + 1;     
    }
}

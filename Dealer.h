#pragma once
#include "die.h"
#include <string>
using namespace std;

class Dealer {
private:
    Die die1, die2;
    int die1Val, die2Val;

public:
    Dealer() {
        die1Val = 0;
        die2Val = 0;
    }

    void rollDice() {
        die1.roll();
        die2.roll();
        die1Val = die1.getVal();
        die2Val = die2.getVal();
    }

    string getChoOrHan() {
        string result;
        int sum = die1Val + die2Val;

        if (sum % 2 == 0){
            result = "Cho (even)";
        }
        else {
            result = "Han (odd)";
        }
        return result;
    }

    int getdie1Val() {
        return die1Val;
    }

    int getdie2Val() {
        return die2Val;
    }
};

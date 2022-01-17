#pragma once
#include <cstdlib>
#include <time.h>
using namespace std;

class Die {
private:
    int sides, values;

public:
    Die(int numsides = 6) {
        unsigned seed = time(0);
        srand (seed);
        sides = numsides;
        roll();
    }

    void roll() {
        const int minVal = 1;
        values = (rand() % (sides - minVal + 1)) + minVal;
    }

    int getSides() {
        return sides;
    }

    int getVal() {
        return values;
    }
};

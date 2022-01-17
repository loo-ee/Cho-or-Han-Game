#pragma once
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

class Player {
private:
    string name, guess;
    int points;

public:
    Player() {
        name= "";
        guess = "";
        points = 0;
    }

    Player(string playerName) {
        srand (time(0));
        name = playerName;
        guess = "";
        points = 0;
    }

    void makeGuess() {
        char playerGuess;

        cout << "\nPress [1] for Cho or press [2] for Han.\n"
        << "Enter your guess, " << name << ": ";
        cin >> playerGuess;

        if (playerGuess == '1') {
            guess = "Cho (even)";
        }
        else {
            guess = "Han (odd)";
        }
    }

    void addPoints(int newPoints) {
        points += newPoints;
    }

    string getName() {
        return name;
    }

    string getGuess() {
        return guess;
    }

    int getPoints() {
        return points;
    }
};

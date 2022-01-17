#include <iostream>
#include "die.h"
#include "Dealer.h"
#include "Player.h"
using namespace std;

void roundResult(Dealer &, Player *, int);
void getGuesses(Dealer &, Player &);
void disPlayOverall(Player *, int);

int main(void) {
    int maxTurns, howmanyplayers;
    string playername;
    char reload;

    cout << "Enter how many players who wants to play: ";
    cin >> howmanyplayers;

    Dealer dealer;
    Player *Players = new Player[howmanyplayers];

    for (int i = 0; i < howmanyplayers; i++) {
        cout << "Enter name for player #" << i+1 << ": ";
        getline (cin >> ws, playername);
        Players[i] = Player(playername);
    }
    cout << endl << "Enter number of max turns for this game.\n"
    << ">> ";
    cin >> maxTurns;

    for (int i = 0; i < maxTurns; i++){
        cout << "\n\nGame is now playing round " << i+1 << "...\n";
        dealer.rollDice();

        for (int j = 0; j < howmanyplayers; j++) {
            Players[j].makeGuess();
        }
        roundResult(dealer, Players, howmanyplayers);
    }
    disPlayOverall(Players, howmanyplayers);

    delete [] Players;
    Players = NULL;

    cout << "\nPress [R] to replay game.\n"
    << "Press any other key to quit.\n"
    << ">> ";
    cin >> reload;

    if (reload == 'r' || reload == 'R') {
        cout << "Reloading game...\n";
        cout << "\n_____________________________________________________\n";
        main();
    }
    cout << "Thank you for playing!\n";
    return 0;
}

void roundResult(Dealer &dealer, Player *players, int size) {
    cout << "\nDisplaying results...\n"
    << "Die 1: " << dealer.getdie1Val()
    << "\nDie 2: " << dealer.getdie2Val()
    << "\nCho or Han: " << dealer.getChoOrHan()
    << "\n\nPlayers' guesses...\n";

    for (int i=0; i<size; i++) {
        getGuesses(dealer, players[i]);
    }
    cout << "\n_____________________________________________________\n";
}

void getGuesses(Dealer &dealer, Player &player) {
    const int point = 1;
    string guess = player.getGuess(), ChoOrHan = dealer.getChoOrHan();

    cout << player.getName() << " guessed " << player.getGuess() << endl;

    if (guess == ChoOrHan){
        cout << "[Awarding points to " << player.getName() << "]\n\n";
        player.addPoints(point);
    }
}

void disPlayOverall(Player *players, int size) {
    string winner;
    int top1 = 0, sum = 0;

    cout << "\n\nDisplaying overall results...\n";

    for (int i=0; i<size; i++) {
        cout << players[i].getName() << "'s points: " << players[i].getPoints() << "\n";
    }
    cout << "\nThe overall winner is ";

    for (int i=0; i<size; i++) {
        if (players[i].getPoints() > top1) {
            top1 = players[i].getPoints();
            winner = players[i].getName();
        }
        else if (players[i].getPoints() == top1) {
            top1 = players[i].getPoints();
            winner += " and " + players[i].getName();
        }
    }

    for (int i=0; i<size; i++) {
        sum += players[i].getPoints();
    }

    if (sum == 0) {
        cout << "none, no one scored a point.\n";
    }
    else {
        cout << winner << ". Congrats!\n";
    }
}
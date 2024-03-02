#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

int main() {
    int ynum, tries = 1, cnum, best = 100;
    std::string Player, pname;
    
    srand((unsigned) time(0));
    cnum = (rand() % 100) + 1;

    std::ifstream input("./GTN_Best.txt");
    input >> best;
    input >> Player;
    std::ofstream output("./GTN_Best.txt");

    std::cout << "Welcome to guess the number.\nGuess a number between 1 and 100, and I will tell you if your number is too high, or too low.\nYou only have 10 guesses so don't waste them!\n";
    
    if (best < 100 && best > 0) {
        std::cout << "Current high score is " << best << " gotten by " << Player << "!\n";
    }
    else {
        std::cout << "The current high score is 100 by default.\nCan you get better then that?\n";
        best = 100;
    }

    std::cout << "I have a number.\n";
    wrong:
    std::cin >> ynum;
    if (ynum > 0 && ynum < 101) {
        if (ynum == cnum) {
            std::cout << "You got it!\nIt took you " << tries << " tries!\n";
        }
        else if (ynum > cnum) {
            std::cout << "Sorry, too high!\nHere, try again.\n";
            tries++;
            goto wrong;    
        }
        else if ( ynum < cnum) {
            std::cout << "Sorry, too low!\nHere, try again.\n";
            tries++;
            goto wrong;
        }

        if (ynum == 69) {
            std::cout << "Nice\n";
        }
        else if (tries < best) {
            best = tries; 
            std::cout << "Congrats!!!\nNew best score!\nPut in your name to save it!\n";
            std::cin >> pname;

            Player = pname;
            std::cout << "Name saved as " << Player << "!\n";
            output << best << std::endl;
            output << Player << std::endl;
            system("Pause");
        }
        else if (tries == best) {
            std::cout << "Wow!\nYou tied with first place!\nBut you have to BEAT it to be considered a winner.\n";
            system("pause");
        }
        else if (tries > best) {
            std::cout << "The best score is " << best << ", acheived by " << Player << ". Try beating that!\n";
            system("pause");
        }
    }
    else {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Input error.\nTry again.\n";
        goto wrong;
    }
}
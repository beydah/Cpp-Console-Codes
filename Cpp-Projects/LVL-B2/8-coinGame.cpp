#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void output(int screen) {
    if (screen == 0) {
        cout <<
        "=====================================\n"
        "=   H E A D S -  O R  - T A I L S   =\n"
        "============== G A M E ==============\n"
        "=====================================\n"
        "= Author: Ilkay Beydah Saglam       =\n"
        "= Version: 0.0.1                    =\n"
        "= Copyright: Open Source            =\n"
        "= Description: a Small Concole Game =\n"
        "=====================================\n"
        "\nPress any key and enter to start: ";
    } else if (screen == 1) {
        cout << 
        "1- Start ($500)\n"
        "2- Exit\n"
        "\nEnter Your Choice: ";
    } else if (screen == 2) {
        cout << 
        "\n"
        "=====================\n"
        "= G A M E - O V E R =\n"
        "=====================\n"
        "\n";
    }
}

void wrongOutput(int choiceLen) {
    cout << "\nWrong Choice\n";
    
    if (choiceLen < 2) {
        cout << "Remaining chances: " << 3 - choiceLen << '\n';
    } else if (choiceLen < 3) {
        cout << "ITS LAST CHANCE\n";
    } else {
        cout << "You Have Lost Your Chance\n";
    }
}

void screenClear() {
    cout << "\x1B[2J\x1B[H";    
}

int choiceFinder(int choice) {
    if (choice < 1 || choice > 2) {
        return 404;
    } else {
        return choice;
    }
}

string randomZar() {
    int num = (rand() % 2) + 1;
    
    if(num == 1)
    {
    	return "Heads";
	}
	
	else
	{
		return "Tails";
	}
}

int main() {
    /*RANDOM VARIABLE*/
    string slot1, slot2, slot3;

    /*MAIN VARIABLE*/
    int choice, choiceLen = 0;
    string anyKey;

    /*GAME VARIABLE*/
    int dolar = 10000;
    int buy = 500;

    output(0);
    cin >> anyKey;

    screenClear();

    do {
        //MAIN SCREEN
        cout << "\nYour Money: $" << dolar << "\n\n";
        output(1);

        cin >> choice;
        choice = choiceFinder(choice);

        screenClear();

        if (choice == 404) {
            wrongOutput(choiceLen);
            if (choiceLen > 2) {
                choice = 2;
            }
            choiceLen++;
        }
        
        //GAME SCREEN
        else if (choice == 1) {
            if (dolar < 500) {
                cout << "You Don't Have Enough Money.\n";
            } else {
                choiceLen = 0;

                /*Random Ataması*/
                srand(time(0));

                slot1 = randomZar();
                slot2 = randomZar();
                slot3 = randomZar();

                cout << "Slots: " << slot1 << " - " << slot2 << " - "  << slot3 << '\n';

                if (slot1 == "Tails" && slot2 == "Tails" && slot3 == "Tails" || slot1 == "Heads" && slot2 == "Heads" && slot3 == "Heads") {
                    cout << "WIN! WIN! WIN!\n";
                    dolar += 1000;
                } else {
                    cout << "You Lose.\n";
                    dolar -= buy;
                }
            }
        }
    } while (choice != 2);
    output(2);

    return 0;
}

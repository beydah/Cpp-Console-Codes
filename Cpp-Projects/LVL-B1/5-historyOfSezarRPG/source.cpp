#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

void screenOut(int screen) {
    if (screen == 0) {
        cout <<
            "===========================================\n"
            "====== B R A I N    -    T E A S E R ======\n"
            "=========       G  A  M  E       ==========\n"
            "===========================================\n"
            "= Author: Ilkay Beydah Saglam             =\n"
            "= Version: 0.0.1                          =\n"
            "= Copyright: Open Source                  =\n"
            "= Description: a Small Console Game       =\n"
            "===========================================\n";
    } else if (screen == 1) {
        cout <<
            "\nMAIN SCREEN\n"
            "1 - START\n"
            "0 - EXIT\n"
            "Enter Your Choice: ";
    } else if (screen == 2) {
        cout <<
            "======================\n"
            "=                    =\n"
            "=  G A M E - O V E R =\n"
            "=                    =\n"
            "======================\n";
    } else {
        cout << "\nPress Any Key To Go Back: ";
    }
}

void clearScreen() {
    system("cls");
}

/*
DOSYA OKUMA TAMAMLANDI
TASLAK PROGRAM HAZIRLANDI

MAIN SCREEN TAMAMLANACAK
GAME SCREEN TAMAMLANACAK
*/

int main() {
    // MAIN AND GAME VARIABLES
    int i, j;

    // FILE VARIABLES
    ifstream file("data.csv");

    if (!file.is_open()) {
        cout << "Error: File Open" << '\n';
        return 1;
    }

    string scenario[50];

    i = 0;
    while (file.good() && i < 7) {
        getline(file, scenario[i], '\n');
        i++;
    }

    file.close();

    // MAIN SCREEN
    screenOut(0);
    screenOut(1);

    // GAME SCREEN
    while (true) {
        for (i = 0; i < 7; i++) {
            cout << scenario[i] << '\n';
            if ((i + 1) % 2 == 0) {
                cin >> j;
            }
        }

        screenOut(2);

        char choice;
        cin >> choice;

        if (choice == '0') {
            break;
        } else {
            clearScreen();
            screenOut(1);
        }
    }

    return 0;
}


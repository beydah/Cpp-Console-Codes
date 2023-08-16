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

/*BASIT MATEMATIK QUIZI*/

/*FONKSIYON 1*/

/*FONKSIYON 2*/

/*FONKSIYON 3*/

/*FONKSIYON 4*/

/*FONKSIYON 5*/

int main()
{
	/*RANDOM VARIABLE*/
	/*RANDOM İŞLEMLERİ*/
	
	/*MAIN VARIABLE*/
	/*MAIN İŞLEMLERİ*/
	
	/*QUİZ VARİABLE*/
	/*QUİZ İŞLEMLERİ*/
	
	do
	{
		/*MAIN SCREEN*/
		do
		{
			
		}
		while(0);
		
		/*QUIZ SCREEN*/
		while(0)
		{
			
		}
		
		/*SETTINGS SCREEN*/
		while(0)
		{
			
		}
	}
	while(0);
	
	/*EXIT SCREEN*/
	
	return 0;
}

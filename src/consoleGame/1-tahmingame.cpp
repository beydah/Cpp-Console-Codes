#include <iostream>
#include <cstdlib>
using namespace std;

//Number Guessing Game

int main()
{
	cout <<
		"=============================\n"
		"= G U E S S I N G - G A M E =\n"
		"=============================\n"
		"= Author: Beydah Saglam     =\n"
		"= Version: 0.0.1            =\n"
		"= Copyright: Open Source    =\n"
		"= Description: Number Guess =\n"
		"=============================\n";
	
	//MAIN VERIABLE
	int choice, choiceLen = 0;
	
	//GAME VERIABLE
	int pcscore = 0, hescore = 0;
	int guess, i, chance = 6;
	int randomNumber, max, min;
	bool win = 0;
	
	do
	{
		//MAIN ALGORITHM
		do
		{
			cout << "\n1-START\n2-SETTINGS\n0-EXIT\nChoice: ";
			cin >> choice;
			
			if(choice < 0 || choice > 2 && choiceLen < 2)
			{
				cout << "Wrong choice. Begin again...\n";
				choiceLen++;
			}
			
			else if(choice < 0 || choice > 2 && choiceLen < 3)
			{
				cout << "You have last chance...\n";
				choiceLen++;
			}
			
			else if(choice < 0 || choice > 2 && choiceLen < 4)
			{
				cout << "You are lost your chance.\n";
				choice = 0;
			}
		}
		while(choice < 0 || choice > 2);
		choiceLen = 0;
		
		//GAME ALGORITM
		while(choice == 1)
		{
			cout << "\nSCORE BOARD: PC - " << pcscore << " SAPIENS - " << hescore << "\n";
			
			do
			{
				cout << "\n1-Keep in Mind\n2-Guess\n3-Go Back\n";
				if(pcscore > hescore)
				{
					cout << 
					"\nIf the game is getting difficult,"
					"\nyou can change the difficulty from the settings.\n";
				}
				cout << "\nChoice: ";
				cin >> choice;
			
				if(choice < 1 || choice > 3 && choiceLen < 1)
				{
					cout << "Wrong choice. Begin again...\n";
				}
				else if(choice < 1 || choice > 3 && choiceLen < 2)
				{
					cout << "You have last chance...\n";
				}
				else if(choice < 1 || choice > 3 && choiceLen < 3)
				{
					cout << "You are lost your chance.\n";
				}
				
				choiceLen++;
			}
			while(choice < 1 || choice > 3 && choiceLen < 3);
			choiceLen = 0;
			
			//Aklýnda Tut
			if(choice == 1)
			{
				do
				{
					cout << "\nThink of a number between 1 - 100. \nHave you got it?\n1-Yes Choice: ";
					cin >> choice;
			
					if(choice < 1 && choiceLen < 1)
					{
						cout << "Wrong choice. Begin again...\n";
					}
			
					else if(choice < 1 && choiceLen < 2)
					{
						cout << "You have last chance...\n";
					}
			
					else if(choice < 1 && choiceLen < 3)
					{
						cout << "You are lost your chance.\n";
					}
				
					choiceLen++;
				}
				while(choice < 1 && choiceLen < 3);
				choiceLen = 0;
				
				if(choice == 1)
				{
					cout << "\nThen lets get started\n";
					max = 100;
					min = 1;
					
					for(i = 1; i <= 6; i++)
					{
						guess = (max + min) / 2;
						
						do
						{
							cout << "\nYour Number is: " << guess << "?\n1-Yes 2-No Choice: ";
							cin >> choice;
						}
						while(choice < 1 || choice > 2);
						
						if(choice == 1)
						{
							win = 1;
							break;
						}
						
						else if(choice != 1 && i < 6)
						{
							do
							{
								cout << 
								"\nOK. Your number is bigger than " << guess << "?\n"
								"1-Yes 2-No Choise: ";
								cin >> choice;
							}
							while(choice < 1 || choice > 2);
							
							if(choice == 1)
							{
								min = guess;
							}
							else
							{
								max = guess;
							}
						}
					}
					
					if(win == 1)
					{
						cout << "\nI am win. I always win!\n";
						pcscore++;
						win = 0;
					}
					else
					{
						cout << "\nI dont find it.\nYou are win.\n";
						hescore++;
					}
					cout << "\n";
				}
				
				choice = 1;
			}
			
			//Tahmin Et
			else if(choice == 2)
			{
				randomNumber = 1 + (rand() % 100);
				cout << "\nI have a number in my mind between 1 - 100.";
				
				for(i = 1; i <= chance; i++)
				{
					if(i == 1)
					{
						cout << "\nMake your first guess: ";
					}
					else if(i < 5)
					{
						cout << "\nMake your " << i << ". guess: ";
					}
					else
					{
						cout << "\nIts your last chance.\nMake your last guess: ";
					}
					
					cin >> guess;
					
					if(guess == randomNumber)
					{
						win = 1;
						break;
					}
					else if(guess < randomNumber && i != 5)
					{
						cout << "Enter more bigger guess.\n";
					}
					else if(guess > randomNumber && i != 5)
					{
						cout << "Enter more smaller guess.\n";
					}
				}
				
				if(win == 1)
				{
					cout << "Conguralitions! You Won.\n";
					hescore++;
					win = 0;
				}
				else
				{
					cout << "You are lost. My num is: " << randomNumber;
					pcscore++;
				}
				
				cout << "\n";
				choice = 1;
			}
		}
		choiceLen = 0;
		
		//SETTINGS ALGORTIHM
		while(choice == 2)
		{
			do
			{
				cout << "\n1-Guessing Ease Setting\n2-Go Back\nChoice: ";
				cin >> choice;
			
				if(choice < 1 || choice > 2 && choiceLen < 1)
				{
					cout << "Wrong choice. Begin again...\n";
				}
				else if(choice < 1 || choice > 2 && choiceLen < 2)
				{
					cout << "You have last chance...\n";
				}
				else if(choice < 1 || choice > 2 && choiceLen < 3)
				{
					cout << "You are lost your chance.\n";
				}
				
				choiceLen++;
			}
			while(choice < 1 || choice > 2 && choiceLen < 3);
			choiceLen = 0;
			
			//Guessing Ease Setting
			if(choice == 1)
			{
				cout << "\nDefault Level: 6\nEnter New Difficulty Level:";
				cin >> chance;
				
				choice = 2;
			}
			else
			{
				choice = 3;
			}
		}
		choiceLen = 0;
	}
	while(choice != 0);
	
	cout << "Game Over";
	return 0;
}

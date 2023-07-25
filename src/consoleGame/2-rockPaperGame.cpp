#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int mainChoiceFinder(int choice)
{
	if(choice < 0 || choice > 1)
	{
		return 2;
	}
	
	else if(choice == 1)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}

int gameChoiceFinder(int choice)
{
	if(choice < 1 || choice > 3)
	{
		return 4;
	}
	else 
	{
		return choice;
	}
}

int gameWinner(int heChoice)
{
	unsigned int seed = static_cast<unsigned int>(time(NULL));
	srand(seed);
	int pcChoice = rand() % 3 + 1;
	cout << "My symbol is: " << pcChoice;
	
	if(heChoice == 1)
	{
		if(pcChoice == 1)
		{
			return 3;
		}
		
		else if(pcChoice == 2)
		{
			return 2;
		}
		
		else//MAKAS
		{
			return 1;
		}
	}
	
	else if(heChoice == 2)
	{
		if(pcChoice == 1)
		{
			return 1;
		}
		
		else if(pcChoice == 2)
		{
			return 3;
		}
		
		else
		{
			return 2;
		}
	}
	
	else //MAKAS
	{
		if(pcChoice == 1)
		{
			return 2;
		}
		
		else if(pcChoice == 2)
		{
			return 1;
		}
		
		else
		{
			return 3;
		}
	}
}

void wrongChoiceOutput(int choiceLen)
{
	if(choiceLen < 3)
	{
		cout << "\nWrong choice. Begin again...\n";
	}
	
	else if(choiceLen < 4)
	{
		cout << "\nYou have last chance!\n";
	}
	
	else
	{
		cout << "\nYou are lost your chance.\n";
	}
}

int main()
{
	cout <<
		"===========================================\n"
		"= R O C K - P A P E R - S C R I S S O R S =\n"
		"==============  G  A  M  E  ===============\n"
		"===========================================\n"
		"= Author: Ilkay Beydah Saglam             =\n"
		"= Version: 0.0.1                          =\n"
		"= Copyright: Open Source                  =\n"
		"= Description: a Small Concole Game       =\n"
		"===========================================\n";
		
	//MAIN VARIABLE
	int input, choice, choiceLen = 1;
	
	//GAME VARIABLE
	int gameInput, gameChoice, heWin, pcscore = 0, hescore = 0;
	
	do
	{
		do
		{
			cout << "\n1- START\n0- EXIT\nEnter Your Choice: ";
			cin >> input;
			
			choice = mainChoiceFinder(input);
			if(choice == 2)
			{
				wrongChoiceOutput(choiceLen);
				if(choiceLen > 3)
				{
					choice = 0;
				}
				choiceLen++;
			}
		}
		while(choice == 2); //MAIN SCREEN ALGORITHM
		choiceLen = 1;
		
		while(choice == 1) //GAME SCREEN ALGORITHM
		{
			cout << "\nScoreboard: PC - " << pcscore << " SAPIENS - " << hescore << "\n";
			
			do
			{
				cout << "\n1- Start the game\n0- Go back\nEnter Your Choice: ";
				cin >> input;
			
				choice = mainChoiceFinder(input);
				if(choice == 2)
				{
					wrongChoiceOutput(choiceLen);
					if(choiceLen > 3)
					{
						choice = 3;
						cout << "Returned the main screen.\n";
					}
				choiceLen++;
				}
			}
			while(choice == 2);
			choiceLen = 1;
			
			if(choice == 1)
			{
				do
				{
					cout << "\n1- Rock or 2- Paper or 3- Scrissors\nEnter your symbol: ";
					cin >> gameInput;
					
					gameChoice = gameChoiceFinder(gameInput);
					
					if(gameChoice == 4)
					{
						wrongChoiceOutput(choiceLen);
						if(choiceLen > 3)
						{
							gameChoice = 5;
							cout << "Returned the game screen.\n";
						}
						choiceLen++;
					}
				}
				while(gameChoice == 4);
				choiceLen = 1;
				
				if(gameChoice < 4)
				{
					heWin = gameWinner(gameChoice);
					
					if(heWin == 1)
					{
						cout << "\nCongralations! You won.";
						hescore++;
					}
					
					else if(heWin == 2)
					{
						cout << "\nI won!\n";
						pcscore++;
					}
					
					else
					{
						cout << "\nIts Draw";
					}
				}
			}
			
			else if(choice == 0)
			{
				choice = 3;
			}
		}
	}
	while(choice != 0);
	
	cout << "Game Over.\n";
	return 0;
}

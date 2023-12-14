#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*BASIT MATEMATIK QUIZI*/

void output(int screen) 
{
    if (screen == 0) {
        cout <<
        "=====================================\n"
        "=    M A T H - Q U I Z - G A M E    =\n"
        "=====================================\n"
        "= Author: Ilkay Beydah Saglam       =\n"
        "= Version: 0.0.1                    =\n"
        "= Copyright: Open Source            =\n"
        "= Description: a Small Concole Game =\n"
        "=====================================\n"
        "\nPress any key and enter to start: ";
    } 
	
	else if (screen == 1) 
	{
        cout <<
        "\nMain Screen\n"
        "1- Start\n"
        "2- Setting\n"
        "0- Exit\n"
        "\nEnter Your Choice: ";
    } 
	
	else if (screen == 2) 
	{
        cout << 
        "\n"
        "=====================\n"
        "= G A M E - O V E R =\n"
        "=====================\n"
        "\n";
    }
    
    else
	{
        cout <<
        "\nSetting Screen\n"
        "1- Set Difficulty\n"
        "0- Back\n"
        "\nEnter Your Choice: ";
    }
}

void wrongOutput(int choiceLen) 
{
    cout << "\nWrong Choice\n";
    
    if (choiceLen < 2) {
        cout << "Remaining chances: " << 3 - choiceLen << '\n';
    } else if (choiceLen < 3) {
        cout << "ITS LAST CHANCE\n";
    } else {
        cout << "You Have Lost Your Chance\n";
    }
}

void screenClear() 
{
    cout << "\x1B[2J\x1B[H";    
}

int choiceFinder(int choice, int maxChoice) 
{
    if (choice < 0 || choice > maxChoice) 
	{
        return 404;
    } 
	else
	{
        return choice;
    }
}

int randomNum(int input) 
{
	int num;
	
	if(input == 0)
	{
		return num = (rand() % 3) + 1;
	}
	
	else if(input == 1)
	{
		return num = (rand() % 8) + 2;
	}
	
	else if(input == 2)
	{
		return num = (rand() % 88) + 12;
	}
	
	else
	{
		return num = (rand() % 98) + 102;
	}
}

int main()
{
	/*MAIN VARIABLE*/
	int input, choice;
	int maxChoice;
	int choiceLen = 0;
	string anyKey;
	
	/*QUIZ VARIABLE*/
	int trueAnswer;
	int inputAnswer;
	int num1, num2, symbol;
	int score = 0;
	int question;
	
	/*SETTING VARIABLE*/
	int difficulty = 1;
	
	output(0);
	cin >> anyKey;
	screenClear();
	
	do
	{
		maxChoice = 2;
		question = 1;
		
		/*MAIN SCREEN*/
		do
		{
			output(1);
			cin >> input;
			choice = choiceFinder(input, maxChoice);
			
			screenClear();
			
			if(choice == 404)
			{
				wrongOutput(choiceLen);
				if(choiceLen == 3)
				{
					choice = 0;
				}
				choiceLen++;
			}
		}
		while(choice == 404);
		choiceLen = 0;
		
		screenClear();
		
		/*QUIZ SCREEN*/
		while(choice == 1)
		{
			num1 = randomNum(difficulty);
			symbol = randomNum(0);
			num2 = randomNum(difficulty);
			
			cout << "Score: " << score << '\n';
			
			if(question > 10)
			{
				screenClear();
				cout << "Congralations! Your Score: " << score << " - Your Correct Answer: " << score / 5 << '\n';
				break;
			}
			
			else
			{
				if(symbol == 1)
				{
					trueAnswer = num1 + num2;
					
					cout << "\nQuestion " << question << ":\n" << num1 << " + " << num2 << " = ?\n";
					cout << "Enter Correct Answer: ";
				}
			
				else if(symbol == 2)
				{
					trueAnswer = num1 - num2;
					
					cout << "\nQuestion " << question << ":\n" << num1 << " - " << num2 << " = ?\n";
					cout << "Enter Correct Answer: ";
				}
			
				else
				{
					trueAnswer = num1 * num2;	
					
					cout << "\nQuestion " << question << ":\n" << num1 << " x " << num2 << " = ?\n";
					cout << "\nEnter Correct Answer: ";
				}
				
				cin >> inputAnswer;
				screenClear();
				
				if(inputAnswer == trueAnswer)
				{
					cout << "\nCorrect! It was\n";
					score += 5;
				}
				
				else
				{
					cout << "\nWrong. It wasnt\n";
				}
				
				question++;
			}
		}
		choiceLen = 0;
		
		screenClear();
		
		/*SETTINGS SCREEN*/
		while(choice == 2 || choice == 404)
		{
			output(3);
			cin >> input;

			maxChoice = 1;
			choice = choiceFinder(input, maxChoice);

			screenClear();
			
			if(choice == 404)
			{
				wrongOutput(choiceLen);
				if(choiceLen == 3)
				{
					choice = 505;
				}
				choiceLen++;
			}
			
			else if(choice == 1)
			{
				cout << "\nLevel Difficulty Screen\nEnter New Difficulty Level (Between 1 - 3): ";
				
				cin >> input;

				maxChoice = 3;
				choice = choiceFinder(input, maxChoice);

				screenClear();
			
				if(choice == 404 || choice == 0)
				{
					cout << "\nWrong Choice\n";
					choice = 2;
				}
				
				else
				{
					difficulty = choice;
					cout << "\nNew Difficulty Level: " << difficulty << '\n';
					choice = 2;
				}
			}
			
			else
			{
				choice = 505;
			}
		}
		choiceLen = 0;
	}
	while(choice != 0);
	
	screenClear();
	output(2);
	
	return 0;
}

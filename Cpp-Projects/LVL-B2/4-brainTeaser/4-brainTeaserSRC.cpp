#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

void clearScreen()
{
    system("cls");
}

void output(int screen)
{
	if(screen == 0)
	{
		cout <<
		"===========================================\n"
		"====== B R A I N    -    T E A S E R ======\n"
		"=========       G  A  M  E       ==========\n"
		"===========================================\n"
		"= Author: Ilkay Beydah Saglam             =\n"
		"= Version: 0.0.1                          =\n"
		"= Copyright: Open Source                  =\n"
		"= Description: a Small Concole Game       =\n"
		"===========================================\n";
	}
	
	else if(screen == 1)
	{
		cout <<
		"\nMAIN SCREEN\n"
		"1 - START\n"
		"0 - EXIT\n"
		"Enter Your Choice: ";
	}
	
	else //EXIT SCREEN
	{
		cout <<
		"======================\n"
		"=                    =\n"
		"=  G A M E - O V E R =\n"
		"=                    =\n"
		"======================\n";
	}
}

void wrongOutput(int choiceLen)
{
	if(choiceLen < 3)
	{
		cout << "\nWrong Choice. Begin Again..\n";
	}
	
	else
	{
		cout << "\nYou have last chance!\n";
	}
}

int choiceFinder(int choice)
{
	if(choice < 0 || choice > 1)
	{
		return 404;
	}
	
	else
	{
		return choice;
	}
}

int main()
{
	output(0);
	
	//MAIN VERIABLES
	int input, choice, choiceLen;
	
	//GAME VERIABLES
	string guess;
	int known, unknown;
	
	int i, j;
	
	//FILE Reading
	ifstream file("brainTeaserXL.csv");
	
	if(!file.is_open()) 
	{
		cout << "Error: File Open" << '\n';
		return 1;
	}
	
	string questions[50];
	string answers1[50];
	string answers2[50];
	string trueAnswers[50];
	string subjects[50];	
	string unknownSubjects[50];
	
	i = 0;
	while(file.good() && i < 50)
	{
		getline(file,questions[i],';');
		getline(file,answers1[i],';');
		getline(file,answers2[i],';');
		getline(file,trueAnswers[i],';');
		getline(file,subjects[i],'\n');
		
		i++;
	}
	
	file.close();
	
	//MIX The Questions
	int randomSort[50];
	int temp, random;
	
	for(i = 0; i < 50; i++)
	{
		randomSort[i] = i + 1;
	}
	
	srand(static_cast<unsigned int>(time(0)));

	for(i = 0; i < 50; i++)
	{
		random = 1 + rand() % (50 - i);
		
		temp = randomSort[i];
		randomSort[i] = randomSort[random];
		randomSort[random] = temp;
	}
	
	do
	{
		//FIRST EQUALS
		choiceLen = 1, known = 0, unknown = 50 - known;
		
		//MAIN SCREEN
		do
		{
			output(1);
			cin >> input;
			choice = choiceFinder(input);
			
			if(choice == 404)
			{
				wrongOutput(choiceLen);
				
				if(choiceLen > 3)
				{
					choice = 0;
				}
				
				choiceLen++;
			}
		}
		while(choice == 404);
		choiceLen = 1;
		
		clearScreen();
		
		//GAME SCREEN
		while(choice == 1)
		{
			j = 0;
			for(i = 0; i < 50; i++)
			{
				unknown = 50 - known;
				cout << 
				"\nKnown: " << known << " - Unknown: " << unknown << "\n"
				"Last " << 50 - i << " Question. (Exit: W)\n";
				
				cout << "\n" << i + 1 << ". Question\n";
				
				cout << questions[randomSort[i]] << '\n';
				cout << answers1[randomSort[i]] << '\n';
				cout << answers2[randomSort[i]] << '\n';
				
				cout << "\nEnter Correct Option: ";
				cin >> guess;
				
				guess = toupper(guess[0]);
				
				if(guess == "W")
				{
					clearScreen();
					break;
				}
				
				if(guess == trueAnswers[randomSort[i]])
				{
					known++;
				}
				
				else
				{
					unknownSubjects[j] = subjects[randomSort[i]];
					j++;
				}
				
				clearScreen();	
			}
			
			unknown = 50 - known;
			cout << 
			"\nKnown: " << known << " - Unknown: " << unknown << "\n";
			
			cout << "Repeat This Subject\n";
			for(i = 0; i < j; i++)
			{
				cout << i+1 << ". " << unknownSubjects[i] << '\n';
			}
			
			cout << "\nPress Any Key To Go Back: ";
			cin >> guess;
			choice = 2;
			clearScreen();
		}
	}
	while(choice != 0);
	
	output(2);
	return 0;
}

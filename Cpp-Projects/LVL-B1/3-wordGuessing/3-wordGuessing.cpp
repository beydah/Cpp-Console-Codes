#include <iostream>
#include <fstream>

#include <string>
#include <vector>

#include <cstdlib>
#include <ctime>


#include <algorithm>
using namespace std;


int choiceFinder(int input, int screen)
{
	if(screen == 1)
	{
		//MAIN CHOICE FINDER
		if(input < 0 || input > 1)
		{
			return 404;
		}
		
		else
		{
			return input;
		}
	}
	
	else
	{
		//GAME CHOICE FINDER
		if(input < 0 || input > 1)
		{
			return 404;
		}
		
		else
		{
			return input;
		}
	}
}

void wrongOutput(int choiceLen)
{
	if(choiceLen < 3)
	{
		cout << "\nWrong. Begin again...\n";
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

int mainScreen()
{
	return 0;
}

int gameScreen()
{
	return 0;	
}


int main()
{
	cout <<
		"===========================================\n"
		"=  W  O  R  D  -  G  U  E  S  S  I  N  G  =\n"
		"=============   G  A  M  E   ==============\n"
		"===========================================\n"
		"= Author: Ilkay Beydah Saglam             =\n"
		"= Version: 0.0.1                          =\n"
		"= Copyright: Open Source                  =\n"
		"= Description: a Small Concole Game       =\n"
		"===========================================\n";
	
	//FILE VERIABLES
	ifstream engWordsFile("3-engWords.txt");
	ifstream turkWordsFile("3-turkWords.txt");
	
	if (!engWordsFile || !turkWordsFile) 
	{
        cerr << "404 Not Found" << endl;
        return 1;
    }
    
	//VECTORS VERIABLES
    vector<string> engWordsArr;
	vector<string> turkWordsArr;
    string line;

    while (getline(engWordsFile, line)) 
	{
        engWordsArr.push_back(line);
    }	
	
	while(getline(turkWordsFile, line))
	{
		turkWordsArr.push_back(line);
	}
	
    engWordsFile.close();
    turkWordsFile.close();
    
    //RANDOM SORTING VERIABLES
    int i, randomSort;
    unsigned int seed;
	string temp;
	    
    //MAIN VARIABLE
    int input, choice, choiceLen = 1;
    
    //GAME VARIABLE
	int unknown;
	int known;
	string guess;
	
    for(i = 0; i < 100; i++)
    {
        seed = static_cast<unsigned int>(time(NULL));
    	srand(seed);
   		randomSort = rand() % 100 + 1;
    
    	temp = engWordsArr[i];
    	engWordsArr[i] = engWordsArr[randomSort];
    	engWordsArr[randomSort] = temp;
    	
    	temp = turkWordsArr[i];
    	turkWordsArr[i] = turkWordsArr[randomSort];
    	turkWordsArr[randomSort] = temp;
	}
    i = 0;
    
    do
    {
		do
		{
			cout << "\n1- START\n0- EXIT\nEnter Your Choice: ";
			cin >> input;
			
			choice = choiceFinder(input, 1);
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
		while(choice == 404); //MAIN SCREEN ALGORITHM
		choiceLen = 1;
		
		//GAME SCREEN
		while(choice == 1)
		{
			unknown = 100;
			known = 0;
			
			do
			{
				cout << "\n1- TR TO ENG GAME\n0- Go back\nEnter Your Choice: ";
				cin >> input;
			
				choice = choiceFinder(input, 2);
				if(choice == 404)
				{
					wrongOutput(choiceLen);
					if(choiceLen > 3)
					{
						choice = 3;
						cout << "Returned the main screen.\n";
					}
				choiceLen++;
				}
				
				else if(choice == 0)
				{
					choice = 3;
					cout << "Returned the main screen.\n";
				}
			}
			while(choice == 404);
			choiceLen = 1;
			
			if(i >= 100)
			{
				i = 0;
			}
			
			if(choice == 1)
			{
				for(; i < 100; i++) //EXIT 1601
				{
					cout << "\n" << i+1 << ". QUESTION" ;
					cout <<"\nin Turkish: " << turkWordsArr[i]; 
					
					string engWordWithStars = engWordsArr[i][0] + string(engWordsArr[i].length() - 1, '*');
        			cout << "\nin English: " << engWordWithStars;
					
					cout << "\nWhats Words in English: ";
					cin >> guess;
					
  				    transform(guess.begin(), guess.end(), guess.begin(), ::toupper);
        
					if(guess == engWordsArr[i])
					{
						cout << "\nTRUE\n";
						known++;
					}
					
					else
					{
						cout << "\nFALSE\nIt was " << engWordsArr[i] << endl;
					}
				}
				unknown = unknown - known;
				cout << "\nScore:\nKnown: " << known << " - Unknown: " << unknown << endl;
			}
		}
	}
	while(choice != 0);
    cout << "Game Over\n";
	return 0;
}

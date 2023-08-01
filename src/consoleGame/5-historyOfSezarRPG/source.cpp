#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

void screenOut(int screen)
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
	
	else if(screen == 2)
	{
		cout <<
		"======================\n"
		"=                    =\n"
		"=  G A M E - O V E R =\n"
		"=                    =\n"
		"======================\n";
	}
	
	else
	{
		cout << "\nPress Any Key To Go Back: ";
	}
}

void clearScreen()
{
    system("cls");
}

/*
DOSYA OKUMA TAMAMLANDI
TASLAK PROGRAM HAZIRLANDI

MAIN SCREEN TAMAMLANACAK
GAME SCREEN TAMAMLANACAK
*/

int main()
{
	//MAIN AND GAME VARIABLE
	int i, j;
	
	
	//FILE VERIABLE
	ifstream file("data.csv");
	
	if(!file.is_open()) 
	{
		cout << "Error: File Open" << '\n';
		return 1;
	}
	
	string scenario[50];
	
	i = 0;
	while(file.good() && i < 7)
	{
		getline(file,scenario[i],'\n');
		i++;
	}
	
	file.close();
	

	//MAIN SCREEN
	screenOut(0);
	screenOut(3);
	do
	{
		screenOut(1);
	}
	while(0);
	
	clearScreen();
	
	/*
	//GAME SCREEN
	while(0)
	{
		for(i = 0; i < 7; i++)
		{
			cout << scenario[i] << '\n';
			if((i + 1) % 2 == 0)
			{
				cin >> j;
			}
		}
		screenOut(3);	
	}
	*/
	
	clearScreen();
	screenOut(2);
	
	return 0;
}

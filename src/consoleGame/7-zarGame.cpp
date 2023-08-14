#include <iostream>
using namespace std;

/*ZAR ATMA OYUNU*/
/*Kullanıcının hedefi, 
kolu çevirdiğinde 1 ile 5 arasındaki üç zarın hepsinin 5 gelmesini sağlamaktır. 
Başlangıçta kullanıcının hesabında 1.000.000 dolar bulunmaktadır 
ve her kolu çevirdiğinde 500 dolar kaybetmektedir. 
Ancak, eğer kullanıcıya kolu çevirdiğinde üç zar da 5 gelirse, 
1000 dolar kazanma fırsatı elde eder. 
Bu oyun, şansa dayalı bir deneyimi mükemmel bir gerilimle birleştirerek, 
büyük ödülü yakalamak için heyecan dolu bir fırsat sunmaktadır*/

void output(int screen)
{
	if(screen == 0)
	{
		cout <<
		"=====================================\n"
		"=  W  I  N  -  W  I  N  -  W  I  N  =\n"
		"============== G A M E ==============\n"
		"=====================================\n"
		"= Author: Ilkay Beydah Saglam       =\n"
		"= Version: 0.0.1                    =\n"
		"= Copyright: Open Source            =\n"
		"= Description: a Small Concole Game =\n"
		"=====================================\n"
		"\nPress any key and enter to start: ";	
	}
	
	else if(screen == 1)
	{
		cout << 
		"1- Start ($500)\n"
		"2- Exit\n"
		"\nEnter Your Choice: ";
	}
	
	else if(screen == 3)
	{
		cout << 
		"\n"
		"=====================\n"
		"= G A M E - O V E R =\n"
		"=====================\n"
		"\n";
	}
}

void wrongOutput(int choiceLen)
{
	cout << "\nWrong Choice\n";
	
	if(choiceLen < 2)
	{
		cout << "Remaining chances: " << 3 - choiceLen << '\n';
	}
	
	else if(choiceLen < 3)
	{
		cout << "ITS LATS CHANCE\n";
	}
	
	else
	{
		cout << "You Are Lost Your Chance\n";
	}
}

void screenClear()
{
	cout << "\x1B[2J\x1B[H";	
}

int choiceFinder(int choice)
{
	if (choice < 1 || choice > 2)
	{
		return 404;
	}
	
	else
	{
		return choice;
	}
}

/*INT FONKSIYON 4 = RANDOM ATAMASI*/

int main()
{
	/*RANDOM VARIABLE*/
	/*random slot1, slot2, slot3*/
	
	/*MAIN VARIABLE*/
	int choice, choiceLen = 0;
	string anyKey;
	
	/*GAME VARİABLE*/
	int dolar = 1000000;
	int buy = 500;
	
	output(0);
	cin >> anyKey;
	
	screenClear();
	
	do
	{
		//MAIN SCREEN
		cout << "\nYour Money: $" << dolar << "\n\n";
		output(1);
		
		cin >> choice;
		choice = choiceFinder(choice);
		
		screenClear();
		
		if(choice == 404)
		{
			wrongOutput(choiceLen);
			if(choiceLen > 2)
			{
				choice = 2;
			}
			choiceLen++;
		}
		
		//GAME SCREEN
		else if(choice == 1)
		{
			choiceLen = 0;
			dolar -= buy;
		}
	}
	while(choice != 2);
	output(3);
	
	return 0;
}

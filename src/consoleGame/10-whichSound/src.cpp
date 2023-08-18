#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

/*--------------------------------------------------*/
/*FONKSIYONLAR*/

void screenClear()
{
	system("cls");
}

void output(int outputScreen)
{
	if(outputScreen == 1)
	{
		cout << 
		"\n"
		"==================================\n"
		"= N O T A - G U E S S  - G A M E =\n"
		"==================================\n"
		"= Description: Test your musical =\n"
		"= ability by listening to melody =\n"
		"= notes, answer questions, and   =\n"
		"= identify which note it is!     =\n"
		"==================================\n"
		"= Developer: Ilkay Beydah Saglam =\n"
		"= Music: Jaz_the_MAN_2           =\n"
		"= Copyright: Open Source         =\n"
		"==================================\n"
		"\n"
		"\nPress Any Key For Skip: ";
	}
	
	else if(outputScreen == 2)
	{
		cout <<
		"\n"
		"==================================\n"
		"=       M A I N  -  M E N U      =\n"
		"==================================\n"
		"= 1 - START THE GAME             =\n"
		"= 0 - EXIT THE GAME              =\n"
		"==================================\n"
		"\n"
		"\nEnter Your Choice: ";
	}
	
	else
	{
		cout <<
		"\n"
		"==================================\n"
		"=                                =\n"
		"=      G A M E   -   O V E R     =\n"
		"=                                =\n"
		"==================================\n"
		"\n";
	}
}

void wrongOutput(int choiceLen)
{
	cout <<
	"==================================\n"
	"=   W R O N G  -  C H O I C E    =\n"
	"==================================\n";
	
	if(choiceLen < 2)
	{
		cout << "= Remaing Chances: " << 3 - choiceLen << "             =\n";
	}
	
	else
	{
		cout << "= ITS LAST CHANCE!               =\n";
	}
	
	cout << 
	"==================================\n";
}

int choiceFinder(int input, int min, int max)
{
	if(input < min || input > max)
	{
		return 404;
	}
	
	else
	{
		return input;
	}
}

int main()
{
	/*--------------------------------------------------*/
	/*PRIVATE FILE VARIABLE*/
	string komut;
	string uzanti = ".wav";
	
	string notalar[7] = {"do","re","mi","fa","sol","la","si"};
	
	#ifdef _WIN32
    komut = "powershell -c (New-Object Media.SoundPlayer 'sounds\\" + notalar[0] + "').PlaySync()";
    #elif __linux__
    komut = "aplay sounds/" + notalar[0];
    #endif
	
	int iMix[] = {0, 1, 2, 3, 4, 5, 6};
	int iMixNumber = sizeof(iMix) / sizeof(iMix[0]); 
	
	/*PRIVATE MAIN VARIABLE*/
	int input;
	int choice;
	int choiceLen;
	
	/*PRIVATE GAME VARIABLE*/
	string gameChoice;
	int knowing = 0;
	int unknowing = 0;
	
	/*--------------------------------------------------*/
	
	output(1);
	cin >> input;
	
	do
	{
		/*--------------------------------------------------*/
		/*MAIN SCREEN*/
		choiceLen = 0;
		screenClear();
		
		do
		{
			output(2);
			cin >> input;
			
			choice = choiceFinder(input,0,1);
			
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
		
		/*--------------------------------------------------*/
		/*GAME SCREEN*/
		choiceLen = 0;
		screenClear();
		
		while(choice == 1)
		{
			cout <<
			"\n"
			"==================================\n"
			"=         N O T A L A R          =\n"
			"==================================\n";
			
			for (int i = 0; i < 7; ++i) 
			{
				if(i != 4)
				{
					cout << "= " << i+1 << ". Nota: " << notalar[i] << "                    =\n";
				}
	       		
	       		else
	       		{
	       			cout << "= " << i+1 << ". Nota: " << notalar[i] << "                   =\n";
				}
        
	    	    #ifdef _WIN32
    	    	komut = "powershell -c (New-Object Media.SoundPlayer 'sounds\\" + notalar[i] + uzanti + "').PlaySync()";
        		
				#elif __linux__
        		komut = "aplay sounds/" + notalar[i];
        		
				#endif

				system(komut.c_str());
 		   	}
 		   	
 		   	cout <<
			"==================================\n"
			"\nPress Any Key For Play: ";
			cin >> input;
			
			/*--------------------------------------------------*/
			screenClear();

			for(int i = 0; i < 5; i++)
			{
				srand(time(0));
    			random_shuffle(iMix, iMix + iMixNumber);
			}
			
			for(int i = 0; i < 7; i++)
			{
				cout << i+1 << ". Soru:\nBu Hangi Ses?\n";
				
				#ifdef _WIN32
    	    	komut = "powershell -c (New-Object Media.SoundPlayer 'sounds\\" + notalar[iMix[i]] + uzanti + "').PlaySync()";
        		
				#elif __linux__
        		komut = "aplay sounds/" + notalar[iMix[i]];
        		
				#endif
				
				system(komut.c_str());
				
				cout << "Dogru Cevabi Yaz: ";
				cin >> gameChoice;
				
				screenClear();
				
				if(gameChoice == notalar[iMix[i]])
				{
					knowing++;
				}
				
				else
				{
					unknowing++;
				}
				
				cout <<
				"==================================\n"
				"= S K O R - T A B L O S U        =\n"
				"= Bilinen: " << knowing << "                     =\n"
				"= Bilinemeyen: " << unknowing << "                 =\n"
				"==================================\n"
				"= Onceki Sorunun Cevabi: " << notalar[iMix[i]] << "     =\n"
				"==================================\n";
			}
			
			screenClear();
			
			if(knowing > unknowing)
			{
				cout <<
				"\n"
				"==================================\n"
				"=         Y O U  -  W I N        =\n"
				"==================================\n"
				"= Knowing: " << knowing << "                     =\n"
				"= Unknowing: " << unknowing << "                   =\n"
				"==================================\n";
			}
			
			else
			{
				cout <<
				"\n"
				"==================================\n"
				"=        Y O U  -  L O S E       =\n"
				"==================================\n"
				"= Knowing: " << knowing << "                     =\n"
				"= Unknowing: " << unknowing << "                   =\n"
				"==================================\n";
			}
			
			cout << 
			"= 1- Start Again                 =\n"
			"= 2- Go Back                     =\n"
			"==================================\n"
			"\nEnter Your Choice: ";
			
			cin >> input;
			choice = choiceFinder(input,1,2);
			
			knowing = 0;
			unknowing = 0;
			
			screenClear();
		}
		
		/*--------------------------------------------------*/
	}
	while(choice != 0);
	
	screenClear();
	output(5);
	
	return 0;
}

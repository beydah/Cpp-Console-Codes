#include <iostream>
using namespace std;

//decimal to hexadecimal

int main()
{
	int decNum, remainder, i;
	
	char symbol = ' ';
	string hexNum = "";
	string extraNum = "ABCDEF";
	
	cout << "Enter a Decimal Number: ";
	cin >> decNum;
	
	do
	{
		if(decNum < 0)
		{
			symbol = ' -';
			decNum *= -1;
		}
		
		remainder = decNum % 16;
		decNum /= 16;
		
		if(remainder < 10)
		{
			hexNum += (remainder + '0');
		}
		
		else
		{
			remainder -= 10;
			hexNum += extraNum[remainder];
		}
	}
	while(decNum != 0);
	
	cout << "Hexadecimal Number is:" << symbol;
	i = hexNum.size();
	for(; i >= 0; i--)
	{
		cout << hexNum[i];
	}
	
	return 0;
}

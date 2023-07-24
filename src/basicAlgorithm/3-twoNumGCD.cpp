#include <iostream>
using namespace std;

//A program that calculates the greatest common divisor of two numbers

int main()
{
	int num1, num2;
	int i = 2, gcd = 1;
	
	cout << "Enter a Number: ";
	cin >> num1;
	
	cout << "Enter an Another Number: ";
	cin >> num2;
	
	if(num1 <= 0 || num2 <= 0)
	{
		cout << "Error";
	}
	
	else
	{
		do
		{
			if(num1 % i == 0 && num2 % i == 0)
			{
				num1 /= i;
				num2 /= i;
				gcd *= i;
			}
			
			else
			{
				i++;
			}
		}
		while(i <= num1 && i <= num2);
		
		cout << "GCD is: " << gcd;
	}
	
	return 0;
}

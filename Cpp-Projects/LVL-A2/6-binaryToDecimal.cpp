#include <iostream>
#include <cmath>
using namespace std;

//Binary to Decimal

int main()
{
	string binaryNum;
	cout << "Enter a Binary Number: ";
	cin >> binaryNum;
	
	int decimalNum = 0;
	int size = binaryNum.size();
	
	for(int i = 0; i < size; i++)
	{
		if(binaryNum[i] == '1')
		{
			decimalNum += pow(2, size - i - 1);
		}
	}
	
	cout << "to Decimal: " << decimalNum << endl;
	
	return 0;
}

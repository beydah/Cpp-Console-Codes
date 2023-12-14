#include <iostream>
using namespace std;

//A program that determines the sizes (in bytes) of data types

int main()
{
	cout << "Size of bool: " << sizeof(bool) << " byte" << endl;
	cout << "Size of char: " << sizeof(char) << " byte" << endl;
	cout << "Size of string: " << sizeof(string) << " byte" << endl << endl;
	
	cout << "Size of short int: " << sizeof(short int) << " byte" << endl;
	cout << "Size of int: " << sizeof(int) << " byte" << endl;
	cout << "Size of long int: " << sizeof(long int) << " byte" << endl;
	cout << "Size of unsigned int: " << sizeof(unsigned int) << " byte" << endl << endl;
	
	cout << "Size of float: " << sizeof(float) << " byte" << endl;
	cout << "Size of double: " << sizeof(double) << " byte" << endl;
	cout << "Size of long double: " << sizeof(long double) << " byte" << endl << endl;
	                       
	return 0;              
}                       

#include <iostream>
using namespace std;

int main()
{
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	int i;
	
	i = sizeof(array) / sizeof(array[0]);
	cout << "Elements Number of Array: " << i;
	
	return 0;
}

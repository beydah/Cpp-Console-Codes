#include <iostream>
using namespace std;

int main()
{
	int array[] = {1,9,2,8,3,7,4,6,5};
	int size = sizeof(array) / sizeof(array[0]);
	int i = 0, max = array[i];
	
	for(; i < size; i++)
	{
		if(array[i] > max)
		{
			max = array[i];
		}
	}
	
	cout << "Max Number: " << max;
	
	return 0;
}

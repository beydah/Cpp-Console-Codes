#include <iostream>
using namespace std;

//A program that calculates the least common multiple of two numbers.

int main()
{
    int num1, num2;

    cout << "Enter a Number: ";
    cin >> num1;

    cout << "Enter an Another Number: ";
    cin >> num2;

    // Check if numbers are non-negative
    if (num1 <= 0 || num2 <= 0)
    {
        cout << "Error: Numbers should be positive integers.";
    }
    else
    {
        int max = (num1 > num2) ? num1 : num2;
        int lcm = max;

        while (true)
        {
            if (lcm % num1 == 0 && lcm % num2 == 0)
                break;
            lcm += max;
        }

        cout << "LCM is: " << lcm;
    }

    return 0;
}


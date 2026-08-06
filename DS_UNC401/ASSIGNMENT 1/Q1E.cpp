#include <iostream>
using namespace std;

void printName(int n)
{
    switch (n)
    {
        case 1: cout << "One"; break;
        case 2: cout << "Two"; break;
        case 3: cout << "Three"; break;
        case 4: cout << "Four"; break;
        case 5: cout << "Five"; break;
        case 6: cout << "Six"; break;
        case 7: cout << "Seven"; break;
        case 8: cout << "Eight"; break;
        case 9: cout << "Nine"; break;
        default: cout << "Invalid (must be 1-9)"; break;
    }
    cout << endl;
}

int main()
{
    int num;
    cout << "Enter a number (1-9): ";
    cin >> num;
    printName(num);
    return 0;
}

#include <iostream>
using namespace ::std;
const int BINARY_SIZE = 50;

void func()
{
    int n = 0;
    cin >> n;

    if (n != 0)
        func();

    else
        cout << "Positive elements are: ";

    if (n > 0) cout << n << " ";
}

void PrintElements(int* array, int size, int dec)
{

    if (dec > 0)
        cout << "Negative elements: ";
    else
        cout << "Positive elements: ";

    for (int i = 0; i < size; i++)
        if (array[i] * -(dec) > 0)
            cout << array[i] << " ";

    cout << "\n";

    if (dec < 0)
        return;

    PrintElements(array, size, -dec);
}

void ConvertIntToDec(int number, int* binary, int i)
{
    if (number <= 0)
    {
        for (int i = BINARY_SIZE - 1; i > -1; i--)
            if (binary[i] >= 0)
                cout << binary[i];

        return;
    }

    binary[i] = number % 2;
    i++;
    number /= 2;

    ConvertIntToDec(number, binary, i);
}
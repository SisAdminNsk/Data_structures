#include <iostream>
#include "ConvertDecToBinary.h"
using namespace ::std;

// 2.1) Ввести в рекурсивной функции с клавиатуры последовательность чисел заканчивающихся числом ноль, 
//и вывести на экран только положительные числа. Массив не использовать.

// 2.2) Дан массив ненулевых целых чисел из N элементов. Используя рекурсию, напечатать сначала все отрицательные, а потом – все положительные
// числа этой последовательности. Реализовать в одной функции, которая вызывается один раз.
  
// 2.3) Написать рекурсивную функцию для перевода числа из десятичной системы счисления в двоичную.

const int SIZE = 10;

void func();
void PrintElements(int* array,int size,int dec);
void ConvertIntToDec(int number,int* binary,int i);


int main()
{
    int array[SIZE] = { -10, -5, -4, -3, -1, 1, 3, 4, 5, 10 };

    cout << "Entering any sequence of numbers :\n";
    cout << "To interrupt input, enter the number 0\n";
    cout << "----------------------------------\n";

    func();
    cout << "\n\n----------------------------------\n";
    cout << "Second array elements are:\n";
    PrintElements(array,SIZE,1);
 
    cout << "\n----------------------------------\n";
    cout << "Dec to binary:\n";

    int binaryArr[BINARY_SIZE];
    int i = 0;

    ConvertIntToDec(20,binaryArr,i);
    cout << "\n----------------------------------\n";
    system("PAUSE");

}

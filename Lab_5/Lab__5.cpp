﻿#include <iostream>
#include <vector>
#include "Header.h"
using namespace std;

//
//Сгенерировать одномерный динамический массив A из m элементов. Вводится число k (k<m). 
// Получить из А матрицу B, по k элементов в строке.  Если m не кратно k,  
// недостающие элементы последней строки дополнить нулями.
// 
// 2. Создать двумерный массив с переменной длиной строки, в который записать таблицу умножения следующего вида:
// 
// 1
// 2   4
// 3   6   9
// 4   8  12 16
// 5  10 15 20 25
// 6  12 18 24 30 36
// 7  14 21 28 35 42 49
// 8  16 24 32 40 48 56 64
// 9  18 27 36 45 54 63 72 81
//

int main()
{
	GenerateArray();
	cout << "\n***----------------------***\n";
	GenerateLadderMatrix();
}

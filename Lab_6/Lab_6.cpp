#include <iostream>
#include <math.h>
using namespace std;

// 1. Написать функцию, которая вычисляет периметр и площадь треугольника. В функцию передаётся длина его сторон. 
// Результаты возвращаются через параметры-указатели. В функции также предусмотреть ошибку в введённых данных 
// (если такой треугольник может существовать, функция возвращает 1, иначе 0 через своё имя).
//
// Написать функцию, определяющую вероятность того, что среди n детей будет m девочек или m мальчиков.
// Предусмотреть контроль входных данных. Вероятность рождения девочки p=0.45, мальчика q=1-p. 

bool CalcPerimeterAndSquare(const double a,const double b,const double c,double* perimeter,double* square)
{
    int countTrueLines = 0;

    if (a + b > c)
        countTrueLines++;
    if (a + c > b)
        countTrueLines++;
    if (b + c > a)
        countTrueLines++;

    if (countTrueLines == 3)
    {
        double semiPerimeter = (a + b + c) / 2;

        *perimeter = a + b + c;
        *square = sqrt(semiPerimeter * ((semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c)));

        return 1;
    }
    else
        cout << "Треугольник со сторонами: " << a << " " << b << " " << c << " существовать не может!";

    return 0;
}

int CalcFactorial(int number)
{
    if (number <= 1)
        return 1;

    else
        return (number * CalcFactorial(number - 1));
}

void CalcGirlsAndBoys(int childCount,int boys ,int girls,double& girlsProperty,double& boysProperty) 
{
    double cnBoys = 0;
    double cnGirls = 0;

    cnBoys = (double)CalcFactorial(childCount) / (CalcFactorial(boys) * (CalcFactorial(childCount - boys)));
    cnGirls = (double)CalcFactorial(childCount) / (CalcFactorial(girls) * (CalcFactorial(childCount - girls)));

    cout << cnBoys;
    cout << cnGirls;

    girlsProperty = cnGirls * pow(0.45,girls) * pow(0.55,childCount - girls);
    boysProperty = cnBoys * pow(0.55,boys) * pow(0.45,childCount - boys);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double a = 10, b = 15, c = 15;
    double perimeter = 0 , square = 0;
    CalcPerimeterAndSquare(a, b, c,&perimeter,&square);

    cout << "периметр: " << perimeter<<"\n";
    cout << "площадь: " << square << "\n";

    double girlsProperty, boysProperty;
    int boysCount = 5,girlsCount = 5;
    CalcGirlsAndBoys(5,boysCount,girlsCount, girlsProperty, boysProperty);

    cout << "Вероятность рождения девочки: " << girlsProperty<<"\n";
    cout << "Вероятность рождения мальчика: " << boysProperty << "\n";
}


#include <iostream>
using namespace  std;
double const PI = 3.141592658979;

int CalculateFactorial(int number);

void CalculateEasterDate(int year) 
{
	int firstResidue = year % 19,secondResidue = year % 4,thirdResidue = year % 7;
	int d = (19 * firstResidue + 15) % 30;
	int f = (2 * secondResidue + 4 * thirdResidue + 6 * d + 6) % 7;
	int result = f + d;

	if (result <= 26 and year < 2023)
		cout << "In " << year << " year " << "Easter was at " << 4 + result << " April.";
	
	else if(result <= 26 and year >= 2023)
		cout << "In " << year << " year " << "Easter will at " << 4 + result << " April.";

	else if(result > 26 and year < 2023)
		cout << "In " << year << " year " << "Easter was at " << result - 26  <<  "May.";

	else if(result > 26 and year >= 2023)
		cout << "In " << year << " year " << "Easter will at " << result - 26 << " May.";

}

double CalculatePow(double found,int degree)
{
	double temp = found;
	if (degree > 0) 
	{
		for (int i = 1; i < degree; i++)
			found *= temp;
		return found;
	}
		
	if (degree == 0)
		return 1;


	for (int i = 1; i < -degree; i++)
		found *= temp;
	
	return 1/found;
}

double CalculateCos(double number)
{
	double n = 1.0;
	double sum = 0.0;
	int i = 1;

	do
	{
		sum += n;
		n *= -1.0 * number * number / ((2 * i - 1) * (2 * i));
		i++;

	} while (fabs(n) > 0.0000001);

	return sum;
}

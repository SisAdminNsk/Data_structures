#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
using namespace std;
//Дана информация о  школах города. Запись имеет вид: номер школы, количество выпускников школы, число поступивших в ВУЗ. 
//сформировать массив из записей.
//отсортировать его с помощью индексного массива по проценту поступивших в ВУЗы.
//вывести данные о количестве выпускников в каждой школе и проценту поступивших в ВУЗ.

//Дана информация о комнатах в общежитии.Запись имеет вид : номер комнаты, площадь комнаты, факультет, количество проживающих.
//сформировать массив из записей.
//вычислить количество различных факультетов и занести их в отдельный массив.
//С помощью массива факультетов вывести данные о  количестве комнат, количестве студентов и средней площади на одного студента по каждому факультету.
const int SCHOOL_COUNT = 5;
const int ROOM_COUNT = 12;

struct School
{
	int schoolNumber;// номер школы.
	int graduateCount;// кол-во выпускников.
	int universityMembersCount;// кол-во поступивших в ВУЗ.
};

struct Room 
{
	string facultyName;// название факультета
	double roomSquare;// полщадь комнаты
	int roomNuber;// номер комнаты проживающего
	int residingCount;// кол-во проживающих
};

double CalculatePercentEntered(const School school);
void ShellSort(const vector<School> schools,const int schoolsCount, int* indexArray);

int main()
{
	vector<School> schools(SCHOOL_COUNT);
	int indexArray[SCHOOL_COUNT] = { 0,1,2,3,4 };// индексный массив для сортировки записей

	schools[0] = { 122,50,15 };// 30%
	schools[1] = { 22,45,27 };// 60%
	schools[2] = { 69,57,12 };// 21%
	schools[3] = { 1,127,98 };// 77%
	schools[4] = { 127,27,19 };// 70%

	vector<Room> rooms(ROOM_COUNT);
	rooms[0] = { "IVT",15,517,2 }; 	rooms[1] = { "IVT",13.5,516,2 };
	rooms[2] = { "IVT",17,518,3 }; rooms[3] = { "RADIO",14,126,2 };
	rooms[4] = { "RADIO",14,116,2 }; rooms[5] = { "RADIO",19,119,3 };
	rooms[6] = { "HUM",12.5,253,2 }; rooms[7] = { "HUM",17.5,255,3 };
	rooms[8] = { "HUM",19,257,3 }; rooms[9] = { "SECURITY",16,346,2 };
	rooms[10] = { "SECURITY",21.5,364,3 };
	
	map <string, vector<int>> facultyesAndCount;// определяем словарик факультетов;
	vector<int> facultyIndex(1);// индексный массив комнат, для сопоставления с факультетами 

	for (int i = 0, index = 0,facSize = 1; i < ROOM_COUNT - 1; i++)// определяем кол-во уникальных факультетов и добавляем их в массив факультетов
	{
		facultyIndex[index] = i;// кладем индекс комнат одного факультета
		facSize++; index++;// увеличиваем размер индексного массива и увеличиваем сдвиг
		
		string compare = rooms[i].facultyName;
		if (compare != rooms[i + 1].facultyName)
		{
			facultyesAndCount[compare] = facultyIndex;// кладем факультет и кол-во его повторейний в словарик
			index = 0; facSize = 1;
		
			facultyIndex.clear();// очищаем индексный массив
			facultyIndex.resize(facSize);// пересоздаем и задаем ему размер равный 1 в начале итерации
		}
		facultyIndex.resize(facSize);// увеличиваем размер массива 
	}

	ShellSort(schools, SCHOOL_COUNT, indexArray);// сортируем школы по проценту поступивших в вузы с помощью индексного массива 

	cout << left << setw(10) << "School:" << left << setw(10) << "Students:" << left << setw(10) << "Percent %" << "\n";
	for (int i = 0; i < 5; i++)
	{
		cout << left << setw(10) << schools[indexArray[i]].schoolNumber << left << setw(10) << schools[indexArray[i]].graduateCount
			<< left << setw(10) << CalculatePercentEntered(schools[indexArray[i]]) << "\n";
	}

	cout << "\n" << left << setw(10) << "Faculty:" << left << setw(10) << "Rooms:" << left << setw(10) << "Students:"
		<< left << setw(10) << "Mid square:" << "\n";// выводим шапку таблицы 
	int iterCounter = 0;// счетчик итераций
	for (auto item : facultyesAndCount)// перебираем каждый элемент словарика 
	{
		int allResidings = 0,roomsCount = 0;
		double avgSquare = 0,allSquare = 0;

		for (int i = 0,roomsInc = 1;i < item.second.size(); i++)
		{
			roomsCount += roomsInc;// считаем кол-во комнат
			allSquare += rooms[item.second[i]].roomSquare;// считаем площадь всех комнат
			allResidings += rooms[item.second[i]].residingCount;// считаем кол-во всех проживающих
			iterCounter++;// увеличиваем счетчик
		}
		avgSquare = (allSquare / allResidings);// считаем среднюю площадь комнат на факультет 
		cout << left << setw(10) << item.first << left << setw(10) << roomsCount << left << setw(10) << allResidings
			<< left <<setw(10) << avgSquare << "\n";
	}
	cout << "\nIterations: " << iterCounter;// выводим кол-во итераций,которое потребовалось для вывода всех данных.
}

double CalculatePercentEntered(const School school) 
{
	return (static_cast<double>(school.universityMembersCount) / school.graduateCount)*100;
}

void ShellSort(const vector<School> schools,const int schoolsCount,int* indexArray)// сортируем индексный массив
{
	int h = schoolsCount / 2;
	while (h >= 1) 
	{
		for (int i = h; i < schoolsCount; i++) 
		{
			int j = i;
			while ((j >= h) && CalculatePercentEntered(schools[j - h]) > CalculatePercentEntered(schools[j])) 
			{
				int t = indexArray[j];
				indexArray[j] = indexArray[j - h];
				indexArray[j - h] = t;
				j = j - h;
			}
		}
		h /= 2;
	}
}
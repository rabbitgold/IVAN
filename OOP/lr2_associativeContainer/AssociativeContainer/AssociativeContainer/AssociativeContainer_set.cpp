#include <iostream>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <time.h>

using namespace std;

const int minRand = 700;
const int maxRand = 900;
const int SIZE = 10;

void generateContainer(set<int>& cont);
void printElements(set<int> cont, string title);
void eraseElement_value(set<int>& cont, int value);
void eraseElement_index(set<int>& cont, int index);
void changeElements(set<int>& cont);

int main()
{
	setlocale(LC_ALL, "Russian");
	
	int index;
	int value;
	set<int> cont;

	generateContainer(cont);
	printElements(cont, "Начальный контейнер");

	changeElements(cont);
	printElements(cont, "Контейнер после выполнения задания");

	cout << "\nВведите значение для удаления: ";
	cin >> value;
	eraseElement_value(cont, value);
	printElements(cont, "Контейнер после удаления(по значению)");

	cout << "\nВведите индекс элемента для удаления: ";
	cin >> index;
	eraseElement_index(cont, index);
	printElements(cont, "Контейнер после удаления(по индексу)");

	return 0;
}

void generateContainer(set<int>& cont)
{
	srand(time(NULL));

	for (int i = 0; i < SIZE; i++)
	{
		int val = minRand + rand() % maxRand;
		cont.insert(val);
	}
}

void printElements(set<int> cont, string title)
{
	set<int>::iterator it;

	cout << "\n" << title << ":" << endl;
	for (it = cont.begin(); it != cont.end(); it++)
	{
		cout << "[ " << distance(cont.begin(), it) << "] " <<  *it << endl;
	}
}

void eraseElement_value(set<int>& cont, int value)
{
	cont.erase(value);
}

void eraseElement_index(set<int>& cont, int index)
{
	set<int>::iterator it;
	int tmp = 0;
	for (it = cont.begin(); it != cont.end(); it++)
	{
		tmp++;
		if (tmp == index + 1)
		{
			cont.erase(it);
			break;
		}
	}
}

void changeElements(set<int>& cont)
{
	int firstElValue = *(cont.begin());
	set<int> tmpSet;
	set<int>::iterator it;

	for (it = cont.begin(); it != cont.end(); it++)
	{
		int tmpValue = *it;
		tmpValue = tmpValue + firstElValue;
		tmpSet.insert(tmpValue);
	}

	cont.clear();
	cont = tmpSet;
}
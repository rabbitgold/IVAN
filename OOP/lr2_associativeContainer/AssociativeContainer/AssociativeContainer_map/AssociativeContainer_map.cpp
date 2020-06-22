#include <iostream>
#include <cstdlib>
#include <time.h>
#include <map>

using namespace std;

const int minRand = 90;
const int maxRand = 150;
const int SIZE = 10;

void generateElements(map<int, char>& cont);
void printElements(map<int, char> cont, string title);
void changeElements(map<int, char>& cont);

int main()
{
    setlocale(LC_ALL, "Russian");
    
    map<int, char> cont;

    generateElements(cont);
    printElements(cont, "Начальный контейнер");

    changeElements(cont);
    printElements(cont, "Измененный контейнер");

    return 0;
}

void generateElements(map<int, char>& cont)
{
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        char value = minRand + rand() % maxRand;
        cont.insert(pair<int, char>(i, value));
    }
}

void printElements(map<int, char> cont, string title)
{
    map<int, char>::iterator it;

    cout << "\n" << title << ":" << endl;
    for (it = cont.begin(); it != cont.end(); it++)
    {
        cout << it->first << " - " << it->second << endl;
    }
}

void changeElements(map<int, char>& cont)
{
    int maxElement = 0;
    map<int, char>::iterator it;
    map<int, char>::iterator maxElementIt;
    for (it = cont.begin(); it != cont.end(); it++)
    {
        if (it->second > maxElement)
        {
            maxElement = it->second;
            maxElementIt = it;
        }
    }

    cont.erase(cont.begin(), maxElementIt);
}
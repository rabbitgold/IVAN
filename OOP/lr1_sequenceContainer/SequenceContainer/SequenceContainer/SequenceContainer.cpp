//Найти максимальный элемент и удалить его из контейнера.

#include <iostream>
#include <random>
#include <vector>
#include <bitset>

using namespace std;

void fillBitsetContainer(vector<bitset<32>> &cont);
void printBitsetContainer(vector<bitset<32>> cont, string title);
void printBitsetContainerElement(vector<bitset<32>> cont, int index);
void delMaxElement(vector<bitset<32>> &cont);
bool BitComp(bitset<32>& l, bitset<32>& r);

const int SIZE = 10;

int main()
{
    vector<bitset<32>> container;
    int index;

    fillBitsetContainer(container);
    printBitsetContainer(container, "Default container");

    delMaxElement(container);
    printBitsetContainer(container, "After change");

    cout << "Enter index of element for print: ";
    cin >> index;
    printBitsetContainerElement(container, index);
}

void fillBitsetContainer(vector<bitset<32>> &cont)
{
    random_device rd;
    mt19937 gen(rd());

    int value = gen();

    for (int i = 0; i < SIZE; i++)
    {
        int value = gen();

        cont.push_back(value);
    }
}

void printBitsetContainer(vector<bitset<32>> cont, string title)
{
    vector<bitset<32>>::iterator it;

    cout << "\n" << title << ":" << endl;
    for (it = cont.begin(); it != cont.end(); it++)
    {
        bitset<32> tmp = *it;
        cout << "[" << distance(cont.begin(), it) << "] " << *it << " | " << hex << tmp.to_ulong() << dec <<  " | " << tmp.to_ulong() << endl;
    }
}

void delMaxElement(vector<bitset<32>> &cont)
{
    vector<bitset<32>>::iterator itMaxElement = max_element(cont.begin(), cont.end(), BitComp);
    cont.erase(itMaxElement);
}

bool BitComp(bitset<32>& l, bitset<32>& r)
{
    return int(l.to_ulong()) < int(r.to_ulong());
}

void printBitsetContainerElement(vector<bitset<32>> cont, int index)
{
    try
    {
        bitset<32> tmp = cont.at(index);
        cout << "\n" << index << " element is " << tmp << " | " << hex << tmp.to_ulong() << dec << " | " << tmp.to_ulong() << endl;
    }
    catch (out_of_range)
    {
        cout << "Error: index is out of range" << endl;
    }
}
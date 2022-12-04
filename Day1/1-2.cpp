#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define N_TOPS 3

void handleNewCount(int, int[]);
void InsertAt(int, int, int[]);

int main()
{
    string num;
    ifstream file;

    int count = 0;

    int Tops[N_TOPS];

    for (int i = 0; i < N_TOPS; i++)
        Tops[i] = 0;

    file.open("inp1.txt");

    while (getline(file, num))
    {
        if (!num.empty())
        {
            count += stoi(num);
        }
        else
        {
            handleNewCount(count, Tops);
            count = 0;
        }
    }

    handleNewCount(count, Tops);

    int total = 0;
    for (int i = 0; i < N_TOPS; i++)
        total += Tops[i];

    cout << total << endl;

    file.close();

    return 0;
}

void InsertAt(int val, int index, int arr[])
{
    for (int i = N_TOPS - 1; i >= index + 1; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = val;
}

void handleNewCount(int Count, int tops[])
{
    bool found = false;
    for (int i = 0; i < N_TOPS && !found; i++)
    {
        if (tops[i] < Count)
        {
            InsertAt(Count, i, tops);
            found = true;
        }
    }
}
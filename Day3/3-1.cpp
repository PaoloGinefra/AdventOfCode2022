#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char inCommon(string);
int computeScore(char c);

int main()
{
    ifstream file;

    string rucksack;
    char common;
    int total = 0;

    file.open("inp.txt");

    while (getline(file, rucksack))
    {
        common = inCommon(rucksack);
        total += computeScore(common);
        cout << common << endl;
    }

    cout << total << endl;

    file.close();

    return 0;
}

char inCommon(string rucksack)
{
    int len = rucksack.length();
    bool found = false;
    char common;

    for (int i = 0; i < (len - 1) / 2 && !found; i++)
    {
        for (int j = (len - 1) / 2; j < len && !found; j++)
        {
            if (rucksack[i] == rucksack[j])
            {
                found = true;
                common = rucksack[i];
            }
        }
    }

    return common;
}

int computeScore(char c)
{
    return ('a' <= c && c <= 'z') ? c - 'a' + 1 : c - 'A' + 27;
}
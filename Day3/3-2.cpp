#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define N_IN_GROUP 3

char inCommon(string[]);
int computeScore(char c);

int main()
{
    ifstream file;

    string rucksacks[N_IN_GROUP];
    char common;
    int total = 0;

    file.open("inp.txt");

    while (getline(file, rucksacks[0]))
    {
        for (int i = 1; i < N_IN_GROUP; i++)
        {
            getline(file, rucksacks[i]);
        }

        common = inCommon(rucksacks);
        total += computeScore(common);
        cout << common << endl;
    }

    cout << total << endl;

    file.close();

    return 0;
}

char inCommon(string rucksacks[])
{
    int len = rucksacks[0].length();
    bool found = false;
    char common;

    for (int i = 0; i < len && !found; i++)
    {
        found = true;
        for (int j = 1; j < N_IN_GROUP && found; j++)
        {
            int j_len = rucksacks[j].length();
            found = false;
            for (int k = 0; k < j_len && !found; k++)
            {
                if (rucksacks[0][i] == rucksacks[j][k])
                {
                    found = true;
                    common = rucksacks[0][i];
                }
            }
        }
    }

    return common;
}

int computeScore(char c)
{
    return ('a' <= c && c <= 'z') ? c - 'a' + 1 : c - 'A' + 27;
}
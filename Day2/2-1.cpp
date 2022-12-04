#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define FIRST_OPP 'A'
#define FIRST_ME 'X'

#define WINNING_SCORE 3

int WinScore(int, int);

int main()
{
    ifstream file;

    string round;

    int opponent, me, score, total = 0;

    file.open("inp.txt");

    while (getline(file, round))
    {
        opponent = round[0] - FIRST_OPP;
        me = round[2] - FIRST_ME;

        score = me + 1 + WinScore(opponent, me);

        total += score;
    }

    cout << total << endl;

    file.close();

    return 0;
}

int WinScore(int opp, int me)
{
    return ((opp == me) + 2 * (me == (opp + 1) % 3)) * WINNING_SCORE;
}
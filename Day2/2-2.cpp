#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define FIRST_OPP 'A'
#define FIRST_ME 'X'

#define WINNING_SCORE 3

int ComputeMove(int, int);

int main()
{
    ifstream file;

    string round;

    int opponent, result, score, total = 0;

    file.open("inp.txt");

    while (getline(file, round))
    {
        opponent = round[0] - FIRST_OPP;
        result = round[2] - FIRST_ME;

        score = result * WINNING_SCORE + ComputeMove(opponent, result) + 1;

        total += score;
    }

    cout << total << endl;

    file.close();

    return 0;
}

int ComputeMove(int opp, int result)
{
    return (opp + result - 1 + 3) % 3;
}
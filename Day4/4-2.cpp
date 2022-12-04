#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct
{
    int a, b;
} Range_t;

void parseString(Range_t *, string);
int overlaps(Range_t *, Range_t *);

int main()
{
    ifstream file;

    string pairs;

    Range_t first, second;
    int comma_index;
    int total = 0;

    file.open("inp.txt");

    while (getline(file, pairs))
    {
        comma_index = pairs.find(',');
        parseString(&first, pairs.substr(0, comma_index));
        parseString(&second, pairs.substr(comma_index + 1, pairs.length()));

        total += overlaps(&first, &second) || overlaps(&second, &first);
    }

    cout << total << endl;

    file.close();

    return 0;
}

void parseString(Range_t *target, string str)
{
    int dashIndex = str.find('-');
    target->a = stoi(str.substr(0, dashIndex));
    target->b = stoi(str.substr(dashIndex + 1, str.length()));
}

int overlaps(Range_t *a, Range_t *b)
{
    return (a->a <= b->a) && (a->b >= b->a);
}
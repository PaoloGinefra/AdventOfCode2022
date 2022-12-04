// basic file operations
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string num;
    ifstream file;

    int count = 0;
    int max = 0;

    file.open("inp1.txt");

    while (getline(file, num))
    {
        if (!num.empty())
        {
            count += stoi(num);

            if (count > max)
                max = count;
        }
        else
            count = 0;
    }

    if (count > max)
        max = count;

    cout << max << endl;

    file.close();

    return 0;
}
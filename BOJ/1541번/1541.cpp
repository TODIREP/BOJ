#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string input;
    cin >> input;

    bool isMinus = false;
    int sum = 0, before = 0, temp = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '-' || input[i] == '+')
        {
            if (isMinus) temp += stoi(input.substr(before, i - before));
            else sum += stoi(input.substr(before, i - before));
            before = i + 1;
        }
        else if (input[i + 1] == '\0')
        {
            if (isMinus) temp += stoi(input.substr(before, i - before + 1));
            else sum += stoi(input.substr(before, i - before + 1));
        }

        if (input[i] == '-') isMinus = true;
    }

    cout << sum - temp;

    return 0;
}
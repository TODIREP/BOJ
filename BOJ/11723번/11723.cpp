#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M, num;
    cin >> M;

    string opers;
    int target = 0;

    while (M--)
    {
        cin >> opers;

        if (opers.compare("add") == 0)
        {
            cin >> num;
            target |= (1 << (num - 1));
        }
        else if (opers.compare("remove") == 0)
        {
            cin >> num;
            target &= ~(1 << (num - 1));
        }
        else if (opers.compare("check") == 0)
        {
            cin >> num;
            int check = target & (1 << (num - 1));
            cout << (check != 0) << '\n';
        }
        else if (opers.compare("toggle") == 0)
        {
            cin >> num;
            target ^= (1 << (num - 1));
        }
        else if (opers.compare("all") == 0)
        {
            target = ~(1 << 20);
        }
        else // empty
        {
            target = 0;
        }
    }

    return 0;
}
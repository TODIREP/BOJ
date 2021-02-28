#include <iostream>
using namespace std;

int main(void)
{
    int M;
    cin >> M;

    int i = 0, cur = 0;

    while (++i)
    {
        int check = i;

        while (check % 5 == 0)
        {
            cur++;
            check /= 5;
        }

        int N = i * 5;
        cur++;

        if (cur == M)
        {
            cout << N;
            return 0;
        }

        if (cur > M)
        {
            cout << -1;
            return 0;
        }
    }
}
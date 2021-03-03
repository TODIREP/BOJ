#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int count = 0, cmp = 1, answer = 0;

    while (++count)
    {
        if (N < cmp * 10)
        {
            answer += (N - cmp + 1) * count;
            break;
        }

        answer += (cmp * 10 - cmp) * count;
        cmp *= 10;
    }

    cout << answer;
    return 0;
}
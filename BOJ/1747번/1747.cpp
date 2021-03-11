#include <iostream>
using namespace std;

bool sosu[2000001];

bool valid(int target)
{
    int tmp[8], index = 0;

    while (target > 0)
    {
        tmp[index++] = target % 10;
        target /= 10;
    }

    for (int i = 0; i < index / 2; i++)
    {
        if (tmp[i] != tmp[index - i - 1])
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    int N;
    cin >> N;

    sosu[1] = true;
    for (int num = 2; num <= 2000000; num++)
    {
        if (sosu[num]) continue;
        
        for (int i = 2; num * i <= 2000000; i++)
        {
            sosu[num * i] = true;
        }
    }

    for (int num = N; num <= 2000000; num++)
    {
        if (!sosu[num])
        {
            if (valid(num))
            {
                cout << num;
                break;
            }
        }
    }

    return 0;
}
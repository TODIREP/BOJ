#include <iostream>
using namespace std;
using lint = long long;

const lint MAX_NUM = __LONG_LONG_MAX__;
const int LIMITS = 1e7;
bool sosu[LIMITS + 1];
lint sosus[LIMITS];

int main(void)
{
    lint A, B;
    cin >> A >> B;

    int pos = 0;
    for (lint num = 2; num <= LIMITS; num++)
    {
        if (sosu[num]) continue;
        sosus[pos++] = num;
        for (lint index = 2; index * num <= LIMITS; index++)
        {
            lint number = index * num;
            if (sosu[number]) continue;
            sosu[number] = true;
        }
    }

    int answer = 0;
    for (int index = 0; index < pos; index++)
    {
        lint number = sosus[index] * sosus[index];
        while (number <= B)
        {
            if (number >= A)
            {
                answer++;
            }

            if (number > (MAX_NUM / sosus[index]))
            {
                break;
            }
            
            number *= sosus[index];
        }
    }

    cout << answer;
    return 0;
}
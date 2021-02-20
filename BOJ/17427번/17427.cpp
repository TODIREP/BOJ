#include <iostream>
using namespace std;

long long g(int n)
{
    long long res = 0;

    for (int i = 1; i <= n; i++)
    {
        res += i * (n / i);
    }
    
    return res;
}

int main(void)
{
    long long N;
    cin >> N;
    cout << g(N);
    return 0;
}
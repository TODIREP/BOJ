#include <iostream>
using namespace std;

void search(int a, int b, int n)
{
    if (n == 1)
    {
        cout << a << " " << b << '\n';
        return;
    }

    search(a, 6 - a - b, n - 1);
    cout << a << " " << b << '\n';
    search(6 - a - b, b, n - 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K;
    cin >> K;
    cout << (1 << K) - 1 << '\n';
    search(1, 3, K);
    return 0;
}
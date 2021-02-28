#include <iostream>
using namespace std;
using lint = long long;

pair<lint, lint> cnt(lint target)
{
    lint res2 = 0, res5 = 0, num;

    num = 2;
    while (num <= target)
    {
        res2 += target / num;
        num *= 2;
    }

    num = 5;
    while (num <= target)
    {
        res5 += target / num;
        num *= 5;
    }

    return {res2, res5};
}

int main(void)
{
    lint N, M;
    cin >> N >> M;

    auto A = cnt(N), B = cnt(N - M), C = cnt(M);

    lint R = A.first - B.first - C.first;
    lint P = A.second - B.second - C.second;

    cout << min(R, P);
    return 0;
}
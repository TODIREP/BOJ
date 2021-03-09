#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque<pair<int, int>> dq;

    int N, L, num;
    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        
        while (!dq.empty() && dq.back().first >= num)
        {
            dq.pop_back();
        }

        while (!dq.empty() && i - dq.back().second >= L)
        {
            dq.pop_back();
        }

        while (!dq.empty() && i - dq.front().second >= L)
        {
            dq.pop_front();
        }

        dq.push_back({num, i});

        cout << dq.front().first << ' ';
    }

    return 0;
}
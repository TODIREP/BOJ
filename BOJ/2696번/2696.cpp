#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int M, num, mid;
        cin >> M;
        cout << (M + 1) / 2 << '\n';

        priority_queue<int, vector<int>, greater<int>> min_heap;
        priority_queue<int, vector<int>, less<int>> max_heap;

        cin >> mid;
        cout << mid << ' ';
        for (int i = 2; i <= M; i++)
        {
            cin >> num;

            if (i % 2 == 0)
            {
                if (num > mid)
                {
                    min_heap.push(num);
                    max_heap.push(mid);
                }
                else
                {
                    min_heap.push(mid);
                    max_heap.push(num);
                }
            }
            else
            {
                if (num > min_heap.top())
                {
                    min_heap.push(num);
                    mid = min_heap.top();
                    min_heap.pop();
                }
                else
                {
                    max_heap.push(num);
                    mid = max_heap.top();
                    max_heap.pop();
                }
                cout << mid << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
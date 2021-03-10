#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, num, mid;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;

    cin >> mid;
    cout << mid << '\n';
    for (int i = 2; i <= N; i++)
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
                max_heap.push(num);
                min_heap.push(mid);
            }
            mid = max_heap.top();
        }
        else
        {
            if (num > mid)
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
        }

        cout << mid << '\n';
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int index = N;
    for (int i = 1; i < N; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            index = i;
        }
    }

    if (index == N)
    {
        cout << -1;
        return 0;
    }

    int nxt = index;
    while (arr[index - 1] > arr[nxt] && nxt < N) nxt++;

    swap(arr[index - 1], arr[nxt - 1]);

    reverse(arr.begin() + index, arr.begin() + N);

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}
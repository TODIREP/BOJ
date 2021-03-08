#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    int left = 0, right = N - 1;
    int ans_left, ans_right, ans_sum = 2000000002;

    for (int i = 0; i < N; i++)
    {
        int left = i + 1, right = N - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;

            int cur_sum = arr[i] + arr[mid];

            if (abs(cur_sum) < ans_sum)
            {
                ans_sum = abs(cur_sum);
                ans_left = i;
                ans_right = mid;
            }

            if (cur_sum == 0) break;

            if (cur_sum < 0) left = mid + 1;
            else right = mid - 1;
        }
    }

    cout << arr[ans_left] << ' ' << arr[ans_right];

    return 0;
}
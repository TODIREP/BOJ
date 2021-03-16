#include <iostream>
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

    int left = 0, right = N - 1, answer = 200000003;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(answer))
        {
            answer = sum;
        }

        if (sum < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << answer;
    return 0;
}
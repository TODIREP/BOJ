#include <iostream>
#include <algorithm>
using namespace std;

int number[1000001];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, k;
    cin >> t;
    for (int test_case = 0; test_case < t; test_case++)
    {
        cin >> n >> k;
        for (int index = 0; index < n; index++) cin >> number[index];
        sort(number, number + n);

        int answer = 0, left = 0, right = n - 1, diff = (int) 1e9;
        while (left < right)
        {
            int value = number[left] + number[right];
            if (abs(k - value) < abs(k - diff))
            {
                diff = value;
                answer = 1;
            }
            else if (abs(k - value) == abs(k - diff)) answer++;

            if (value >= k) right--;
            else left++;
        }
        cout << answer << '\n';
    }
    return 0;
}
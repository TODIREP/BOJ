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

    vector<int> num(N);
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        int left = 0, right = N - 1;

        while (left < right)
        {
            if (left == i) left++;
            else if (right == i) right--;
            if (left == right) break;

            int sum = num[left] + num[right];

            if (sum == num[i])
            {
                answer++;
                break;
            }

            if (sum < num[i])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    cout << answer;
    return 0;
}
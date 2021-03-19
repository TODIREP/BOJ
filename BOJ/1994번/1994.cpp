#include <iostream>
#include <algorithm>
using namespace std;

int num[2001], dis[2001][2001], delta[2001][2001];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        dis[i][i] = 1;
        delta[i][i] = -1;
    }
    sort(num, num + N);

    int answer = 1;
    for (int i = 0; i < N; i++)
    {
        for (int k = i - 1; k >= 0; k--)
        {
            int del = num[i] - num[k], index = k;
            int left = 0, right = k - 1;

            while (left < right)
            {
                int mid = (left + right) / 2;
                
                if (delta[k][mid] >= del)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }
            index = left;

            delta[i][k] = del;
            if (delta[k][index] == del)
            {
                dis[i][k] = dis[k][index] + 1;
            }
            else if (index > 0 && delta[k][index - 1] == del)
            {
                dis[i][k] = dis[k][index - 1] + 1;
            }
            else
            {
                dis[i][k] = 2;
            }
            answer = max(answer, dis[i][k]);
        }
    }
    cout << answer;
    return 0;
}
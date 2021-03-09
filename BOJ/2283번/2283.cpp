#include <iostream>
using namespace std;
using lint = long long;

lint line[1000001];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lint N, K;
    cin >> N >> K;

    int A, B, LIMITS = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;
        line[A]++;
        line[B]--;

        LIMITS = max(LIMITS, B);
    }

    lint cur = 0;
    for (int i = 0; i <= LIMITS; i++)
    {
        cur += line[i];
        line[i] = cur;
    }

    lint cur_sum = 0;
    int left = 0, right = 0;
    int ans_left = 0, ans_right = 0;

    while (left < LIMITS)
    {
        if (cur_sum == K)
        {
            ans_left = left;
            ans_right = right;
            break;
        }

        if (cur_sum < K)
        {
            cur_sum += line[right++];
        }
        else
        {
            cur_sum -= line[left++];
        }
    }
    
    cout << ans_left << ' ' << ans_right;
    return 0;
}
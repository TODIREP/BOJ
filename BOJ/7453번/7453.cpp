#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using lint = long long;

lint A[4001], B[4001], C[4001], D[4001];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lint N;
    cin >> N;

    for (lint i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    vector<lint> pre_sum(N * N);
    for (lint i = 0; i < N; i++)
    {
        for (lint j = 0; j < N; j++)
        {
            pre_sum[i * N + j] = C[i] + D[j];
        }
    }
    sort(pre_sum.begin(), pre_sum.end());

    lint answer = 0;
    for (lint i = 0; i < N; i++)
    {
        for (lint j = 0; j < N; j++)
        {
            lint cur_sum = A[i] + B[j];

            lint res_right = upper_bound(pre_sum.begin(), pre_sum.end(), -cur_sum) - pre_sum.begin();
            lint res_left = lower_bound(pre_sum.begin(), pre_sum.end(), -cur_sum) - pre_sum.begin();

            if (-cur_sum == pre_sum[res_left])
            {
                answer += (res_right - res_left);
            }
        }
    }
    cout << answer;
    return 0;
}
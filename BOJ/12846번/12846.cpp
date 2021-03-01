#include <iostream>
#include <vector>
using namespace std;
using lint = long long;

vector<lint> pay;

lint search(int S, int E)
{
    if (S == E) return pay[S];

    int mid = (S + E) / 2;

    lint result = max(search(S, mid), search(mid + 1, E));
    int left = mid, right = mid + 1;
    lint cur_count = right - left + 1;
    lint cur_min = min(pay[left], pay[right]);
    lint cur_pay = cur_min * cur_count;

    result = max(result, cur_pay);

    while (left > S || right < E)
    {
        if (right < E && (left == S || pay[left - 1] < pay[right + 1]))
        {
            cur_count++;
            cur_min = min(cur_min, pay[++right]);
        }
        else
        {
            cur_count++;
            cur_min = min(cur_min, pay[--left]);
        }

        result = max(result, cur_min * cur_count);
    }

    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    pay.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> pay[i];
    }
    
    cout << search(0, N - 1);
    return 0;
}
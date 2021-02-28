#include <iostream>
#include <vector>
using namespace std;
using lint = long long;

vector<lint> num;
lint search(lint S, lint E)
{
    if (S == E) return num[S] * num[E];
    lint mid = (S + E) / 2;
    lint result = max(search(S, mid), search(mid + 1, E));

    lint left = mid, right = mid + 1;
    lint cur_num = num[left] + num[right];
    lint cur_min = min(num[left], num[right]);
    result = max(result, cur_num * cur_min);

    while (left > S || right < E)
    {
        if (right < E && (left == S || num[left - 1] < num[right + 1]))
        {
            cur_num += num[right + 1];
            right++;
            cur_min = min(cur_min, num[right]);
        }
        else
        {
            cur_num += num[left - 1];
            left--;
            cur_min = min(cur_min, num[left]);
        }
        result = max(result, cur_min * cur_num);
    }
    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lint N;
    cin >> N;
    num.resize(N);
    for (lint i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    cout << search(0, N - 1);
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<pair<int, int>> line)
{
    vector<int> check_index, check_value;
    vector<int> pre_index(n), dis(n);

    check_index.push_back(-1);
    check_value.push_back(0);

    for (int i = 0; i < n; i++)
    {
        if (line[i].second > check_value.back())
        {
            pre_index[i] = check_index.back();
            dis[i] = check_index.size();
            check_value.push_back(line[i].second);
            check_index.push_back(i);
        }
        else
        {
            int index = lower_bound(check_value.begin(), check_value.end(), line[i].second) - check_value.begin();

            pre_index[i] = check_index[index - 1];
            dis[i] = index;
            check_value[index] = line[i].second;
            check_index[index] = i;
        }
    }

    int max_len = 0, max_index = -1;
    for (int i = 0; i < n; i++)
    {
        if (dis[i] > max_len)
        {
            max_len = dis[i];
            max_index = i;
        }
    }

    while (max_index >= 0)
    {
        dis[max_index] = 0;
        max_index = pre_index[max_index];
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (dis[i] == 0) continue;
        ans.push_back(line[i].first);
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> line(N);

    for (int i = 0; i < N; i++)
    {
        cin >> line[i].first >> line[i].second;
    }

    sort(line.begin(), line.end());
    vector<int> res = solution(N, line);

    cout << res.size() << '\n';
    for (int r : res)
    {
        cout << r << '\n';
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int N, ans = 100000000;
vector<vector<int>> city;
vector<int> vis;
vector<bool> check;

void search(int count)
{
    if (count == N)
    {
        if (city[vis[N - 1]][vis[0]] == 0) return;
        int sum = city[vis[N - 1]][vis[0]];

        for (int i = 1; i < N; i++)
        {
            if (city[vis[i - 1]][vis[i]] == 0) return;
            sum += city[vis[i - 1]][vis[i]];
        }

        ans = min(ans, sum);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (check[i]) continue;
        check[i] = true;
        vis[count] = i;
        search(count + 1);
        check[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    city.resize(N);
    vis.resize(N);
    check.assign(N, false);

    for (int x = 0; x < N; x++)
    {
        city[x].resize(N);
        for (int y = 0; y < N; y++)
        {
            cin >> city[x][y];
        }
    }

    search(0);

    cout << ans;

    return 0;
}
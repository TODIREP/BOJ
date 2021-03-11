#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 1, 1};
int dy[4] = {1, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int N, test_cases = 1; cin >> N; test_cases++)
    {
        if (N == 0) return 0;

        vector<vector<int>> graph(N), ans(N);

        for (int i = 0; i < N; i++)
        {
            graph[i].assign(3, 0);
            ans[i].assign(3, 2000000000);
            for (int j = 0; j < 3; j++)
            {
                cin >> graph[i][j];
            }
        }

        ans[0][1] = graph[0][1];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == 0 && j == 0) continue;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx >= N || ny < 0 || ny >= 3) continue;
                    ans[nx][ny] = min(ans[nx][ny], ans[i][j] + graph[nx][ny]);
                }
            }
        }

        cout << test_cases << ". " << ans[N - 1][1] << '\n';
    }

    return 0;
}
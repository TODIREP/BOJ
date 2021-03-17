#include <iostream>
#include <queue>
using namespace std;

const int LIMITS = 500000;
int dis[LIMITS + 1][2];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= LIMITS; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            dis[i][j] = LIMITS + 1;
        }
    }

    queue<pair<int, int>> q;
    dis[N][0] = 0;
    q.push({N, dis[N][0]});

    while (!q.empty())
    {
        int cur_pos = q.front().first;
        int cur_time = q.front().second;
        q.pop();

        int nxt_pos[3] = {cur_pos * 2, cur_pos + 1, cur_pos - 1};
        int nxt_time = cur_time + 1;

        for (int dir = 0; dir < 3; dir++)
        {
            if (nxt_pos[dir] < 0 || nxt_pos[dir] > LIMITS) continue;
            int nxt = nxt_time % 2;

            if (nxt_time < dis[nxt_pos[dir]][nxt])
            {
                dis[nxt_pos[dir]][nxt] = nxt_time;
                q.push({nxt_pos[dir], nxt_time});
            }
        }
    }

    int cur = 0, answer = -1;
    for (int index = K; index <= LIMITS; index += cur)
    {
        if (dis[index][cur % 2] <= cur)
        {
            answer = cur;
            break;
        }
        cur++;
    }

    cout << answer;

    return 0;
}
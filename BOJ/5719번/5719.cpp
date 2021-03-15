#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct link
{
    int start, distance;
    bool operator<(const link &a) const
    {
        return distance > a.distance;
    }
};
int dis[501], node[501][501];
int LIMITS = 50000000;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    while (cin >> N >> M)
    {
        if (N == 0 && M == 0) return 0;
        int S, D, U, V, P;

        cin >> S >> D;
        memset(node, 0, sizeof(node));
        fill(dis, dis + N, LIMITS);

        for (int i = 0; i < M; i++)
        {
            cin >> U >> V >> P;
            node[U][V] = P;
        }

        priority_queue<link> pq, pre[501];
        dis[S] = 0;
        pq.push({S, dis[S]});

        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            if (cur.distance != dis[cur.start]) continue;

            for (int index = 0; index < N; index++)
            {
                if (node[cur.start][index] == 0) continue;
                int nxt_dis = dis[cur.start] + node[cur.start][index];
                if (nxt_dis <= dis[index])
                {
                    pre[index].push({cur.start, nxt_dis});
                }

                if (nxt_dis < dis[index])
                {
                    dis[index] = nxt_dis;
                    pq.push({index, nxt_dis});
                }
            }
        }
        
        queue<int> q;
        q.push(D);
        fill(dis, dis + N, LIMITS);
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            
            if (pre[cur].empty()) continue;
            int cur_dis = pre[cur].top().distance;
            while (!pre[cur].empty() && pre[cur].top().distance == cur_dis)
            {
                int prev = pre[cur].top().start;
                q.push(prev);
                node[prev][cur] = 0;
                pre[cur].pop();
            }
        }

        dis[S] = 0;
        pq.push({S, dis[S]});
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            if (cur.distance != dis[cur.start]) continue;

            for (int index = 0; index < N; index++)
            {
                if (node[cur.start][index] == 0) continue;
                int nxt_dis = dis[cur.start] + node[cur.start][index];
                if (nxt_dis < dis[index])
                {
                    dis[index] = nxt_dis;
                    pq.push({index, nxt_dis});
                }
            }
        }
        cout << (dis[D] == LIMITS ? -1 : dis[D]) << '\n';
    }
}
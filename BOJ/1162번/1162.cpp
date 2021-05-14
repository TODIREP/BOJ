#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using lint = long long;

const lint limit = __LONG_LONG_MAX__;
struct link
{
    int current, road;
    lint distance;
    bool operator<(const link &a) const
    {
        return distance > a.distance;
    }
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<lint>> dis(N, vector<lint>(K + 1, limit));
    vector<vector<link>> node(N);

    int A, B, C;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        node[A - 1].push_back({B - 1, 0, C});
        node[B - 1].push_back({A - 1, 0, C});
    }

    priority_queue<link> pq;
    dis[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty())
    {
        int cc = pq.top().current;
        int cr = pq.top().road;
        lint cd = pq.top().distance;
        pq.pop();

        if (cd != dis[cc][cr]) continue;

        for (link nxt: node[cc])
        {
            int nc = nxt.current;
            lint nd = nxt.distance;

            if (cd + nd < dis[nc][cr])
            {
                dis[nc][cr] = cd + nd;
                pq.push({nc, cr, cd + nd});
            }
            if (cr + 1 > K) continue;
            if (cd < dis[nc][cr + 1])
            {
                dis[nc][cr + 1] = cd;
                pq.push({nc, cr + 1, cd});
            }
        }
    }

    lint answer = limit;
    for (int j = 0; j <= K; j++) answer = min(answer, dis[N - 1][j]);
    cout << answer;
    return 0;
}
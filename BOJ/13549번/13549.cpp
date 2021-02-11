#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 200000;
vector<int> dis;
struct link {
    int current;
    int time;
    bool operator<(const link &a) const { return time > a.time; }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N, K;
    cin >> N >> K;
    int E = max(N, K) + 2;
    dis.assign(E, INF);

    priority_queue<link > q;
    dis[N] = 0;
    q.push({N, dis[N]});

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();

        if (cur.time != dis[cur.current]) continue;

        int next = cur.current + 1;
        int next_distance = cur.time + 1;
        if (next < E && dis[next] > next_distance) {
            dis[next] = next_distance;
            q.push({next, dis[next]});
        }

        next = cur.current - 1;
        if (next >= 0 && dis[next] > next_distance) {
            dis[next] = next_distance;
            q.push({next, dis[next]});
        }

        next = cur.current * 2;
        if (next < E && dis[next] > cur.time) {
            dis[next] = cur.time;
            q.push({next, dis[next]});
        }
    }
    cout << dis[K];
    return 0;
}
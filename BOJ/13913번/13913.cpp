#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, K;
    cin >> N >> K;
    int limit = max(N, K) + 1;
    vector<int> res, dis(limit + 1, 1000000), pre(limit + 1);
    queue<int> q;

    dis[N] = 0;
    pre[N] = -1;

    q.push(N);
    while (!q.empty()) {
        int cur = q.front();q.pop();
        for (int nxt : {cur + 1, cur - 1, cur + cur}) {
            if (nxt <= limit and nxt >= 0) {
                if (dis[cur] + 1 < dis[nxt]) {
                    dis[nxt] = dis[cur] + 1;
                    pre[nxt] = cur;
                    q.push(nxt);
                }
            }
        }
    }
    cout << dis[K] << "\n";
    while (K >= 0) {
        res.push_back(K);
        K = pre[K];
    }
    reverse(res.begin(), res.end());
    for (auto result: res) cout << result << " ";
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> pre, time, res;
vector<vector<int> > nxt;
int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N;
    cin >> N;

    pre.assign(N + 1, 0);
    nxt.resize(N + 1);
    res.assign(N + 1, 0);
    time.resize(N + 1);

    int before;
    for (int i = 1; i <= N; i++) {
        cin >> time[i];

        while (true) {
            cin >> before;
            if (before == -1) break;
            nxt[before].push_back(i);
            pre[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (pre[i] == 0) {
            q.push(i);
            res[i] = time[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto target: nxt[cur]) {
            res[target] = max(res[target], res[cur] + time[target]);
            if (--pre[target] == 0) q.push(target);
        }
    }

    for (int i = 1; i <= N; i++) cout << res[i] << "\n";
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> wait(N + 2), res;
    vector<vector<int> > link(N + 2);
    
    int PD, P, before;
    while (M--) {
        cin >> PD;
        cin >> before;
        for (int i = 1; i < PD; i++) {
            cin >> P;
            link[before].push_back(P);
            wait[P]++;
            before = P;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) if (wait[i] == 0) q.push(i);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);

        for (auto nxt: link[cur]) if (--wait[nxt] == 0) q.push(nxt);
    }
    bool possible = true;
    for (int i = 1; i <= N; i++) if (wait[i] > 0) possible = false;

    if (possible) for (auto result: res) cout << result << "\n";
    else cout << 0;
    return 0;
}
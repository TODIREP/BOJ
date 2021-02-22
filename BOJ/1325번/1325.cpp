#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> cnt(N + 1), vis(N + 1, 0);
    vector<vector<int> > node(N + 1);

    int A, B;

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        node[B].push_back(A);
    }

    queue<int> q;

    int R = 0;
    for (int i = 1; i <= N; i++) {
        if (node[i].size() == 0) continue;

        q.push(i);
        int count = 1;
        vis[i] = i;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (auto nxt : node[cur]) {
                if (vis[nxt] == i) continue;
                count++;
                vis[nxt] = i;
                q.push(nxt);
            }
        }
        cnt[i] = count;
        R = max(R, cnt[i]);
    }
    
    for (int i = 1; i <= N; i++) {
        if (cnt[i] < R) continue;
        cout << i << " ";
    }
    return 0;
}
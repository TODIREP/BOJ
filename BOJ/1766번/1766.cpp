#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> root(N + 1, 0);
    vector<vector<int> > ord(N + 1);

    int A, B;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        ord[A].push_back(B);
        root[B]++;
    }

    priority_queue<int, vector<int>, greater<int> > q;

    for (int i = 1; i <= N; i++) {
        if (root[i] == 0) q.push(i);
    }

    vector<int> res;
    while (!q.empty()) {
        int cur = q.top();
        q.pop();
        res.push_back(cur);

        for (int nxt : ord[cur]) {
            if (--root[nxt] == 0) q.push(nxt);
        }
    }

    for (int result: res) cout << result << " ";
    return 0;
}
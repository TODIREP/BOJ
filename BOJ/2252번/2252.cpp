#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> indegree(N + 2), res;
    vector<vector<int > > node(N + 2);
    int A, B;
    while (M--) {
        cin >> A >> B;
        node[A].push_back(B);
        indegree[B]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) if (indegree[i] == 0) q.push(i);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);

        for (auto nxt: node[cur]) {
            if (--indegree[nxt] == 0) q.push(nxt);
        }
    }
    for (auto num: res) cout << num << " ";
    return 0;
}
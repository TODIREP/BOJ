#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, M, INF = 20000000;
    cin >> N >> M;
    vector<vector<int> > node(N + 1), root(N + 1);
    for (int i = 0; i < N; i++) {
        node[i].assign(N + 1, INF);
        root[i].assign(N + 1, -1);
        node[i][i] = 0;
    }
    
    int A, B, C;
    while (M--) {
        cin >> A >> B >> C;
        if (node[A - 1][B - 1] > C) {
            node[A - 1][B - 1] = C;
            root[A - 1][B - 1] = B - 1;
        }
    }

    for (int target = 0; target < N; target++) {
        for (int x = 0; x < N; x++) {
            if (x == target) continue;
            for (int y = 0; y < N; y++) {
                if (y == target) continue;

                if (node[x][y] > (node[x][target] + node[target][y])) {
                    node[x][y] = node[x][target] + node[target][y];
                    root[x][y] = root[x][target];
                }
            }
        }
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cout << (node[x][y] == INF ? 0 : node[x][y]) << " ";
        }
        cout << "\n";
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            vector<int> path;
            int cur = x, cnt = 0;

            while (cur != y && root[cur][y] >= 0) {
                path.push_back(cur);
                cur = root[cur][y];
                cnt++;
            } path.push_back(cur);
            
            if (cur == y && cnt > 0) {
                cout << cnt + 1 << " ";
                for (auto p: path) cout << p + 1 << " ";
                cout << "\n";
            } else cout << 0 << "\n";
        }
    }
    return 0;
}
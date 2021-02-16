#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, M, INF = 30000000;
    cin >> N >> M;

    vector<vector<int> > node(N + 1);
    for (int i = 0; i < N; i++) {
        node[i].assign(N + 1, INF);
        node[i][i] = 0;
    }

    int A, B, C;
    while (M--) {
        cin >> A >> B >> C;
        node[A - 1][B - 1] = min(node[A - 1][B - 1], C);
    }

    for (int target = 0; target < N; target++) {
        for (int x = 0; x < N; x++) {
            if (x == target) continue;
            for (int y = 0; y < N; y++) {
                if (y == target) continue;
                node[x][y] = min(node[x][y], node[x][target] + node[target][y]);
            }
        }
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cout << (node[x][y] == INF ? 0 : node[x][y]) << " ";
        }
        cout << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, INF = 30000;
    cin >> N;
    vector<vector<int> > node(N + 1);
    for (int x = 0; x < N; x++) {
        node[x].resize(N + 1);
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cin >> node[x][y];
            if (node[x][y] == 0) node[x][y] = INF;
        }
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
            cout << (node[x][y] == INF ? 0 : 1) << " ";
        }
        cout << "\n";
    }
    return 0;
}
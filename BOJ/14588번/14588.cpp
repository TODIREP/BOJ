#include <iostream>
#include <vector>
using namespace std;

bool cover(pair<int, int> prev, pair<int, int> cur) {
    if (cur.first <= prev.second && cur.first >= prev.first) return true;
    if (cur.second <= prev.second && cur.second >= prev.first) return true;
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, INF = 1000000;
    cin >> N;

    vector<vector<int> > node(N + 1);
    for (int i = 0; i < N; i++) {
        node[i].assign(N + 1, INF);
        node[i][i] = 0;
    }

    vector<pair<int,int> > input(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> input[i].first >> input[i].second;
        for (int j = i - 1; j >= 0; j--) {
            if (cover(input[j], input[i]) || cover(input[i], input[j])) {
                node[i][j] = node[j][i] = 1;
            }
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

    int Q;
    cin >> Q;

    int A, B;
    while (Q--) {
        cin >> A >> B;
        cout << (node[A - 1][B - 1] == INF ? -1 : node[A - 1][B - 1]) << "\n";
    }
    return 0;
}
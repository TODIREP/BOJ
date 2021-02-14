#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct link {
    int A, B, C;
    bool operator<(const link &a) const { return C < a.C; }
};
vector<int> root(7, -1);
vector<link> node;
vector<vector<int> > bridge;
vector<pair<int, int> > plan[7];
int find_root(int n);
bool union_root(int a, int b);
int get_distance(pair<int, int> a, pair<int, int> b);
bool valid(pair<int, int> a, pair<int, int> b);

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, M;
    cin >> N >> M;
    bridge.resize(N);
    for (int x = 0; x < N; x++) {
        bridge[x].resize(M);
        for (int y = 0; y < M; y++) {
            cin >> bridge[x][y];
        }
    }
    int current = 1;
    queue<pair<int, int> > bridge_q;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (bridge[x][y] == 0 || bridge[x][y] > 1) continue;
            bridge[x][y] = ++current;
            bridge_q.push({x, y});
            
            while (!bridge_q.empty()) {
                auto cur = bridge_q.front();
                bridge_q.pop();

                plan[current - 2].push_back(cur);

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if (bridge[nx][ny] == 0 || bridge[nx][ny] > 1) continue;

                    bridge[nx][ny] = current;
                    bridge_q.push({nx, ny});
                }
            }
        }
    }

    for (int x = 0; x < 5; x++) {
        for (auto xp: plan[x]) {
            for (int y = x + 1; y < 6; y++) {
                for (auto yp : plan[y]) {
                    if (!valid(xp, yp)) continue;
                    node.push_back({x, y, get_distance(xp, yp)});
                }
            }
        }
    }
    sort(node.begin(), node.end());

    int res = 0;
    for (auto L: node) {
        if (!union_root(L.A, L.B)) continue;
        res += L.C;
    }
    int count = 0;
    for (int i = 0; i < current - 1; i++) if (root[i] == -1) count++;
    cout << (count == 1 ? res : -1);
    return 0;
}

int find_root(int n) {
    if (root[n] < 0) return n;
    return root[n] = find_root(root[n]);
}

bool union_root(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) return false;
    root[b] = a;
    return true;
}

int get_distance(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return abs(a.second - b.second) - 1;
    return abs(a.first - b.first) - 1;
}

bool valid(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first && a.second != b.second) return false;
    if (a.first == b.first) {
        if (get_distance(a, b) <= 1) return false;

        int left = min(a.second, b.second), right = max(a.second, b.second);

        for (int idx = left + 1; idx < right; idx++) {
            if (bridge[a.first][idx] != 0) return false;
        }

    } else if (a.second == b.second) {
        if (get_distance(a, b) <= 1) return false;

        int left = min(a.first, b.first), right = max(a.first, b.first);

        for (int idx = left + 1; idx < right; idx++) {
            if (bridge[idx][a.second] != 0) return false;
        }
    }
    return true;
}
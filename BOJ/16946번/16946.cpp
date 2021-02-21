#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool rng(int x, int y, int n, int m) { return (x < 0 || x >= n || y < 0 || y >= m); }
vector<vector<pair<int, int> > > root;

pair<int, int> find_root(int x, int y) {
    if (root[x][y].first == -1 && root[x][y].second == -1) return {x, y};
    return root[x][y] = find_root(root[x][y].first, root[x][y].second);
}
bool union_root(pair<int, int> a, pair<int, int> b) {
    a = find_root(a.first, a.second);
    b = find_root(b.first, b.second);
    if (a.first == b.first && a.second == b.second) return false;
    root[b.first][b.second].first = a.first;
    root[b.first][b.second].second = a.second;
    return true;
}
bool check_root(pair<int, int> a, pair<int, int> b) {
    a = find_root(a.first, a.second);
    b = find_root(b.first, b.second);
    if (a.first == b.first && a.second == b.second) return false;
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, M;
    char input[1001];
    cin >> N >> M;

    vector<vector<int> > wall(N);
    vector<vector<bool> > vis(N);

    root.resize(N);
    for (int x = 0; x < N; x++) {
        wall[x].resize(M);
        root[x].resize(M);
        vis[x].assign(M, false);
        cin >> input;
        for (int y = 0; y < M; y++) {
            wall[x][y] = input[y] - '0';
            root[x][y] = {-1, -1};
        }
    }

    stack<pair<int, int> > stk, label;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (vis[x][y] || wall[x][y] == 1) continue;
            vis[x][y] = true;
            int count = -1;

            stk.push({x, y});

            while (!stk.empty()) {
                auto cur = stk.top();stk.pop();
                label.push(cur);

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (rng(nx, ny, N, M) || vis[nx][ny]) continue;
                    if (wall[nx][ny] != 0) continue;

                    count--;
                    vis[nx][ny] = true;
                    stk.push({nx, ny});
                }
            }

            if (label.empty()) continue;
            auto parrent = label.top();label.pop();
            wall[parrent.first][parrent.second] = count;

            while (!label.empty()) {
                auto cur = label.top();label.pop();
                bool r = union_root(parrent, cur);
                wall[cur.first][cur.second] = count;
            }
        }
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (wall[x][y] != 1) continue;
            int sum = 1;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (rng(nx, ny, N, M)) continue;
                if (wall[nx][ny] > 0) continue;

                bool valid = true;
                for (int nxt = dir - 1; nxt >= 0; nxt--) {
                    int nx2 = x + dx[nxt];
                    int ny2 = y + dy[nxt];

                    if (rng(nx2, ny2, N, M)) continue;
                    if (wall[nx][ny] > 0) continue;
                    if (!check_root({nx2, ny2}, {nx, ny})) valid = false;
                }

                if (valid) sum += (wall[nx][ny] * -1) % 10;
            }

            wall[x][y] = sum % 10;
        }
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            cout << (wall[x][y] > 0 ? wall[x][y] : 0);
        }
        cout << '\n';
    }

    return 0;
}
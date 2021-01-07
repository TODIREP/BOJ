#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> arr;
int N, M, wall_cnt = 0, result = -1, count;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS() {
    queue<pair<int, int>> q;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (arr[x][y] == 2) {
                q.push({x, y});

                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (arr[nx][ny] != 0) continue;

                        arr[nx][ny] = 4;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (arr[x][y] == 0) count++;
            else if (arr[x][y] == 4) arr[x][y] = 0;
        }
    }
    result = count >= result ? count : result;
}

void wall() {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (arr[x][y] != 0) continue;
            arr[x][y] = 3;
            wall_cnt++;
            if (wall_cnt == 3) {
                count = 0;
                BFS();
            } else {
                wall();
            }
            arr[x][y] = 0;
            wall_cnt--;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    arr.resize(N);

    for (int x = 0; x < N; x++) {
        arr[x].resize(M);
        for (int y = 0; y < M; y++) {
            cin >> arr[x][y];
        }
    }
    wall();
    cout << result;
    return 0;
}
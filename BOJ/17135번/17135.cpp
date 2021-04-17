#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define min(x, y) (x < y ? x : y);
#define max(x, y) (x > y ? x : y);

int N, M, D, answer = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> castle, turn;
pair<int, int> archer[3];
pair<int, int> target(pair<int, int> &attack) {
    vector<vector<int>> dis(N + 1, vector<int>(M, 300));
    queue<pair<int, int>> q;
    dis[attack.first][attack.second] = 0;
    q.push(attack);

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
            if (dis[nx][ny] <= dis[cx][cy] + 1) continue;
            dis[nx][ny] = dis[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
    int rx = -1, ry = -1, rd = 300;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (turn[x][y]) {
                if (dis[x][y] <= D) {
                    if (dis[x][y] < rd) {
                        rx = x;
                        ry = y;
                        rd = dis[x][y];
                    } else if (dis[x][y] == rd) {
                        if (y < ry) {
                            rx = x;
                            ry = y;
                        }
                    }
                }
            }
        }
    }
    return {rx, ry};
}
bool valid() {
    bool val = false;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (turn[x][y]) val = true;
        }
    }
    return val;
}
int play() {
    int temp = 0;
    while (valid()) {
        vector<pair<int, int>> kill(3);
        for (int index = 0; index < 3; index++) {
            kill[index] = target(archer[index]);
        }
        for (int index = 0; index < 3; index++) {
            int kx = kill[index].first;
            int ky = kill[index].second;
            if (kx == -1 or ky == -1) continue;

            if (turn[kx][ky]) {
                turn[kx][ky] = 0;
                temp++;
            }
        }
        for (int x = N - 1; x > 0; x--) {
            for (int y = 0; y < M; y++) {
                turn[x][y] = turn[x - 1][y];
            }
        }
        for (int y = 0; y < M; y++) {
            turn[0][y] = 0;
        }
    }
    return temp;
}
void search(int cur, int cnt) {
    if (cnt == 3) {
        turn = castle;
        int played = play();
        answer = max(answer, played);
        return;
    }
    for (int index = cur; index < M; index++) {
        archer[cnt] = {N, index};
        search(index + 1, cnt + 1);
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> D;
    castle.assign(N, vector<int>(M));

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            cin >> castle[x][y];
        }
    }
    search(0, 0);
    cout << answer;
    return 0;
}
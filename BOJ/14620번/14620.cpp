#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> map;
vector<vector<bool>> visit;
int N, result = 10000000, count = 0, sum = 0;

void search() {
    if (count == 3) {
        result = sum < result ? sum : result;
        return;
    }
    for (int x = 1; x < N - 1; x++) {
        for (int y = 1; y < N - 1; y++) {
            if (visit[x][y]) continue;
            bool valid = true;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (visit[nx][ny]) {
                    valid = false;
                    break;
                }
            }

            int temp = 0;
            if (valid) {
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    visit[nx][ny] = true;
                    temp += map[nx][ny];
                }
                visit[x][y] = true;
                temp += map[x][y];
                sum += temp;
                count++;
            } else continue;
            search();
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                visit[nx][ny] = false;
            }
            visit[x][y] = false;
            sum -= temp;
            count--;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    map.resize(N);
    visit.resize(N);
    for (int x = 0; x < N; x++) {
        map[x].resize(N);
        visit[x].assign(N, false);
        for (int y = 0; y < N; y++) {
            cin >> map[x][y];
        }
    }
    search();
    cout << result;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int answer = 0;
void assemble(int sx, int sy, vector<vector<int>> &world, vector<int> &dir, vector<pair<int, int>> &pos) {
    for (int cur = 0; cur < 16; cur++) {
        int cur_dis = dir[cur];
        if (cur_dis == -1) continue;
        int cx = pos[cur].first;
        int cy = pos[cur].second;

        for (int next = 0; next < 8; next++) {
            int nx = cx + dx[cur_dis];
            int ny = cy + dy[cur_dis];

            if (nx < 0 or nx >= 4 or ny < 0 or ny >= 4 or (nx == sx and ny == sy)) {
                cur_dis = (cur_dis + 1) % 8;
            } else {
                dir[cur] = cur_dis;
                pos[cur] = {nx, ny};
                int next_num = world[nx][ny];
                world[cx][cy] = next_num;
                world[nx][ny] = cur;
                if (next_num != -1) {
                    pos[next_num] = {cx, cy};
                }
                break;
            }
        }
    }
}
void search(int cx, int cy, int cd, int number, vector<vector<int>> world, vector<int> dir, vector<pair<int, int>> pos) {
    assemble(cx, cy, world, dir, pos);

    for (int delta = 1; delta < 4; delta++) {
        int nx = cx + dx[cd] * delta;
        int ny = cy + dy[cd] * delta;

        if (nx < 0 or nx >= 4 or ny < 0 or ny >= 4) break;
        if (world[nx][ny] == -1) continue;
        int num = world[nx][ny];
        int num_dir = dir[num];
        dir[num] = -1;
        world[nx][ny] = -1;
        search(nx, ny, num_dir, number + num + 1, world, dir, pos);
        dir[num] = num_dir;
        world[nx][ny] = num;
    }
    answer = (answer > number ? answer : number);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;
    vector<vector<int>> fish(4, vector<int>(4));
    vector<int> direction(16);
    vector<pair<int, int>> position(16);
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            cin >> a >> b;
            fish[x][y] = a - 1;
            direction[a - 1] = b - 1;
            position[a - 1] = {x, y};
        }
    }
    int num = fish[0][0];
    int num_dir = direction[num];
    direction[num] = -1;
    fish[0][0] = -1;
    search(0, 0, num_dir, num + 1, fish, direction, position);
    cout << answer;
    return 0;
}
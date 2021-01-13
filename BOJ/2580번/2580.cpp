#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<bool>> row;
vector<vector<bool>> col;
vector<vector<bool>> sqr;
vector<pair<int, int>> target;
vector<vector<int>> map;
int N;
bool finish = false;

void search() {
    for (int index = 0; index < N; index++) {
        auto cur = target[index];
        int x = cur.first;
        int y = cur.second;
        if (map[x][y] > 0) continue;

        for (int num = 1; num <= 9; num++) {
            if (sqr[(x / 3) * 3 + (y / 3)][num] || row[x][num] || col[y][num]) continue;
            map[x][y] = num;
            sqr[(x / 3) * 3 + (y / 3)][num] = true;
            row[x][num] = true;
            col[y][num] = true;
            if (index == N - 1) {
                finish = true;
                return;
            }
            search();
            if (finish) return;
            map[x][y] = 0;
            sqr[(x / 3) * 3 + (y / 3)][num] = false;
            row[x][num] = false;
            col[y][num] = false;
        }
        return;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int input;
    sqr.resize(10);
    map.resize(10);
    row.resize(10);
    col.resize(10);

    for (int x = 0; x < 9; x++) {
        map[x].resize(11);
        sqr[x].assign(11, false);
        row[x].assign(11, false);
        col[x].assign(11, false);
    }

    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            cin >> input;
            map[x][y] = input;
            if (input != 0) {
                sqr[(x / 3) * 3 + (y / 3)][input] = true;
                row[x][input] = true;
                col[y][input] = true;
            } else {
                target.push_back({x, y});
            }
        }
    }
    N = target.size();

    search();
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            cout << map[x][y] << " ";
        }
        cout << "\n";
    }
    return 0;
}
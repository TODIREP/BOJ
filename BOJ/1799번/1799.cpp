#include <iostream>
using namespace std;

bool visit[21], visit2[21];
int map[11][11], N, result[2];

void search(int x, int y, int count, int center) {
    if (y >= N) y = ((++x % 2) + center) % 2;
    if (x >= N) {
        result[center] = max(result[center], count);
        return;
    }

    if (map[x][y] == 0 || visit[x + y] || visit2[x - y + N - 1]) return search(x, y + 2, count, center);
    visit[x + y] = true;
    visit2[x - y + N - 1] = true;
    search(x, y + 2, count + 1, center);
    visit[x + y] = false;
    visit2[x - y + N - 1] = false;
    return search(x, y + 2, count, center);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cin >> map[x][y];
        }
    }
    search(0, 0, 0, 0);
    search(0, 1, 0, 1);
    cout << result[0] + result[1];
    return 0;
}
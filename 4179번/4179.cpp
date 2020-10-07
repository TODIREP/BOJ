#include <cstdio>
#include <queue>
using namespace std;

#define scale 1001
#define position pair<int, int>
#define X first
#define Y second
int fire[scale][scale];
int people[scale][scale];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    int dis = 1001;
    char input[1001];
    scanf("%d%d", &n, &m);
    queue<position> firePos;
    queue<position> peoplePos;
    for (int x = 0; x < n; x++) {
        scanf("%s", input);
        for (int y = 0; input[y] != '\0'; y++) {
            if (input[y] == '#') {
                fire[x][y] = -1;
                people[x][y] = -1;
            }
            else if (input[y] == '.') {
                fire[x][y] = 0;
                people[x][y] = 0;
            }
            else if (input[y] == 'J') {
                people[x][y] = 1;
                peoplePos.push({x, y});
            }
            else if (input[y] == 'F') {
                fire[x][y] = 1;
                firePos.push({x, y});
            }
        }
    }
    while (!firePos.empty()) {
        position start = firePos.front();
        firePos.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = start.X + dx[dir];
            int ny = start.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (fire[nx][ny] == -1 || fire[nx][ny] != 0) continue;

            fire[nx][ny] = fire[start.X][start.Y] + 1;
            firePos.push({nx, ny});
        }
    }
    while (!peoplePos.empty()) {
        position start = peoplePos.front();
        peoplePos.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = start.X + dx[dir];
            int ny = start.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (people[nx][ny] == -1 || people[nx][ny] != 0) continue;

            people[nx][ny] = people[start.X][start.Y] + 1;
            peoplePos.push({nx, ny});
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
                if ((fire[x][y] > people[x][y] || fire[x][y] == 0) && people[x][y] > 0) {
                    if (dis > people[x][y]) dis = people[x][y];
                }
            } else continue;
        }
    }
    if (dis == 1001) {
        printf("IMPOSSIBLE");
    } else {
        printf("%d", dis);
    }
    return 0;
}
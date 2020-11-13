#include <cstdio>
#include <queue>
using namespace std;

#define X first
#define Y second
#define position pair<int, int>

int chone[101][101];
bool check[101][101];
int dis[101];
int N, a, b, M, p, q;

int main(void) {
    scanf("%d%d%d%d", &N, &a, &b, &M);
    queue<position> data;
    for (int index = 0; index < M; index++) {
        scanf("%d%d", &p, &q);
        chone[p - 1][q - 1] = 1;
        chone[q - 1][p - 1] = 1;
    }
    for (int index = 0; index < N; index++) {
        if (chone[a - 1][index] == 1) {
            check[a - 1][index] = 1;
            check[index][a - 1] = 1;
            data.push({index, a - 1});
        }
    }
    while (!data.empty()) {
        position cur = data.front();
        data.pop();
        if (dis[cur.X] == 0) {
            dis[cur.X] = chone[cur.X][cur.Y];
        }
        for (int index = 0; index < N; index++) {
            if (check[cur.X][index] == 1) continue;
            if (chone[cur.X][index] == 0 || chone[cur.X][index] != 1) continue;

            check[cur.X][index] = 1;
            check[index][cur.X] = 1;
            chone[cur.X][index] = chone[cur.X][cur.Y] + 1;
            chone[index][cur.X] = chone[cur.X][index];
            data.push({index, cur.X});
        }
    }
    printf("%d", dis[b - 1] ? dis[b - 1] : -1);
    return 0;
}
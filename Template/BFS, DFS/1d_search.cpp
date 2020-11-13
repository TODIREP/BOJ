#include <cstdio>
#include <queue>
using namespace std;

#define scale 101

int map[scale];
bool visit[scale];
int dx[2] = {1, -1};
int N;

int main(void) {
/*
예제 입력
10
0 0 1 0 0 1 0 0 0 1
*/
    scanf("%d", &N);
    queue<int> data;
    for (int index = 0; index < N; index++) {
        scanf("%d", map + index);
        if (map[index] == 1) {
            data.push(index);
        }
    }

    while(!data.empty()) {
        auto current = data.front();
        data.pop();
        visit[current] = 1;

        for (int dir = 0; dir < 2; dir++) {
            int nx = current + dx[dir];

            if (nx < 0 || nx >= N) continue;
            if (visit[nx]) continue;

            visit[nx] = 1;
            map[nx] = map[current] + 1;
            data.push(nx);
        }
    }
/*
예제 출력
3 2 1 2 2 1 2 3 2 1
*/
    for (int index = 0; index < N; index++) {
        printf("%d ", map[index]);
    }
    return 0;
}
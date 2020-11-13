#include <cstdio>
#include <queue>
using namespace std;

#define scale 100002
int road[scale];
int dx[2] = {1, -1};
int N, K;
int main(void) {
    scanf("%d%d", &N, &K);
    queue<int> data;
    data.push(N);

    while (!data.empty()) {
        auto current = data.front();
        data.pop();
        if (current == K) break;
        for (int dir = 0; dir < 2; dir++) {
            int nx = current + dx[dir];
            if (nx < 0 || nx > scale) continue;
            if (nx == N) continue;
            if (road[nx] < road[current] + 1 && road[nx] != 0) continue;
            road[nx] = road[current] + 1;
            data.push(nx);
        }
        int nx = current * 2;
        if (nx > scale) continue;
        if (nx == N) continue;
        if (road[nx] < road[current] + 1 && road[nx] != 0) continue;
        road[nx] = road[current] + 1;
        data.push(nx);
    }
    printf("%d\n", road[K]);
    return 0;
}
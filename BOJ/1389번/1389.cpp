#include <cstdio>

int map[101][101];
int MAX = 100000000;
int main(void) {
    int N, M, a, b, answer = 120, answer_sum = MAX, sum;
    scanf("%d%d",&N, &M);

    for (int index = 0; index < M; index++) {
        scanf("%d%d", &a, &b);
        map[a - 1][b - 1] = 1;
        map[b - 1][a - 1] = 1;
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (map[x][y] != 1 && x != y) {
                map[x][y] = MAX;
            }
        }
    }

    for (int t = 0; t < N; t++) {
        for (int x = 0; x < N; x++) {
            if (x == t) continue;
            for (int y = 0; y < N; y++) {
                if (y == t || x == y) continue;
                if (map[x][y] > (map[x][t] + map[t][y])) map[x][y] = map[x][t] + map[t][y];
            }
        }
    }

    for (int x = 0; x < N; x++) {
        sum = 0;
        for (int y = 0; y < N; y++) {
            sum += map[x][y];
        }
        if (sum < answer_sum) {
            answer = x + 1;
            answer_sum = sum;
        }
    }
    printf("%d", answer);
    return 0;
}
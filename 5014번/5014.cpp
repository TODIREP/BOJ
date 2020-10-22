#include <cstdio>
#include <queue>
using namespace std;

int floors[1000002];
int lift[2];
int F,S,G;
int main(void) {
    scanf("%d%d%d%d%d", &F, &S, &G, &lift[0], &lift[1]);
    queue<int> data;
    lift[1] = lift[1] * (-1);
    floors[S] = 1;
    data.push(S);

    while(!data.empty()) {
        int current = data.front();
        data.pop();
        if (current == G) break;
        for (int dir = 0; dir < 2; dir++) {
            int nf = current + lift[dir];

            if (nf <= 0 || nf > F) continue;
            if (floors[nf] != 0 && floors[nf] < floors[current] + 1) continue;
            if (floors[nf] != 0) continue;
            floors[nf] = floors[current] + 1;
            data.push(nf);
        }
    }
    if (floors[G] == 0) {
        printf("use the stairs");
    } else {
        printf("%d", floors[G] - 1);
    }
    return 0;
}
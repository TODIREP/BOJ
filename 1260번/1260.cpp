#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

#define X first
#define Y second
#define position pair<int, int>
int N, M, V, a, b;
int map[1001][1001];
int visit[1001];

int main(void) {
    scanf("%d%d%d", &N, &M, &V);
    for (int index = 0; index < M; index++) {
        scanf("%d%d", &a, &b);
        map[a - 1][b - 1] = 1;
        map[b - 1][a - 1] = 1;
    }
    queue<position> Q;
    stack<position> S;
    queue<int> result;
    queue<int> result2;

    visit[V - 1] += 2;
    result.push(V);
    result2.push(V);

    for (int index = 0; index < N; index++) {
        if (map[V - 1][index] == 1) {
            Q.push({V - 1, index});
            break;
        }
    }
    for (int index = N - 1; index >= 0; index--) {
        if (map[V - 1][index] == 1) {
            S.push({V - 1, index});
            break;
        }
    }

    while(!S.empty()) {
        position cur = S.top();
        S.pop();
        if (visit[cur.X] == 0) {
            visit[cur.X]++;
            result.push(cur.X + 1);
        }
        for (int dir = N - 1; dir >= 0; dir--) {
            if (map[cur.X][dir] != 1) continue;

            map[cur.X][dir]++;
            map[dir][cur.X]++;
            S.push({dir, cur.X});
        }
    }
    while(!result.empty()) {
        int value = result.front();
        result.pop();
        printf("%d ", value);
    }
    printf("\n");

    while(!Q.empty()) {
        position cur = Q.front();
        Q.pop();
        if (visit[cur.X] == 1) {
            visit[cur.X]++;
            result2.push(cur.X + 1);
        }
        for (int dir = 0; dir < N; dir++) {
            if (map[cur.X][dir] != 2) continue;
            
            map[cur.X][dir]++;
            map[dir][cur.X]++;
            Q.push({dir, cur.X});
        }
    }
    while(!result2.empty()) {
        int value = result2.front();
        result2.pop();
        printf("%d ", value);
    }
    return 0;
}
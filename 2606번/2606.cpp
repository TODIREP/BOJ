#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
#define position pair<int, int>
int N, K, a, b;
int network[101][101];
bool isDead[101];

int main(void) {
    int answer = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int index = 0; index < K; index++) {
        cin >> a >> b;
        network[a - 1][b - 1] = 1;
        network[b - 1][a - 1] = 1;
    }
    queue<position> data;
    for (int index = 0; index < N; index++) {
        if (network[0][index] == 1) {
            data.push({0, index});
            isDead[0] = 1;
            break;
        }
    }
    while(!data.empty()) {
        position cur = data.front();
        data.pop();
        if (isDead[cur.X] == 0) {
            isDead[cur.X] = 1;
            answer++;
        }
        for (int dir = 0; dir < N; dir++) {
            if (network[cur.X][dir] == 0) continue;

            network[cur.X][dir] = 0;
            network[dir][cur.X] = 0;
            data.push({dir, cur.X});
        }
    }
    cout << answer;
    return 0;
}
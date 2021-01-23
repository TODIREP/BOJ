#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int music[101];
bool volume[101][1002];
int main(void) {
    fastio();
    int N, S, M, res;
    cin >> N >> S >> M;
    for (int index = 0; index < N; index++) cin >> music[index];

    for (int index = 0; index < N; index++) {
        if (index == 0) {
            if (S + music[index] <= M) volume[index][S + music[index]] = true;
            if (S - music[index] >= 0) volume[index][S - music[index]] = true;
        } else {
            for (int V = 0; V <= M; V++) {
                if (!volume[index - 1][V]) continue;
                if (V + music[index] <= M) volume[index][V + music[index]] = true;
                if (V - music[index] >= 0) volume[index][V - music[index]] = true;
            }
        }
    }
    res = -1;
    for (int V = 0; V <= M; V++) if (volume[N - 1][V]) res = max(res, V);
    cout << res;
    return 0;
}
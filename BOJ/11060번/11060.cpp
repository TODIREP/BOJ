#include <iostream>
#include <vector>
using namespace std;
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

vector<int> miro, jmp;
int main(void) {
    fastio();
    int N;
    cin >> N;
    miro.resize(N);
    jmp.assign(N, -1);
    for (int index = 0; index < N; index++) cin >> miro[index];

    jmp[0] = 0;
    for (int index = 0; index < N; index++) {
        for (int K = 1; K <= miro[index]; K++) {
            if (index + K >= N || jmp[index] == -1) break;
            if (jmp[index + K] == -1) jmp[index + K] = jmp[index] + 1;
            else jmp[index + K] = min(jmp[index + K], jmp[index] + 1);
        }
    }
    cout << jmp[N - 1];
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int dool[1002];
void play(int N, int win) {
    if (N < 0) return;
    if (dool[N] != -1) return;
    dool[N] = win;
    int next = (win + 1) % 2;
    play(N - 3, next);
    play(N - 1, next);
    return;
}

int main(void) {
    fastio();
    int N;
    cin >> N;
    fill(dool, dool + 1002, -1);
    play(N, 1);
    cout << (dool[1] ? "SK" : "CY");
    return 0;
}
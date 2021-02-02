#include <iostream>
#include <map>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

int main(void) {
    fastio;
    int N, M, input;
    map<int, int> card;
    cin >> N;
    for (int index = 0; index < N; index++) {
        cin >> input;
        if (card[input] > 0) card[input]++;
        else card[input] = 1;
    }
    cin >> M;
    for (int index = 0; index < M; index++) {
        cin >> input;
        cout << card[input] << " ";
    }
    return 0;
}
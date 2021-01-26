#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main(void) {
    fastio;
    int N, card[1001];
    cin >> N;
    for (int index = 0; index < N; index++) cin >> card[index];
    int price[1001];
    for (int index = 0; index <= N; index++) price[index] = (int) 1e8;
    price[0] = 0;

    for (int index = 0; index < N; index++) {
        for (int next = index + 1; next <= N; next++) price[next] = min(price[next], price[next - index - 1] + card[index]);
    }
    cout << price[N];
    return 0;
}
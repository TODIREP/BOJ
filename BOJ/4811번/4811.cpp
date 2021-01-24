#include <iostream>
using namespace std;
#define lint long long
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

lint med[62][32][2];
int main(void) {
    fastio();
    int N;
    med[1][1][0] = 1;
    for (int index = 2; index <= 60; index++) {
        for (int date = index / 2; date <= index; date++) {
            if (date > 1) med[index][date][0] = med[index - 1][date - 1][0] + med[index - 1][date - 1][1];
            if (date * 2 >= index) med[index][date][1] = med[index - 1][date][0] + med[index - 1][date][1];
        }
    }
    while (true) {
        cin >> N;
        if (N == 0) return 0;
        cout << med[2 * N][N][1] << "\n";
    }
}
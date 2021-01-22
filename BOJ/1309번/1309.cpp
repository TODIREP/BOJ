#include <iostream>
using namespace std;
#define mod 9901
#define plus(a, b) (a + b) % mod
#define print(a) cout << a;

int cage[100001][3];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    cage[0][0] = 1; cage[0][1] = 1; cage[0][2] = 1;
    for (int index = 1; index < N; index++) {
        cage[index][0] = plus(cage[index - 1][0], plus(cage[index - 1][1], cage[index - 1][2]));
        cage[index][1] = plus(cage[index - 1][0], cage[index - 1][2]);
        cage[index][2] = plus(cage[index - 1][0], cage[index - 1][1]);
    }
    print(plus(cage[N - 1][0], plus(cage[N - 1][1], cage[N - 1][2])));
    return 0;
}
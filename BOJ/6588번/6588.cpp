#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define MAX (int) 1e6 + 1

bool sosu[MAX];
int main(void) {
    fastio();
    int N;
    for (int index = 3; index < MAX; index += 2) {
        if (sosu[index]) continue;
        for (int next = 3; index * next < MAX; next += 2) {
            if (sosu[index * next]) continue;
            sosu[index * next] = true;
        }
    }
    while (true) {
        bool find = true;
        cin >> N;
        if (N == 0) return 0;
        for (int num = 3; num <= N / 2; num += 2) {
            if (sosu[num] || sosu[N - num]) continue;
            cout << N << " = " << num << " + " << N - num << "\n";
            find = false;
            break;
        }
        if (find) cout << "Goldbach's conjecture is wrong.\n";
    }
}
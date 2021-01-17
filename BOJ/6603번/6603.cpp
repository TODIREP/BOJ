#include <iostream>
using namespace std;

int N, target[7], num[13];
bool used[13];

void search(int start, int count) {
    if (count == 6) {
        for (int index = 0; index < 6; index++) cout << target[index] << " ";
        cout << "\n";
        return;
    }
    for (int index = start; index < N; index++) {
        if (used[index]) continue;
        used[index] = true;
        target[count] = num[index];
        search(index + 1, count + 1);
        used[index] = false;
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        cin >> N;
        if (N == 0) return 0;
        for (int index = 0; index < N; index++) cin >> num[index];
        search(0, 0);
        cout << "\n";
    }
}
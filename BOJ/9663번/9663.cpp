#include <iostream>
using namespace std;

int result = 0, count = 0, N;
bool visit1[16], visit2[16], visit3[30], visit4[30];

void search(int startx) {
    for (int x = startx; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (visit1[x] || visit2[y] || visit3[x - y + N - 1] || visit4[x + y - 2]) continue;
            visit1[x] = true;
            visit2[y] = true;
            visit3[x - y + N - 1] = true;
            visit4[x + y - 2] = true;
            count++;
            if (count == N) result++;
            search(x + 1);
            visit1[x] = false;
            visit2[y] = false;
            visit3[x - y + N - 1] = false;
            visit4[x + y - 2] = false;
            count--;
        }
        return;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    search(0);
    cout << result;
    return 0;
}
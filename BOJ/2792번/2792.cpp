#include <iostream>
using namespace std;

int color[300001];
int main(void) {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int N, M, left = 1, right = 0;
    cin >> N >> M;

    for (int index = 0; index < M; index++) {
        cin >> color[index];
        right = max(right, color[index]);
    }

    while (left < right) {
        int mid = (left + right) / 2;

        int value = 0;
        for (int index = 0; index < M; index++)
            value += color[index] / mid + (color[index] % mid > 0);
        if (value <= N) right = mid;
        else left = mid + 1;
    }
    cout << left;
    return 0;
}
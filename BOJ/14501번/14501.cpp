#include <iostream>
using namespace std;
#define duration first
#define reward second
pair<int, int> work[16];
int pay[16];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, result = 0;
    cin >> N;
    for (int index = 0; index < N; index++) cin >> work[index].duration >> work[index].reward;

    for (int index = 0; index < N; index++) {
        int before = 0;
        for (int prev = index - 1; prev >= 0; prev--) {
            if (prev + work[prev].duration <= index) before = max(before, pay[prev]);
        }
        if (index + work[index].duration > N) continue;
        if (before == 0) pay[index] = work[index].reward;
        else pay[index] = before + work[index].reward;
        result = max(result, pay[index]);
    }
    cout << result;
    return 0;
}
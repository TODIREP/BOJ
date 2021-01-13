#include <iostream>
#include <vector>
using namespace std;

vector<bool> btn;
int N, M, c_len = 0, result, count = 0;
int cur = 0, level = 1;

void search() {
    if (count == c_len + 1) return;
    for (int index = 0; index < 10; index++) {
        if (btn[index]) continue;
        cur += level * index;
        level *= 10;
        count++;
        if (cur == N) result = min(result, count);
        else result = min(result, abs(cur - N) + count);
        search();
        count--;
        level /= 10;
        cur -= level * index;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int input;
    cin >> N >> M;
    input = N;
    if (N == 0) c_len++;
    while (input > 0) {
        c_len++;
        input /= 10;
    }
    result = abs(100 - N);
    btn.assign(11, false);
    for (int index = 0; index < M; index++) {
        cin >> input;
        btn[input] = true;
    }
    search();
    cout << result;
    return 0;
}
#include <iostream>
using namespace std;

int num[9], number[9];
bool visit[9];
int N, count = 0, result = -1;

void search() {
    if (count == N) {
        int sum = 0;
        for (int index = 0; index < N - 1; index++)
            sum += abs(number[index] + (-1) * number[index + 1]);
        result = max(result, sum);
        return;
    }
    for (int index = 0; index < N; index++) {
        if (visit[index]) continue;
        visit[index] = true;
        number[count++] = num[index];
        search();
        visit[index] = false;
        count--;
    }
}

int main(void) {
    cin >> N;
    for (int index = 0; index < N; index++) cin >> num[index];
    search();
    cout << result;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int N, S, answer = 0, sum = 0;
vector<int> target;
vector<bool> visit;

void check(int cur) {
    for (int index = cur; index < N; index++) {
        if (!visit[index]) {
            visit[index] = true;
            sum += target[index];

            if (sum == S) {
                answer++;
            }
            check(index + 1);
            visit[index] = false;
            sum -= target[index];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int input;
    cin >> N >> S;

    visit.assign(N, false);
    target.resize(N);
    for (int index = 0; index < N; index++) {
        cin >> target[index];
    }
    check(0);
    cout << answer;
    return 0;
}
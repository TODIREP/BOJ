#include <iostream>
#include <queue>
using namespace std;

struct cake {
    bool ten;
    int cut, gain;
    bool operator<(const cake &a) const {
        if (ten == a.ten) {
            if (cut == a.cut) return gain < a.gain;
            return cut > a.cut;
        }
        return ten < a.ten;
    }
};

int main(void) {
    int N, M, num, answer = 0;
    cin >> N >> M;

    priority_queue<cake> q;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num < 10) continue;
        if (num == 10) answer++;
        else q.push({num % 10 == 0, num / 10 - (num % 10 == 0), num / 10});
    }

    while (!q.empty()) {
        if (M == 0) break;
        auto cur = q.top();q.pop();

        if (M - cur.cut >= 0) {
            M -= cur.cut;
            answer += cur.gain;
        } else {
            answer += M;
            M = 0;
        }
    }
    cout << answer;
    return 0;
}
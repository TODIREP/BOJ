#include <iostream>
#include <queue>
using namespace std;

struct number {
    int num;
    bool operator<(const number &a) const {
        if (abs(num) == abs(a.num)) return num > a.num;
        return abs(num) > abs(a.num);
    }
};
int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, num;
    cin >> N;

    priority_queue<number> q;
    while (N--) {
        cin >> num;

        if (num == 0) {
            if (q.empty()) cout << 0;
            else {
                cout << q.top().num;
                q.pop();
            }
            cout << "\n";
        } else q.push({num});
    }
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

typedef long long lint;
struct number {
    lint num;
    bool operator<(const number &a) const { return num > a.num; }
};

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N, num;
        cin >> N;
        
        priority_queue<number> q;
        for (int i = 0; i < N; i++) {
            cin >> num;
            q.push({num});
        }

        lint ans = 0;
        while (q.size() >= 2) {
            lint a = q.top().num;q.pop();
            lint b = q.top().num;q.pop();

            ans += a + b;
            q.push({a + b});
        }
        cout << ans << "\n";
    }
    return 0;
}
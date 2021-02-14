#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct link {
    int A, B, C;
    bool operator<(const link &a) const { return C < a.C; }
};
int find_root(vector<int> &r, int n) {
    if (r[n] < 0) return n;
    return r[n] = find_root(r, r[n]);
}
bool union_root(vector<int> &r, int a, int b) {
    a = find_root(r, a);
    b = find_root(r, b);
    if (a == b) return false;
    r[b] = a;
    return true;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> root(N + 2, -1);
    vector<link> computer;

    int A, B, C;
    for (int i = 1; i <= M; i++) {
        cin >> A >> B >> C;
        computer.push_back({A, B, C});
    }
    sort(computer.begin(), computer.end());

    int res = 0;
    for (auto cur: computer) {
        if (!union_root(root, cur.A, cur.B)) continue;
        res += cur.C;
    }
    cout << res;
    return 0;
}
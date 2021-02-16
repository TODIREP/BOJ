#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct link {
    int A, B, C;
    bool operator<(const link &a) const { return C > a.C; }
};
vector<int> root;
int find_root(int n) {
    if (root[n] < 0) return n;
    return root[n] = find_root(root[n]);
}
bool union_root(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) return false;
    root[b] = a;
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N, M;
    cin >> N >> M;
    root.assign(N + 2, -1);

    int A, B, C;
    priority_queue<link> q;
    while (M--) {
        cin >> A >> B >> C;
        q.push({A, B, C});
    }

    int ans = 0, cut = 0;
    while (!q.empty()) {
        auto cur = q.top();q.pop();
        if (!union_root(cur.A, cur.B)) continue;
        cut = max(cut, cur.C);
        ans += cur.C;
    }
    cout << ans - cut;
    return 0;
}
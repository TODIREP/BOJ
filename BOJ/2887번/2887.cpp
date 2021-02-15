#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long lint;

struct link {
    int A, B;
    lint C;
    bool operator<(const link &a) const { return C < a.C; }
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
vector<link> node;
vector<pair<int, int> > x_node, y_node, z_node;
int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N;
    cin >> N;
    root.assign(N + 2, -1);

    lint X, Y, Z;
    for (int i = 0; i < N; i++) {
        cin >> X >> Y >> Z;
        x_node.push_back({X, i});
        y_node.push_back({Y, i});
        z_node.push_back({Z, i});
    }
    sort(x_node.begin(), x_node.end());
    sort(y_node.begin(), y_node.end());
    sort(z_node.begin(), z_node.end());

    for (int i = 0; i < N - 1; i++) {
        node.push_back({x_node[i].second, x_node[i + 1].second, x_node[i + 1].first - x_node[i].first});
        node.push_back({y_node[i].second, y_node[i + 1].second, y_node[i + 1].first - y_node[i].first});
        node.push_back({z_node[i].second, z_node[i + 1].second, z_node[i + 1].first - z_node[i].first});
    }
    sort(node.begin(), node.end());

    lint res = 0;
    for (auto cur: node) {
        if (!union_root(cur.A, cur.B)) continue;
        res += cur.C;
    }
    cout << res;
    return 0;
}
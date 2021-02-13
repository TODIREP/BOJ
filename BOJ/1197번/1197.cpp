#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long lint;
struct link {
    int A, B, C;
    bool operator<(const link &a) const { return C < a.C; }
};
vector<link> node;
vector<lint> root;
int find_root(int n) { return (root[n] < 0 ? n : (root[n] = find_root(root[n])));}
int res = 0;

void union_root(int a, int b, int c) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) return;
    if (root[a] >= root[b]) root[b] = a;
    else root[a] = b;
    res += c;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int V, E, A, B, C;
    cin >> V >> E;
    root.assign(V + 2, -1);

    while(E--) {
        cin >> A >> B >> C;
        node.push_back({A, B, C});
    }
    sort(node.begin(), node.end());
    for (auto edge: node) union_root(edge.A, edge.B, edge.C);
    cout << res;
    return 0;
}
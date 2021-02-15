#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct link {
    int A, B;
    double C;
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
double get_distance(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

vector<link> node;
vector<pair<int, int> > pos;
int main(void) {
    double res = 0.0;
    int N, M, X, Y;
    scanf("%d%d", &N, &M);

    root.assign(N + 2, -1);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &X, &Y);
        pos.push_back({X, Y});
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            node.push_back({i, j, get_distance(pos[i], pos[j])});
        }
    }
    sort(node.begin(), node.end());

    while (M--) {
        scanf("%d%d", &X, &Y);
        if (!union_root(X - 1, Y - 1)) continue;
    }

    for (auto cur : node) {
        if (!union_root(cur.A, cur.B)) continue;
        res += cur.C;
    }

    printf("%.2lf", res);
    return 0;
}
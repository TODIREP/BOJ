#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct star {
    int A, B;
    double D;
    bool operator<(const star &a) const { return D < a.D; }
};
double distance(double ax, double ay, double bx, double by) {
    return sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
}

vector<int> root;
vector<star> node;
vector<pair<double, double> > stars;

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
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N;
    cin >> N;
    root.assign(N + 1, -1);
    double x, y, res = 0;

    for (int i = 1; i <= N; i++) {
        cin >> x >> y;
        int len = stars.size();
        for (int P = 0; P < len; P++) {
            node.push_back({P, len, distance(x, y, stars[P].first, stars[P].second)});
        }
        stars.push_back({x, y});
    }
    sort(node.begin(), node.end());
    
    for (auto nd: node) {
        if (!union_root(nd.A, nd.B)) continue;
        res += nd.D;
    }
    cout << floor(res * 100 + 0.5) / 100;
    return 0;
}
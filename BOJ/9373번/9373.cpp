#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct camera {
    int x, y, r;
};
struct node {
    int a, b;
    double dis;
    bool operator<(const node &a) const {
        return dis < a.dis;
    }
};
vector<int> root;
int find_root(int a) {
    if (root[a] < 0) return a;
    return root[a] = find_root(root[a]);
}
bool union_root(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) return false;
    root[b] = a;
    return true;
}
double get_distance(const pair<int, int> &a, const pair<int, int> &b) {
    return sqrt(pow((long long) (a.first - b.first), 2) + pow((long long) (a.second - b.second), 2));
}
int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int w, n;
        scanf("%d%d", &w, &n);
        vector<camera> cam(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &cam[i].x, &cam[i].y, &cam[i].r);
        }
        vector<node> link;
        link.push_back({0, n + 1, (double) w});
        root.assign(n + 2, -1);

        for (int i = 0; i < n; i++) {
            if (cam[i].x - cam[i].r <= 0) union_root(0, i + 1);
            else link.push_back({0, i + 1, (double) (cam[i].x - cam[i].r)});
            if (cam[i].x + cam[i].r >= w) union_root(i + 1, n + 1);
            else link.push_back({i + 1, n + 1, (double) (w - cam[i].x - cam[i].r)});

            for (int j = i + 1; j < n; j++) {
                double dis = get_distance({cam[i].x, cam[i].y}, {cam[j].x, cam[j].y});
                if (dis <= (cam[i].r + cam[j].r)) {
                    link.push_back({i + 1, j + 1, 0.0});
                } else {
                    dis -= (double) (cam[i].r + cam[j].r);
                    if (dis <= w) link.push_back(node{i + 1, j + 1, dis});
                }
            }
        }
        double result = 0.0;
        sort(link.begin(), link.end());
        int l_size = link.size();
        for (int i = 0; i < l_size; i++) {
            if (union_root(link[i].a, link[i].b)) {
                if (find_root(0) == find_root(n + 1)) {
                    result = link[i].dis;
                    break;
                }
            }
        }
        if (result == 0.0) printf("0\n");
        else {
            printf("%.10lf\n", result / 2.0);
        }
    }
    return 0;
}
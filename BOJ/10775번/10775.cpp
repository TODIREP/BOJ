#include <iostream>
#include <vector>
using namespace std;

vector<int> root;
int find_root(int n) {
    if (root[n] == n) return n;
    return root[n] = find_root(root[n]);
}
void union_root(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    root[a] = b;
}

int main(void) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int G, P;
    cin >> G >> P;
    root.resize(G + 1);
    for (int i = 1; i <= G; i++) root[i] = i;

    int answer = 0, node;
    for (int i = 0; i < P; i++) {
        cin >> node;
        int port = find_root(node);
        if (port == 0) break;
        union_root(port, port - 1);
        answer++;
    }
    cout << answer;
    return 0;
}
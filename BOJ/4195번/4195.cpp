#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> root;
int find_root(int n) {return ((root[n] < 0) ? n : (root[n] = find_root(root[n])));}
int union_root(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) return root[a] * -1;
    root[a] += root[b];
    root[b] = a;
    return root[a] * -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T, F;
    string A, B;
    cin >> T;

    while (T--) {
        cin >> F;
        root.assign(F * 2 + 2, -1);
        unordered_map<string, int> mp;

        int current = 0;
        while (F--) {
            cin >> A >> B;
            int a_idx, b_idx;
            if (mp.count(A) == 0) mp.insert({A, ++current});
            a_idx = mp.at(A);
            if (mp.count(B) == 0) mp.insert({B, ++current});
            b_idx = mp.at(B);
            cout << union_root(a_idx, b_idx) << "\n";
        }
    }
    return 0;
}
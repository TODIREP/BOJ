#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> num;
int search(int N) {
    if (num[N] <= N) return num[N];
    int start = (int) sqrt(N);
    for (int index = start; start >= 0; index--) {
        num[N] = min(num[N], search(N - index * index) + 1);
        if (index < sqrt(N - index * index)) return num[N];
    }
    return num[N];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    num.assign(100001, 100001);
    num[0] = 0; num[1] = 1;
    cin >> N;
    cout << search(N);
    return 0;
}
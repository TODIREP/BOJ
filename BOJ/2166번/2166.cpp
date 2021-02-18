#include <iostream>
#include <vector>
using namespace std;
#define lint long long

lint CCW(pair<int, int> c, pair<lint, lint> a, pair<lint, lint> b) {
    return (c.first * a.second + a.first * b.second + b.first * c.second)
        - (c.second * a.first + a.second * b.first + b.second * c.first);
}
int main(void) {
    lint N;
    cin >> N;
    vector<pair<lint, lint> > point(N);
    for (lint i = 0; i < N; i++) cin >> point[i].first >> point[i].second;

    lint res = 0, center = 0, left = 1;
    for (lint right = 2; right < N; right++) {
        res += CCW(point[center], point[left], point[right]);
        left = right;
    }
    if (res < 0) res *= -1;
    cout << res / 2 << (res % 2 == 1 ? ".5" : ".0");
    return 0;
}
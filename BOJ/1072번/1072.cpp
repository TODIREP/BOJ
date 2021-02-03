#include <iostream>
#include <cmath>
using namespace std;
#define lint long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main(void) {
    fastio;
    lint X, Y, Z, ans;
    cin >> X >> Y;
    Z = floor(Y * 100 / X);
    lint left = 0, right = X;

    while (right - left > 3) {
        lint mid = (left + right) / 2;
        lint next = floor((Y + mid) * 100 / (X + mid));
        if (next > Z) right = mid;
        else left = mid;
    }

    for (lint check = right; check >= left; check--) {
        lint next = floor((Y + check) * 100 / (X + check));
        if (next > Z) right = check;
    }

    lint check = floor((Y + right) * 100 / (X + right));
    if (check == Z) cout << "-1";
    else cout << right;
    return 0;
}
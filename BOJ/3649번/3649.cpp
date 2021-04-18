#include <iostream>
#include <algorithm>
using namespace std;

int parts[1000001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    while (cin >> x) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> parts[i];
        sort(parts, parts + n);

        x *= 10000000;
        bool found = false;
        int left = 0, right = n - 1;

        while (left < right) {
            if (parts[left] + parts[right] == x) {
                found = true;
                break;
            }
            if (parts[left] + parts[right] < x) left++;
            else right--;
        }
        if (found) cout << "yes " << parts[left] << ' ' << parts[right] << '\n';
        else cout << "danger\n";
    }
    return 0;
}
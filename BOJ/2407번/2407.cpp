#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string comb[102][102];
string comb_plus(string a, string b) {
    if (b.size() > a.size()) return comb_plus(b, a);
    int cache = 0;
    int ax = a.size() - 1, bx;
    string result;

    for (bx = b.size() - 1; bx >= 0; bx--) {
        int temp = (b[bx] - '0') + (a[ax] - '0') + cache;
        cache = temp / 10;
        temp %= 10;
        result.push_back(temp + '0');
        ax--;
    }
    while (cache != 0 || ax != -1) {
        if (ax == -1) {
            result.push_back(cache + '0');
            break;
        } else {
            int temp = (a[ax] - '0') + cache;
            cache = temp / 10;
            temp %= 10;
            result.push_back(temp + '0');
            ax--;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(void) {
    int N, M;
    cin >> N >> M;
    if (M > N - M) M = N - M;

    for (int x = 1; x <= N; x++) {
        for (int y = 0; y <= M; y++) {
            if (y == 0 || x == y) comb[x][y] = "1";
            comb[x + 1][y] = comb_plus(comb[x + 1][y], comb[x][y]);
            comb[x + 1][y + 1] = comb_plus(comb[x + 1][y + 1], comb[x][y]);
        }
    }
    cout << comb[N][M];
    return 0;
}
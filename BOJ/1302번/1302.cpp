#include <iostream>
#include <string>
#include <map>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main(void) {
    fastio;
    int N, res = 0;
    string book, best_book;
    map<string, int> mp;
    cin >> N;

    for (int index = 0; index < N; index++) {
        cin >> book;
        if (mp[book] > 0) mp[book]++;
        else mp[book] = 1;

        if (res < mp[book]) {
            res = mp[book];
            best_book = book;
        } else if (res == mp[book]) {
            if (book.compare(best_book) < 0) {
                best_book = book;
            }
        }
    }

    cout << best_book;
    return 0;
}
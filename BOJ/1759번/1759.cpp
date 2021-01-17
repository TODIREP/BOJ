#include <iostream>
using namespace std;

char moem[5] = {'a', 'e', 'i', 'o', 'u'};
char pass[16], word[16], input[27];
int L, C, count = 0;

void search(int start, int n) {
    if (n == L) {
        int temp = 0;
        for (int x = 0; x < 5; x++) if (input[moem[x] - 'a'] == 2) temp++;
        if (temp < 1 || (n - temp) < 2) return;
        for (int x = 0; x < L; x++) cout << (char) pass[x];
        cout << "\n";
        return;
    }
    for (int x = start; x < C; x++) {
        if (input[word[x]] != 1) continue;
        input[word[x]]++;
        pass[n] = word[x] + 'a';
        search(x + 1, n + 1);
        input[word[x]]--;
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    char c;
    cin >> L >> C;
    for (int index = 0; index < C; index++) {
        cin >> c;
        input[c - 'a']++;
    }
    for (int index = 0; index < 27; index++) if (input[index]) word[count++] = index;
    search(0, 0);
    return 0;
}
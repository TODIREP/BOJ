#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, input;
    stack<pair<int, int>> data;
    cin >> N;

    for (int index = 1; index <= N; index++) {
        cin >> input;
        while (!data.empty()) {
            if (data.top().first <= input) data.pop();
            else break;
        }
        if (data.empty()) cout << "0 ";
        else cout << data.top().second << " ";
        data.push({input, index});
    }
    return 0;
}
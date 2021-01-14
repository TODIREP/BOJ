#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;
vector<int> number;
int N, M, item = 0;

void result(int cur) {
    for (int index = cur; index < N; index++) {
        item++;
        number.push_back(num[index]);

        if (item == M) {
            for (auto data: number) cout << data << " ";
            cout << "\n";
        } else result(index);

        item--;
        number.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;

    num.resize(N);

    for (int index = 0; index < N; index++) {
        cin >> num[index];
    }
    sort(num.begin(), num.end());
    result(0);
    return 0;
}
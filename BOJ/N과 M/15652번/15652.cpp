#include <iostream>
#include <vector>
using namespace std;

vector<int> num;
int N, M, count = 0;

void result(int cur) {
    if (count == M) return;
    for (int index = cur; index < N; index++) {
        count++;
        num.push_back(index + 1);

        if (count == M) {
            for (int index2 = 0; index2 < count; index2++) {
                cout << num[index2] << " ";
            }
            cout << "\n";
        }
        result(index);
        
        count--;
        num.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    result(0);
    return 0;
}
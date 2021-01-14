#include <iostream>
#include <vector>
using namespace std;

vector<bool> visit;
vector<int> num;
int N, M, count = 0;

void print() {
    for (int index = 1; index <= N; index++) {
        if (visit[index]) continue;
        visit[index] = true;
        num.push_back(index);
        count++;
        if (count == M) {
            for (int index2 = 0; index2 < count; index2++) {
                cout << num[index2] << " ";
            }
            cout << "\n";
        }
        print();
        visit[index] = false;
        num.pop_back();
        count--;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    visit.assign(N + 1, false);
    print();
    return 0;
}
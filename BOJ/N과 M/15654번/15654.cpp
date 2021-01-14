#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;
vector<int> number;
vector<bool> visit;
int N, M, item = 0;

void result() {
    for (int index = 0; index < N; index++) {
        if (!visit[index]) {
            visit[index] = true;
            item++;
            number.push_back(num[index]);

            if (item == M) {
                for (auto data: number) cout << data << " ";
                cout << "\n";
            } else result();

            visit[index] = false;
            item--;
            number.pop_back();
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;

    visit.assign(N, false);
    num.resize(N);

    for (int index = 0; index < N; index++) {
        cin >> num[index];
    }
    sort(num.begin(), num.end());
    result();
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector<int> opers;
int num[13], oper[4];
int N, res_max = -1000000000, res_min = 1000000000;

void search(int count) {
    if (count == N - 1) {
        int sum = num[0];
        for (int index = 0; index < count; index++) {
            int op = opers[index];
            if (op == 0) sum += num[index + 1];
            else if (op == 1) sum -= num[index + 1];
            else if (op == 2) sum *= num[index + 1];
            else sum /= num[index + 1];
        }
        res_max = max(res_max, sum);
        res_min = min(res_min, sum);
        return;
    }

    for (int index = 0; index < 4; index++) {
        if (oper[index] == 0) continue;
        oper[index]--;
        opers.push_back(index);
        search(count + 1);
        oper[index]++;
        opers.pop_back();
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int input;
    cin >> N;
    for (int index = 0; index < N; index++) {
        cin >> input;
        num[index] = input;
    }
    for (int index = 0; index < 4; index++) {
        cin >> input;
        oper[index] = input;
    }
    search(0);
    cout << res_max << "\n" << res_min;
    return 0;
}
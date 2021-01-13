#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int N;
long long res_min = 10000000000, res_max = 0;
vector<bool> arr;
vector<int> target;
vector<char> oper;

long long max(long long a, long long b) {
    return a > b ? a : b;
}

long long min(long long a, long long b) {
    return a > b ? b : a;
}

long long vtoi(vector<int> array) {
    long long level = 1, sum = 0;
    for (int index = N; index >= 0; index--) {
        sum += (array[index] - 1) * level;
        level *= 10;
    }
    return sum;
}

bool valid() {
    for (int index = 0; index < N; index++) {
        int a = target[index];
        int b = target[index + 1];
        if (oper[index] == '<') {
            if (a > b) return false;
        } else {
            if (a < b) return false;
        }
    }
    return true;
}

void search() {
    for (int index = 0; index <= 9; index++) {
        if (arr[index]) continue;
        arr[index] = true;
        target.push_back(index + 1);
        if (target.size() == N + 1) {
            if (valid()) {
                long long number = vtoi(target);
                res_max = max(number, res_max);
                res_min = min(number, res_min);
            }
        }
        search();
        arr[index] = false;
        target.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char input;
    arr.assign(11, false);
    cin >> N;
    for (int index = 0; index < N; index++) {
        cin >> input;
        oper.push_back(input);
    }
    search();
    if (res_max < pow(10, N)) cout << "0";
    cout << res_max << "\n";
    if (res_min < pow(10, N)) cout << "0";
    cout << res_min;
    return 0;
}
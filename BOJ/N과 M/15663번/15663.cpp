#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define num first
#define count second

vector<int> number, temp;
vector<pair<int, int>> arr;
int N, M, cases = 0;

void search(int counter) {
    if (counter == M) {
        for (auto nums : number) {
            cout << nums << " ";
        }
        cout << "\n";
        return;
    }
    for (int index = 0; index < cases; index++) {
        if (arr[index].count == 0) continue;
        arr[index].count--;
        number.push_back(arr[index].num);
        search(counter + 1);
        arr[index].count++;
        number.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int input;
    temp.assign(10002, 0);
    cin >> N >> M;
    for (int index = 0; index < N; index++) {
        cin >> input;
        temp[input]++;
    }
    for (int index = 0; index < 10002; index++) {
        if (temp[index] > 0) {
            cases++;
            arr.push_back({index, temp[index]});
        }
    }
    search(0);
    return 0;
}
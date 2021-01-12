#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
vector<bool> visit;
int N, count = 0, result = 1000000000;

void search() {
    vector<int> start, link;
    int start_sum = 0, link_sum = 0;

    for (int index = 0; index < N; index++) {
        if (visit[index]) start.push_back(index);
        else link.push_back(index);
    }
    
    for (int index = 0; index < count; index++) {
        for (int index2 = 0; index2 < count; index2++) {
            if (index == index2) continue;
            start_sum += arr[start[index]][start[index2]];
            link_sum += arr[link[index]][link[index2]];
        }
    }
    int temp = start_sum - link_sum;
    temp = temp > 0 ? temp : (-1) * temp;
    result = min(result, temp);
}

void res(int x) {
    for (int index = x; index < N; index++) {
        if (visit[index]) continue;
        visit[index] = true;
        count++;
        if (count == N / 2) search();
        res(index + 1);
        visit[index] = false;
        count--;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    visit.assign(N, false);
    arr.resize(N);
    for (int x = 0; x < N; x++) {
        arr[x].resize(N);
        for (int y = 0; y < N; y++) {
            cin >> arr[x][y];
        }
    }
    res(0);
    cout << result;
    return 0;
}
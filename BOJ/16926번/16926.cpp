#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, R;
    cin >> N >> M >> R;
    vector<vector<int>> arr(N, vector<int>(M));
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            cin >> arr[x][y];
        }
    }

    int layer = min(N, M) / 2;
    vector<vector<int>> groups;
    
    for (int level = 0; level < layer; level++) {
        vector<int> group;
        for (int x = level; x < M - level - 1; x++) {
            group.push_back(arr[level][x]);
        }
        for (int x = level; x < N - level - 1; x++) {
            group.push_back(arr[x][M - level - 1]);
        }
        for (int x = M - level - 1; x >= level + 1; x--) {
            group.push_back(arr[N - level - 1][x]);
        }
        for (int x = N - level - 1; x >= level + 1; x--) {
            group.push_back(arr[x][level]);
        }
        groups.push_back(group);
    }

    for (int level = 0; level < layer; level++) {
        vector<int> &group = groups[level];
        int len = group.size();
        int index = R % len;

        for (int x = level; x < M - level - 1; x++, index = (index + 1) % len) {
            arr[level][x] = group[index];
        }
        for (int x = level; x < N - level - 1; x++, index = (index + 1) % len) {
            arr[x][M - level - 1] = group[index];
        }
        for (int x = M - level - 1; x >= level + 1; x--, index = (index + 1) % len) {
            arr[N - level - 1][x] = group[index];
        }
        for (int x = N - level - 1; x >= level + 1; x--, index = (index + 1) % len) {
            arr[x][level] = group[index];
        }
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            cout << arr[x][y] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
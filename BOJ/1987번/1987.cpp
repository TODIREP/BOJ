#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M, count = 1, result = 1;
vector<vector<char>> target;
vector<vector<bool>> visit;
vector<bool> str;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void circuit(int X, int Y) {
    for (int index = 0; index < 4; index++) {
        int nx = X + dx[index];
        int ny = Y + dy[index];
        
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (str[target[nx][ny] - 'A']) continue;
        if (visit[nx][ny]) continue;

        str[target[nx][ny] - 'A'] = true;
        visit[nx][ny] = true;
        count++;
        if (count >= result) result = count;

        circuit(nx, ny);
        str[target[nx][ny] - 'A'] = false;
        visit[nx][ny] = false;
        count--;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input;
    cin >> N >> M;

    target.resize(N);
    visit.resize(N);
    str.assign(26, 0);
    for (int index = 0; index < N; index++) {
        cin >> input;
        visit[index].assign(M, false);
        for (int index2 = 0; index2 < M; index2++) {
            target[index].push_back(input[index2]);
        }
    }
    str[target[0][0] - 'A'] = true;
    circuit(0, 0);
    cout << result;
    return 0;
}
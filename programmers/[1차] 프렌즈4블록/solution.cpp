#include <string>
#include <vector>
using namespace std;

int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};
pair<bool, int> valid(vector<string> &board) {
    int height = board.size();
    int width = board[0].size();
    bool able = false;
    vector<pair<int, int>> target;
    for (int x = 0; x < height - 1; x++) {
        for (int y = 0; y < width - 1; y++) {
            if (board[x][y] == '0') continue;
            int cnt = 0;
            for (int dir = 0; dir < 3; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (board[nx][ny] == board[x][y]) cnt++;
            }
            if (cnt == 3) {
                able = true;
                target.push_back({x, y});
                for (int dir = 0; dir < 3; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    target.push_back({nx, ny});
                }
            }
        }
    }
    int cnt = 0;
    for (pair<int, int>& item: target) {
        if (board[item.first][item.second] != '0') cnt++;
        board[item.first][item.second] = '0';
    }
    return {able, cnt};
}
void poll(vector<string> &board) {
    int height = board.size();
    int width = board[0].size();
    for (int x = height - 1; x >= 0; x--) {
        for (int y = 0; y < width; y++) {
            if (board[x][y] == '0') {
                int start = x;
                for (int p = start; p >= 0; p--) {
                    if (board[p][y] != '0') {
                        board[start][y] = board[p][y];
                        start--;
                        board[p][y] = '0';
                    }
                }
            }
        }
    }
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (true) {
        pair<bool, int> r = valid(board);
        if (!r.first) break;
        answer += r.second;
        poll(board);
    }
    return answer;
}
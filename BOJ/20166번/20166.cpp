#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

char arr[11][11];
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

struct items {
    int X;
    int Y;
    string text;
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    string input;

    cin >> N >> M >> K;
    for (int x = 0; x < N; x++) {
        cin >> input;
        for (int y = 0; y < M; y++) {
            arr[x][y] = input[y];
        }
    }

    stack<items> stk;
    map<string, int> res;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            string start_text = "";
            start_text.push_back(arr[x][y]);
            stk.push({x, y, start_text});

            while (!stk.empty()) {
                auto cur = stk.top();
                stk.pop();
                res[cur.text] += 1;

                for (int dir = 0; dir < 8; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0) nx = N - 1;
                    else if (nx >= N) nx = 0;
                    if (ny < 0) ny = M - 1;
                    else if (ny >= M) ny = 0;

                    string next_text = cur.text;
                    if (next_text.size() == 5) continue;

                    next_text.push_back(arr[nx][ny]);
                    stk.push({nx, ny, next_text});
                }
            }
        }
    }

    for (int index = 0; index < K; index++) {
        cin >> input;
        cout << res[input] << "\n";
    }
    
    return 0;
}
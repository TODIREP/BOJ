#include <iostream>
#include <vector>
using namespace std;

void copy_arr(vector<vector<int>> &from, vector<vector<int>> &to, int size) {
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            to[x][y] = from[x][y];
        }
    }
}
void reverse_vertical(vector<vector<int>> &target, int &a, int &b) {
    int size = max(a, b);
    vector<vector<int>> res(size, vector<int>(size, 0));

    for (int x = 0; x < a; x++) {
        for (int y = 0; y < b; y++) {
            res[x][y] = target[a - x - 1][y];
        }
    }
    copy_arr(res, target, size);
}
void reverse_horizontal(vector<vector<int>> &target, int &a, int &b) {
    int size = max(a, b);
    vector<vector<int>> res(size, vector<int>(size, 0));

    for (int x = 0; x < a; x++) {
        for (int y = 0; y < b; y++) {
            res[x][y] = target[x][b - y - 1];
        }
    }
    copy_arr(res, target, size);
}
void rotate_right(vector<vector<int>> &target, int &a, int &b) {
    int size = max(a, b);
    vector<vector<int>> res(size, vector<int>(size, 0));

    for (int x = 0; x < a; x++) {
        for (int y = 0; y < b; y++) {
            res[y][a - x - 1] = target[x][y];
        }
    }
    int temp = a;
    a = b;
    b = temp;
    copy_arr(res, target, size);
}
void rotate_left(vector<vector<int>> &target, int &a, int &b) {
    int size = max(a, b);
    vector<vector<int>> res(size, vector<int>(size, 0));

    for (int x = 0; x < a; x++) {
        for (int y = 0; y < b; y++) {
            res[b - y - 1][x] = target[x][y];
        }
    }
    int temp = a;
    a = b;
    b = temp;
    copy_arr(res, target, size);
}
void switch_right(vector<vector<int>> &target, int &a, int &b) {
    int size = max(a, b);
    vector<vector<int>> res(size, vector<int>(size, 0));

    for (int x = 0; x < a / 2; x++) {
        for (int y = 0; y < b / 2; y++) {
            res[x][y + b / 2] = target[x][y];
            res[x + a / 2][y + b / 2] = target[x][y + b / 2];
            res[x + a / 2][y] = target[x + a / 2][y + b / 2];
            res[x][y] = target[x + a / 2][y];
        }
    }
    copy_arr(res, target, size);
}
void switch_left(vector<vector<int>> &target, int &a, int &b) {
    int size = max(a, b);
    vector<vector<int>> res(size, vector<int>(size, 0));

    for (int x = 0; x < a / 2; x++) {
        for (int y = 0; y < b / 2; y++) {
            res[x + a / 2][y] = target[x][y];
            res[x + a / 2][y + b / 2] = target[x + a / 2][y];
            res[x][y + b / 2] = target[x + a / 2][y + b / 2];
            res[x][y] = target[x][y + b / 2];
        }
    }
    copy_arr(res, target, size);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, R, A;
    cin >> N >> M >> R;
    int size = max(N, M);
    vector<vector<int>> arr(size, vector<int>(size, 0));

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            cin >> arr[x][y];
        }
    }
    while (R--) {
        cin >> A;
        switch (A) {
        case 1:
            reverse_vertical(arr, N, M);
            break;
        case 2:
            reverse_horizontal(arr, N, M);
            break;
        case 3:
            rotate_right(arr, N, M);
            break;
        case 4:
            rotate_left(arr, N, M);
            break;
        case 5:
            switch_right(arr, N, M);
            break;
        default:
            switch_left(arr, N, M);
            break;
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
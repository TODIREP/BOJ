#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int N;
char arr[2200][2200];
void fill(int x, int y, int size) {
    int next_size = size / 3;
    for (int nx = 0; nx < next_size; nx++) {
        for (int ny = 0; ny < next_size; ny++) {
            arr[x + next_size + nx][y + next_size + ny] = ' ';
        }
    }
    if (next_size == 1) return;
    fill(x, y, next_size);
    
    for (int nx = x; nx < x + size; nx += next_size) {
        for (int ny = y; ny < y + size; ny += next_size) {
            if (nx == x && ny == y) continue;
            if (nx == x + next_size && nx == ny) continue;

            for (int rx = 0; rx < next_size; rx++) {
                for (int ry = 0; ry < next_size; ry++) {
                    arr[nx + rx][ny + ry] = arr[x + rx][y + ry];
                }
            }
        }
    }
}

int main(void) {
    fastio;
    cin >> N;
    for (int x = 1; x <= N; x++) for (int y = 1; y <= N; y++) arr[x][y] = '*';
    fill(1, 1, N);
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) cout << arr[x][y];
        cout << "\n";
    }
    return 0;
}
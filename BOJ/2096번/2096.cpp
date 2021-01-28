#include <iostream>
using namespace std;
#define MIN_NUM 10000000
#define MAX_NUM -1
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int N, number[3], res[3][2], temp[3][2];
int main(void) {
    fastio;
    cin >> N;
    for (int index = 0; index < N; index++) {
        for (int num = 0; num < 3; num++) cin >> number[num];

        for (int num = 0; num < 3; num++) {
            temp[num][0] = MIN_NUM;
            temp[num][1] = MAX_NUM;
        }

        if (index == 0) {
            for (int num = 0; num < 3; num++) {
                temp[num][0] = temp[num][1] = number[num];
            }

        } else {
            for (int num = 0; num < 3; num++) {
                for (int mov = -1; mov <= 1; mov++) {
                    int next = num + mov;
                    if (next < 0 || next > 2) continue;
                    temp[num][0] = min(temp[num][0], res[next][0] + number[num]);
                    temp[num][1] = max(temp[num][1], res[next][1] + number[num]);
                }
            }
        }

        for (int num = 0; num < 3; num++) {
            res[num][0] = temp[num][0];
            res[num][1] = temp[num][1];
        }
    }

    int min_res = MIN_NUM, max_res = MAX_NUM;
    for (int num = 0; num < 3; num++) {
        min_res = min(min_res, res[num][0]);
        max_res = max(max_res, res[num][1]);
    }
    cout << max_res << " " << min_res;
    return 0;
}
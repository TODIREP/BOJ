#include <iostream>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int N, M, printer[101], timer[101];
int getmax() {
    int num = -1;
    for (int index = 0; index < N; index++) {
        if (timer[index] == 0 && printer[index] > num) num = printer[index];
    }
    return num;
}
int main(void) {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        int rate = 1;
        cin >> N >> M;
        for (int index = 0; index < N; index++) cin >> printer[index];
        while (rate <= N) {
            for (int index = 0; index < N; index++) {
                int target = getmax();
                if (printer[index] == target) {
                    timer[index] = rate++;
                }
            }
        }
        cout << timer[M] << "\n";
        for (int index = 0; index < N; index++) timer[index] = 0;
    }
    return 0;
}
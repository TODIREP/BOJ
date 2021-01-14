#include <iostream>
using namespace std;

int arr[1001];
int bitonic[1001][2];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, result = 0;
    cin >> N;
    for (int index = 0; index < N; index++) {
        cin >> arr[index];
    }

    for (int index = 1; index < N; index++) {
        int inc_max = -1, dec_max = -1;
        for (int index2 = index - 1; index2 >= 0; index2--) {
            if (arr[index2] > arr[index]) dec_max = max(dec_max, max(bitonic[index2][0], bitonic[index2][1]));
            if (arr[index] > arr[index2]) inc_max = max(inc_max, bitonic[index2][0]);
        }
        bitonic[index][0] = inc_max + 1;
        bitonic[index][1] = dec_max + 1;
        result = max(result, max(bitonic[index][0], bitonic[index][1]));
    }
    cout << result + 1;
    return 0;
}
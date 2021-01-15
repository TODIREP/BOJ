#include <iostream>
using namespace std;

int arr[100001], sum[100001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, I, J;
    cin >> N >> M;
    for (int index = 1; index <= N; index++) {
        cin >> arr[index];
        if (index == 1) sum[index] = arr[index];
        else sum[index] = sum[index - 1] + arr[index];
    }
    for (int index = 0; index < M; index++) {
        cin >> I >> J;
        cout << sum[J] - sum[I - 1] << "\n";
    }
    return 0;
}
#include <iostream>
using namespace std;
#define lint long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

lint LAN[10001];
int main(void) {
    fastio;
    lint K, N, M_LAN = 0, answer = 0;
    cin >> K >> N;

    for (int index = 0; index < K; index++) {
        cin >> LAN[index];
        M_LAN = max(M_LAN, LAN[index]);
    }

    lint m_LAN = 0;
    while (m_LAN <= M_LAN) {
        lint cut_LAN = (m_LAN + M_LAN) / 2;
        if (cut_LAN == 0) cut_LAN++;

        lint res = 0;
        for (int index = 0; index < K; index++)
            res += LAN[index] / cut_LAN;

        if (res >= N) {
            answer = max(answer, cut_LAN);
            m_LAN = cut_LAN + 1;
        } else M_LAN = cut_LAN - 1;
    }
    cout << answer;
    return 0;
}
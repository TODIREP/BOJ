#include <iostream>
using namespace std;
#define endl "\n"
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int lesson[100001];
int main(void) {
    fastio;
    int N, M, start_lesson = 0, end_lesson = 0;
    cin >> N >> M;
    for (int index = 0; index < N; index++) {
        cin >> lesson[index];
        end_lesson += lesson[index];
        start_lesson = max(start_lesson, lesson[index]);
    }

    while (start_lesson <= end_lesson) {
        int check_lesson = (start_lesson + end_lesson) / 2;
        int res = 1, temp_lesson = 0;

        for (int index = 0; index < N; index++) {
            temp_lesson += lesson[index];

            if (temp_lesson > check_lesson) {
                temp_lesson = 0;
                index--;
                res++;
            }
        }

        if (res <= M) end_lesson = check_lesson - 1;
        else start_lesson = check_lesson + 1;
    }
    cout << start_lesson;
    return 0;
}
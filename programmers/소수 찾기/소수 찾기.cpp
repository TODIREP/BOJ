#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> check, visit;
string num, temp;
int answer = 0, N;

void solve() {
    for (int index = 0; index < N; index++) {
        if (visit[index] == 0) {
            visit[index] = 1;
            temp.push_back(num[index]);
            if (check[stoi(temp)] == 0 && stoi(temp) >= 2) {
                check[stoi(temp)] = 1;
                answer++;
            }
            solve();
            visit[index] = 0;
            temp.pop_back();
        }
    }
}

int solution(string numbers) {
    vector<int> number;
    N = numbers.size();
    visit.assign(N, 0);
    num = numbers;
    int target = 0, times = 1;
    for (int index = 0; index < N; index++) {
        number.push_back(numbers[index] - '0');
    }
    sort(number.begin(), number.end());
    for (int index = 0; index < N; index++) {
        target += number[index] * times;
        times *= 10;
    }
    check.assign(target + 1, 0);
    for (int index = 2; index <= target; index++) {
        for (int pos = 2; index * pos <= target; pos++) {
            if (check[index * pos] == 1) continue;
            check[index * pos] = 1;
        }
    }
    solve();
    return answer;
}
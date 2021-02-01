#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define endl "\n"
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

bool num[10];
int N, alphabet[27], number[10];
int result = 0, alpha_counter = 0;
vector<string> target(10);

void search(int count) {
    if (count == alpha_counter) {
        int sum = 0;
        for (int index = 0; index < N; index++) {
            int level = 1;
            int length = target[index].size();
            
            for (int S = length - 1; S >= 0; S--) {
                sum += number[alphabet[target[index][S] - 'A'] - 1] * level;
                level *= 10;
            }
        }
        result = max(result, sum);
        return;
    }

    for (int index = 10 - alpha_counter; index < 10; index++) {
        if (num[index]) continue;
        num[index] = true;
        number[count] = index;
        search(count + 1);
        num[index] = false;
    }
}

int main(void) {
    fastio;
    string input;
    cin >> N;
    
    for (int index = 0; index < N; index++) {
        cin >> target[index];
        int length = target[index].size();

        for (int S = 0; S < length; S++) {
            int alpha = target[index][S] - 'A';
            if (alphabet[alpha] == 0) alphabet[alpha] = ++alpha_counter;
        }
    }

    search(0);
    cout << result;
    return 0;
}
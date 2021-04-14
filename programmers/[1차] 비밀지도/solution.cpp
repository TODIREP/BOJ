#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n, string(n, ' '));
    for (int i = 0; i < n; i++) {
        int cur = arr1[i] | arr2[i];
        int pos = (1 << (n - 1));
        for (int j = 0; j < n; j++) {
            if ((cur & pos) == pos) answer[i][j] = '#';
            pos >>= 1;
        }
    }
    return answer;
}
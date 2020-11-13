#include <vector>
using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int dx[7] = {0, 0, 0, 1, 2, 2, 2};
    int dy[7] = {0, 1, 2, 1, 0, 1, 2};
    int sum, answer = -1e9;
    
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            sum = 0;
            for (int index = 0; index < 7; index++) {
                sum += arr[x + dx[index]][y + dy[index]];
            }
            if (sum > answer) answer = sum;
        }
    }
    return answer;
}
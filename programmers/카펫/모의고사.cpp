#include <string>
#include <vector>
using namespace std;

int brown_value(int x, int y) {
    return 2 * x + 2 * y + 4;
}

int yellow_value(int x, int y) {
    return x * y;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int x = 1; x <= 2000; x++) {
        for (int y = 1; y <= 2000; y++) {
            int br = brown_value(x, y);
            int ye = yellow_value(x, y);
            if (br > brown || ye > yellow) break;
            if (br == brown && ye == yellow) {
                if (y >= x) {
                    int temp = x;
                    x = y;
                    y = temp;
                }
                answer.push_back(x + 2);
                answer.push_back(y + 2);
                x = 2001;
                break;
            }
        }
    }
    return answer;
}
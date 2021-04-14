#include <string>
using namespace std;

int solution(string dartResult) {
    int num[3] = {0, };
    int number = -1;
    for (int index = 0; dartResult[index] != '\0'; index++) {
        char cur = dartResult[index];
        if (cur >= '0' and cur <= '9') {
            if (dartResult[index + 1] == '0') {
                index++;
                num[++number] = 10;
            } else {
                num[++number] = cur - '0';
            }
        } else if (cur == 'D') {
            num[number] *= num[number];
        } else if (cur == 'T') {
            num[number] *= num[number] * num[number];
        } else if (cur == '#') {
            num[number] *= -1;
        } else if (cur == '*') {
            num[number] *= 2;
            if (number > 0) {
                num[number - 1] *= 2;
            }
        }
    }
    return num[0] + num[1] + num[2];
}
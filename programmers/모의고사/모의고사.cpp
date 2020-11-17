#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    int supo1[5] = {1, 2, 3, 4, 5};
    int supo2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int supo3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> answer;
    vector<int> result;
    answer.assign(3, 0);
    int length = answers.size();
    for (int index = 0; index < length; index++) {
        if (supo1[index % 5] == answers[index]) answer[0]++;
        if (supo2[index % 8] == answers[index]) answer[1]++;
        if (supo3[index % 10] == answers[index]) answer[2]++;
    }
    int max = -1;
    for (int index = 0; index < 3; index++) {
        max = answer[index] > max ? answer[index] : max;
    }
    for (int index = 0; index < 3; index++) {
        if (answer[index] == max) result.push_back(index + 1);
    }
    return result;
}
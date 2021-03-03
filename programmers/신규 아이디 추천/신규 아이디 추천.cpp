#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1단계
    string target = new_id;
    for (int i = 0; target[i] != '\0'; i++) {
        if (target[i] >= 'A' && target[i] <= 'Z') {
            target[i] += ('a' - 'A');
        }
    }
    
    // 2단계
    for (int i = 0; target[i] != '\0'; i++) {
        if ((target[i] >= 'a' && target[i] <= 'z') || (target[i] >= '0' && target[i] <= '9')
            || target[i] == '-' || target[i] == '_' || target[i] == '.') {
            answer.push_back(target[i]);
        }
    }
    target = answer;
    answer = "";
    
    // 3단계
    for (int i = 0; target[i] != '\0'; i++) {
        if (i > 0 && target[i] == '.' && answer.back() == '.') continue;
        answer.push_back(target[i]);
    }
    target = answer;
    answer = "";
    
    // 4단계
    for (int i = 0; target[i] != '\0'; i++) {
        if ((i == 0 || target[i + 1] == '\0') && target[i] == '.') continue;
        answer.push_back(target[i]);
    }
    target = answer;
    answer = "";
    
    // 5단계
    if (target.size() == 0) {
        answer.push_back('a');
    } else {
        answer = target;
    }
    target = answer;
    answer = "";
    
    // 6단계
    if (target.size() >= 16) {
        for (int i = 0; i < 15; i++) {
            answer.push_back(target[i]);
        }
        while (answer.back() == '.') {
            answer.pop_back();
        }
    } else {
        answer = target;
    }
    target = answer;
    answer = "";
    
    // 7단계
    answer = target;
    while (answer.size() <= 2) {
        answer.push_back(target.back());
    }
    
    return answer;
}
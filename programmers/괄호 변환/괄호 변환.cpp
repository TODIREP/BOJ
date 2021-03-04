#include <string>
#include <vector>
using namespace std;

bool valid(string target) {
    int cnt = 0;
    for (int i = 0; i < target.size(); i++) {
        if (target[i] == ')') cnt--;
        else cnt++;
        if (cnt < 0) return false;
    }
    return cnt == 0;
}

string solution(string p) {
    if (p.size() == 0) return p;
    string answer = "";
    
    int A = 0, B = 0, divide = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') A++;
        else B++;
        if (A == B) {
            divide = i;
            break;
        }
    }
    
    string left = p.substr(0, divide + 1);
    string right = p.substr(divide + 1, p.size() - divide - 1);
    
    if (valid(left)) {
        answer += left + solution(right);
    } else {
        answer += "(" + solution(right) + ")";
        for (int i = 1; i < left.size() - 1; i++) {
            if (left[i] == ')') answer += "(";
            else answer += ")";
        }
    }
    return answer;
}
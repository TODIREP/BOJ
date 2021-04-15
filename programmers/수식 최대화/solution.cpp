#include <string>
#include <vector>
using namespace std;
using lint = long long;
char inst[3] = {'*', '-', '+'}, priority[3];
bool used[3];
vector<lint> number;
vector<char> opers;
lint answer = 0;

lint calcul(lint a, lint b, char oper) {
    if (oper == '*') return a * b;
    if (oper == '+') return a + b;
    return a - b;
}
void cal(vector<lint> &num, vector<char> &insts, int cur) {
    if (cur == 3) {
        answer = max(answer, abs(num[0]));
        return;
    }
    vector<lint> cur_num;
    vector<char> cur_inst;
    cur_num.push_back(num[0]);
    
    for (int index = 0; index < insts.size(); index++) {
        if (insts[index] != priority[cur]) {
            cur_num.push_back(num[index + 1]);
            cur_inst.push_back(insts[index]);
        } else {
            cur_num[cur_num.size() - 1] = calcul(cur_num[cur_num.size() - 1], num[index + 1], priority[cur]);
        }
    }
    cal(cur_num, cur_inst, cur + 1);
}
void search(int cnt) {
    if (cnt == 3) {
        cal(number, opers, 0);
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (used[i]) continue;
        used[i] = true;
        priority[cnt] = inst[i];
        search(cnt + 1);
        used[i] = false;
    }
}
lint solution(string expression) {
    int front = 0;
    for (int index = 0; expression[index] != '\0'; index++) {
        char current = expression[index];
        if (current == '*' or current == '+' or current == '-') {
            number.push_back(stoll(expression.substr(front, index - front)));
            opers.push_back(current);
            front = index + 1;
        } else if (expression[index + 1] == '\0') {
            number.push_back(stoll(expression.substr(front, index)));
        }
    }
    search(0);
    return answer;
}
#include <cstdio>
#include <stack>
using namespace std;

int num[27];
bool isOper(char t) { return t == '+' || t == '*' || t == '-' || t == '/';}
double Operation(double a, double b, char oper) {
    if (oper == '+') return a + b;
    if (oper == '-') return a - b;
    if (oper == '*') return a * b;
    return a / b;
}

int main(void) {
    int N;
    char expression[102];
    stack<double> stk;
    scanf("%d %s", &N, expression);
    for (int index = 0; index < N; index++) scanf("%d", &num[index]);
    
    for (int index = 0; expression[index] != '\0'; index++) {
        if (isOper(expression[index])) {
            double A = stk.top();stk.pop();
            double B = stk.top();stk.pop();
            double res = Operation(B, A, expression[index]);
            stk.push(res);
        } else stk.push(num[expression[index] - 'A']);
    }
    printf("%.2lf", stk.top());
    return 0;
}
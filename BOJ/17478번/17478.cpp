#include <iostream>
#include <string>
using namespace std;

string wlfans = "\"재귀함수가 뭔가요?\"\n";
string listen1 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
string listen2 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
string listen3 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
string answer = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
string last = "라고 답변하였지.\n";
int N;

void print_content(int a, string contents) {
    for (int index = 0; index < N - a; index++) {
        cout << "____";
    }
    cout << contents;
}

void ask(int a) {
    print_content(a, wlfans);
    if (a == 0) {
        print_content(a, answer);
    }
    else {
        print_content(a, listen1);
        print_content(a, listen2);
        print_content(a, listen3);
        ask(a - 1);
    }
    print_content(a, last);
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    ask(N);
    return 0;
}
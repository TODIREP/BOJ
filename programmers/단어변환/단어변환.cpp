#include <string>
#include <vector>
using namespace std;

vector<int> visit;
vector<string> word;
string tar;
int times;
int answer = 0;
int counter = 0;

bool valid(string a, string b) {
    int num = 0;
    int len = a.length();
    for (int index = 0; index < len; index++) {
        if (a[index] != b[index]) num++;
    }
    return num == 1 ? true : false;
}

void compute(string cur) {
    for (int index = 0; index < times; index++) {
        if (visit[index] == 0) {
            if (valid(cur, word[index])) {
                visit[index] = 1;
                counter++;
                if (word[index] == tar) {
                    answer = answer > counter || answer == 0 ? counter : answer;
                    counter--;
                    visit[index] = 0;
                    return;
                }
                compute(word[index]);
                counter--;
                visit[index] = 0;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    word.assign(words.begin(), words.end());
    int length = words.size();
    tar = target;
    times = length;
    visit.assign(length, 0);
    compute(begin);
    return answer;
}

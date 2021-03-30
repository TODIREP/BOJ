#include <string>
#include <vector>
using namespace std;

int move_alphabet(const char& target) {
    int right = target - 'A';
    int left = 'Z' - target + 1;
    return min(left, right);
}

int direction(const int& start, const string& my, const string& target) {
    int right = -1;
    for (int index = start; target[index] != '\0'; index++) {
        if (target[index] != my[index]) {
            right = index - start;
            break;
        }
    }
    if (right == -1) return -1;
    
    int left = 1, index = start - 1;
    if (index == -1) index = target.size() - 1;
    while (my[index] == target[index]) {
        left++;
        index--;
        if (index == -1) index = target.size() - 1;
    }
    return (right <= left ? 1 : -1);
}

bool remain(const string& start, const string& target) {
    for (int index = 0; start[index] != '\0'; index++) {
        if (start[index] != target[index]) return false;
    }
    return true;
}

int solution(string name) {
    int answer = 0, len = name.size(), current = 0;
    string my_name(len, 'A');
    
    while (true) {
        if (name[current] != my_name[current]) {
            int res = move_alphabet(name[current]);
            my_name[current] = name[current];
            answer += res;
        }
        if (remain(my_name, name)) break;
        int dir = direction(current, my_name, name);
        current += direction(current, my_name, name);
        answer++;
        if (current == -1) current = len - 1;
    }
    return answer;
}
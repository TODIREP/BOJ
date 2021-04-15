#include <string>
#include <map>
using namespace std;

string get_string(string target) {
    if (target[0] >= 'A' and target[0] <= 'Z') target[0] = target[0] - 'A' + 'a';
    if (target[1] >= 'A' and target[1] <= 'Z') target[1] = target[1] - 'A' + 'a';
    return target;
}
bool valid(string target) {
    if (target[0] < 'a' or target[0] > 'z') return false;
    if (target[1] < 'a' or target[1] > 'z') return false;
    return true;
}
int solution(string str1, string str2) {
    map<string, int> a, b;
    for (int index = 0; str1[index + 1] != '\0'; index++) {
        string input = get_string(str1.substr(index, 2));
        if (valid(input)) {
            a[input]++;
        }
    }
    for (int index = 0; str2[index + 1] != '\0'; index++) {
        string input = get_string(str2.substr(index, 2));
        if (valid(input)) {
            b[input]++;
        }
    }
    int diff = 0, total = 0;
    for (auto table: a) {
        if (b[table.first] > 0) {
            diff += min(b[table.first], table.second);
            total += max(b[table.first], table.second);
        } else {
            total += table.second;
        }
    }
    for (auto table: b) {
        if (a[table.first] == 0) {
            total += table.second;
        }
    }
    return (total > 0 ? (diff * 65536 / total) : 65536);
}
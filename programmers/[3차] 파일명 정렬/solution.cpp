#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string lower(string target) {
    for (int i = 0; target[i] != '\0'; i++) {
        if (target[i] >= 'A' and target[i] <= 'Z') target[i] = target[i] - 'A' + 'a';
    }
    return target;
}
struct file {
    string head, number, tail;
    bool operator<(const file &a) const {
        if (lower(head).compare(lower(a.head)) == 0) {
            return stoi(number) < stoi(a.number);
        }
        return lower(head).compare(lower(a.head)) < 0;
    }
};
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<file> res;
    for (string &f: files) {
        int num_start = -1, num_end = -1;
        for (int i = 0; f[i] != '\0'; i++) {
            char t = f[i];
            if (t >= '0' and t <= '9' and num_start == -1) {
                num_start = i;
            }
            if (num_start != -1 and num_end == -1) {
                if (t < '0' or t > '9') {
                    num_end = i;
                }
            }
        }
        string tail = "";
        if (num_end == -1) {
            num_end = f.size();
        } else {
            tail = f.substr(num_end, f.size() - num_end);
        }
        string h = f.substr(0, num_start);
        string n = f.substr(num_start, num_end - num_start);
        res.push_back({h, n, tail});
    }
    stable_sort(res.begin(), res.end());
    for (file result: res) {
        string ans = "";
        ans += result.head;
        ans += result.number;
        ans += result.tail;
        answer.push_back(ans);
    }
    return answer;
}
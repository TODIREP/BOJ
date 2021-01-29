#include <iostream>
#include <map>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

int main(void) {
    fastio;
    int K, L;
    string number;
    map<string, int> m;
    map<int, string> res;
    cin >> K >> L;
    for (int index = 1; index <= L; index++) {
        cin >> number;
        m[number] = index;
    }
    for (auto student : m) res[student.second] = student.first;
    auto stu = res.begin();
    for (int index = 0; index < K && stu != res.end(); index++) cout << stu++->second << "\n";
    return 0;
}
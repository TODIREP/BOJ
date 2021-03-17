#include <iostream>
#include <vector>
using namespace std;
using lint = long long;
const int mod = 1e9 + 7;

vector<lint> f = {1, 1, 1, 0};
vector<lint> matrix(vector<lint> &a, vector<lint> &b)
{
    vector<lint> r = {0, 0, 0, 0};
    r[0] = (a[0] * b[0] + a[1] * b[2]) % mod;
    r[1] = (a[0] * b[1] + a[1] * b[3]) % mod;
    r[2] = (a[2] * b[0] + a[3] * b[2]) % mod;
    r[3] = (a[2] * b[1] + a[3] * b[3]) % mod;
    return r;
}
vector<lint> search(lint N)
{
    if (N == 1) return f;
    auto mid = search(N / 2);
    auto res = matrix(mid, mid);
    if (N % 2 == 0) return res;
    return matrix(res, f);
}
int main(void)
{
    lint N;
    cin >> N;
    auto res = search(N);
    cout << res[1];
    return 0;
}
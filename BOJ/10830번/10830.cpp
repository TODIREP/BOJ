#include <iostream>
#include <vector>
using namespace std;
using lint = long long;
#define MATRIX vector<vector<lint> >
lint mod = 1000;

MATRIX matrix;

MATRIX pow(MATRIX target, MATRIX level)
{
    int size = target.size();
    MATRIX res(size);
    for (int K = 0; K < size; K++)
    {
        res[K].resize(size);
        for (int x = 0; x < size; x++)
        {
            lint sum = 0;
            for (int y = 0; y < size; y++)
            {
                sum += (target[K][y] * level[y][x]) % mod;
            }
            res[K][x] = sum % mod;
        }
    }

    return res;
}

MATRIX sqr(lint N)
{
    if (N == 1) return matrix;
    MATRIX mat = sqr(N / 2);
    mat = pow(mat, mat);
    if (N % 2 == 0) return mat;
    return pow(mat, matrix);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lint A, B;
    cin >> A >> B;

    matrix.resize(A);
    for (int x = 0; x < A; x++)
    {
        matrix[x].resize(A);
        for (int y = 0; y < A; y++)
        {
            cin >> matrix[x][y];
        }
    }

    MATRIX res = sqr(B);

    for (int x = 0; x < A; x++)
    {
        for (int y = 0; y < A; y++)
        {
            cout << res[x][y] % mod << ' ';
        }
        cout << '\n';
    }
    return 0;
}
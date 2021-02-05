#include <cstdio>
#include <cmath>
using namespace std;

double min(double a, double b) { return a > b ? b : a; }
int main(void) {
    double x, y, c;
    scanf("%lf%lf%lf", &x, &y, &c);
    double left = 0, right = min(x, y), res;

    while (right - left > 0.000001) {
        double mid = (left + right) / 2.0;

        double hx = sqrt(x * x - mid * mid);
        double hy = sqrt(y * y - mid * mid);
        double hc = (hx * hy) / (hx + hy);
        
        if (hc >= c) {
            res = mid;
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%.3lf", res);
    return 0;
}
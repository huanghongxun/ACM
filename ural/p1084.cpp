#include <cstdio>
#include <cmath>
const double PI = acos(-1.0);
int main() {
    double d, r;
    scanf("%lf %lf",&d,&r);
    if (2 * r <= d) // a whole circle area.
        printf("%.3lf\n", PI * r * r);
    else if (r * r * 2 >= d * d) // the square is contained in the circle.
        printf("%.3lf\n", d * d);
    else {
        double tmp = 2 * acos(d / (2 * r));
        double area = r * r * tmp / 2 - r * r * sin(tmp) / 2;
        printf("%.3lf\n", PI * r * r - 4 * area);
    }
    return 0;
}
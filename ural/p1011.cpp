#include <cstdio>
#include <cmath>

const double eps = 1e-9;

int main() {
    double p, q;
    int ans;
    scanf("%lf%lf", &p, &q);

    for (ans = 1; ; ++ans) {
        double least = ans * p / 100.0;
        int realLeast = (int) ceil(least);
        double most = ans * q / 100.0;
        int realMost = (int) floor(most);
        if (realMost >= realLeast && most - realMost > eps && realLeast - least > eps)
            break;
    }

    printf("%d\n", ans);

    return 0;
}
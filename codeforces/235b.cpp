#include <cstdio>
int main() {
    double a, x1 = 0, ans = 0;
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &a);
        ans += (2 * x1 + 1) * a;
        x1 = (x1 + 1) * a;
    }
    printf("%.15lf\n", ans);
    return 0;
}
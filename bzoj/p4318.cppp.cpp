#include <cstdio>
int main() {
    double a, x1 = 0, x2 = 0, ans = 0;
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &a);
        ans += (3 * x2 + 3 * x1 + 1) * a;
        x2 = (x2 + 2 * x1 + 1)*a;
        x1 = (x1 + 1) * a;
    }
    printf("%.1lf\n", ans);
    return 0;
}
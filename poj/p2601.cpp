// POJ 2601, URAL 1047
#include <cstdio>
int main() {
    int n, i;
    double a, b, c, ans, sum;
    scanf("%d", &n);
    scanf("%lf%lf", &a, &b);
    sum = 0;
    for (i = 0; i < n; ++i) {
        scanf("%lf", &c);
        sum += (n - i) * c; 
    } 
    ans = (n * a + b - 2 * sum) / (n + 1);
    printf("%.2lf\n", ans);
    return 0;
}
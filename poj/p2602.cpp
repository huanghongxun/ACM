// POJ 2602, URAL 1048
#include <cstdio>
#define N 1000005
int a[N], b[N], c[N];
int main() {
    int i, n;
    scanf("%d", &n);
    for (i = n; i > 0; --i)
        scanf("%d%d", &a[i], &b[i]);

    for(i = 1; i <= n; ++i) {
        c[i] += a[i] + b[i];
        c[i + 1] = c[i] / 10;
        c[i] %= 10;
    }
    for (i = n; i > 0; --i)
        printf("%d", c[i]);
    return 0;
}
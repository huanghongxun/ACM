#include <cstdio>
#include <cstring>

int main() {
    int n, k, ans, t, i;
    char str[32];
    scanf("%d %s", &n, str);
    k = strlen(str);

    t = n / k;
    if (n % k == 0) --t;

    for (i = 0, ans = 1; i <= t; ++i) {
        ans *= n - i * k;
    }
    printf("%d\n", ans);

    return 0;
}
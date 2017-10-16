#include <cstdio>
int factor[N];
int main() {
    int n, factor, i;
    scanf("%d", &n);
    // L must be larger than 2, so factor must be larger than 3.
    if (n % 2 == 0 && n / 2 > 2)
        factor = n / 2;
    else
        factor = n;
    for (i = 2; i * i <= n; ++i) 
        if (n % i == 0) {
            factor = i;
            break;
        }
    --factor;
    printf("%d\n", factor < 2 ? 0 : factor);
    return 0;
}
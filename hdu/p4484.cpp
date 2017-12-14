// UVALive 6172, HDU 4484
#include <cstdio>

int main() {
    int p, kase, n, ma;
    scanf("%d", &p);

    while (p--) {
        scanf("%d %d", &kase, &n);

        ma = n;

        while (n != 1) {
            if (ma < n) ma = n;
            if (n % 2 == 0) while (n % 2 == 0) n /= 2;
            else n = n * 3 + 1;
        }

        printf("%d %d\n", kase, ma);
    }

    return 0;
}
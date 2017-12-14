// UVALive 6173, HDU 4485
#include <cstdio>
int main() {
    int T, kase, base, sum;
    char c;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &kase, &base);
        sum = 0;
        while ((c = getchar()) != '\n') {
            if (c == ' ' || c == '\n') continue;
            (sum = sum * base + c - '0') %= base - 1;
        }
        printf("%d %d\n", kase, sum);
    }
    return 0;
}
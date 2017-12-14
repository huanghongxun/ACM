// UVALive 6181, HDU 4492
#include <cstdio>
#include <cstring>
char str[4096];
int main() {
    int T, x, kase, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%*c", &kase);
        gets(str);
        scanf("%d", &n);
        printf("%d ", kase);
        int len = strlen(str), loc = 0;
        while (n--) {
            scanf("%d", &x);
            loc = (loc + x + len) % len;
            putchar(str[loc]);
        }
        putchar('\n');
    }

    return 0;
}
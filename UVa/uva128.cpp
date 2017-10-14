#include <cstdio>
#include <cstring>
#define rep(i,j,k) for(i=j;i<k;++i)
const int N = 1500;
char s[N];
const char digit[] = {"0123456789ABCDEF"};
const int MOD = 34943;

int main() {
    int len, i, res, sum;
    while (gets(s) && s[0] != '#') {
        len = strlen(s);
        if (len == 0) {
            puts("00 00");
            continue;
        }
        sum = 0;
        for (i = 0; i < len; i++)
            sum = (sum * 256 % MOD + s[i]) % MOD;
        res = MOD - sum * 256 % MOD * 256 % MOD;

        // Output res in hexadecimal code.
        int ans[4];
        for (i = 0; i < 4; i++) {
            ans[3 - i] = digit[res % 16];
            res /= 16;
        }
        printf("%c%c %c%c\n", ans[0], ans[1], ans[2], ans[3]);
    }
    return 0;
}
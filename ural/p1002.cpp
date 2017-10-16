#include <cstdio>
#include <cstring>
#define FOR(i,j,k) for(i=j;i<=k;++i)
#define rep(i,j,k) for(i=j;i<k;++i)
const char map[] = "22233344115566070778889990";

char s[128], word[65536][64];
int len[65536], dp[128], sel[128];

void output(int n) {
    if (n == 0) return;
    else output(n - len[sel[n]]);
    printf("%s ", word[sel[n]] + 1);
}

int main() {
    int i, j, k, n, l;
    while (scanf("%s", s + 1) != EOF && s[1] != '-') {
        scanf("%d", &n); l = strlen(s + 1);
        memset(dp, 127, sizeof dp);
        dp[0] = 0;
        FOR(i,1,n) scanf("%s", word[i] + 1), len[i] = strlen(word[i] + 1);
        FOR(j,1,l) FOR(i,1,n) if (j >= len[i]) {
            bool flag = true;
            FOR(k,1,len[i]) if (s[j - len[i] + k] != map[word[i][k] - 'a']) {
                flag = false;
                break;
            }
            if (!flag) continue;
            if (dp[j] > dp[j - len[i]] + 1) {
                dp[j] = dp[j - len[i]] + 1;
                sel[j] = i;
            }
        }
        if (dp[l] == 0x7f7f7f7f) puts("No solution.");
        else output(l), putchar('\n');
    }
}
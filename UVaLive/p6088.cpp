// UVALive 6088
#include <cstdio>
#include <cstring>
#define rep(i,j,k) for(i=j;i<(k);++i)
const int inf = 0x7f7f7f7f;
const int N = 1 << 18;

int res[N], count[N], path[N], f[N], less[N], log2[N];
char str[20];

int dp(int mark) {
    if (f[mark] != inf)
        return f[mark];
    
    for (int x = mark; x; x -= x & -x) {
        int lowbit = x & -x;
        int i = log2[lowbit];
        int res = dp(mark ^ lowbit) + count[less[i] & mark];
        if (res < f[mark]) {
            f[mark] = res;
            path[mark] = mark ^ lowbit;
        }
    }

    return f[mark];
}

int main() {
    int i, j, n, full, tot;
    rep(i,1,1<<18) count[i] = count[i ^ (i & -i)] + 1;
    rep(i,0,18) log2[1 << i] = i;
    
    while (scanf("%d", &n) != EOF && n) {
        tot = 0;
        memset(f, 0x7f, sizeof f);
        memset(less, 0, sizeof less);

        rep(i,0,n) {
            scanf("%s", str);
            rep(j,0,n) if (str[j] == '1' && j != i)
                less[j] |= 1 << i;
        }

        int full = (1 << n) - 1;
        f[0] = 0;
        dp(full);

        for (i = full; i; i = path[i])
            res[tot++] = log2[i ^ path[i]];
        rep(i,0,tot) {
            if (i > 0) putchar(' ');
            printf("%d", res[i]);
        }

        printf("\n%d\n", f[full]);
    }

    return 0;
}
#include <cstdio>
#include <cstring>
#define FOR(i,j,k) for(i=j;i<=k;++i)
#define rep(i,j,k) for(i=j;i<k;++i)

int col[64], rb[256], rt[256];
int n;

inline void roll(int i, int j, int k) {
    int a = col[i], b = col[j], c = col[k];
    col[i] = b; col[j] = c; col[k] = a;
}

inline bool judge() {
    int i;
    memset(rb, 0, sizeof rb);
    memset(rt, 0, sizeof rt);
    FOR(i,1,n) {
        if (rb[i + col[i] + 128]) return false;
        if (rt[i - col[i] + 128]) return false;
        rb[i + col[i] + 128] = true;
        rt[i - col[i] + 128] = true;
    }
    return true;
}

int main() {
    int x, y, i, j, k, s = 0;
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d%d", &x, &y), col[x] = y;

    FOR(i,1,n) rep(j,1,i) rep(k,1,j) {
        roll(i, j, k);
        if (judge()) ++s;
        roll(i, j, k);
        if (judge()) ++s;
        roll(i, j, k);
    }
    printf("%d\n", s);
    return 0;
}
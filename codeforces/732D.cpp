#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 100005;
int a[N], d[N], c[N];
int main() {
    int i, n, m;
    scanf("%d%d", &n, &m);
    FOR(i,1,n) scanf("%d", d + i), c[d[i]] = 1;
    FOR(i,1,m) scanf("%d", a + i);
    int spare = 0, subject = 0;
    c[0] = 0; a[0] = -1;
    FOR(i,1,n+1) {
        spare -= a[d[i]];
        subject += c[d[i]];
        c[d[i]] = 0;
        a[d[i]] = -1;
        if (spare >= 0 && subject == m && d[i])
            return printf("%d", i), 0;
    }
    return puts("-1"), 0;
}
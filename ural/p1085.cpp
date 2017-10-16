#include <cstdio>
#include <cstring>
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int inf = 0x7f7f7f7f;
const int N = 110;
int ruble[N], from[N], hasTicket[N];
int stop[N], f[N][N];
int n, k;

void floyd() {
    int i, j, k;
    FOR(k,1,n) FOR(i,1,n) FOR(j,1,n)
        if (f[i][k] != inf && f[k][j] != inf &&
            f[i][j] > f[i][k] + f[k][j])
            f[i][j] = f[i][k] + f[k][j];
}


int main() {
    int m, l, i, j, mi = inf, p, c;

    scanf("%d %d", &n, &m);
    memset(f, 0x7f, sizeof f);
    FOR(i,1,n) f[i][i] = 0;

    while (m--) {
        scanf("%d", &l);
        FOR(i,1,l) scanf("%d", &stop[i]);
        FOR(i,1,l) FOR(j,i+1,l)
            f[stop[i]][stop[j]] = f[stop[j]][stop[i]] = 4;
    }
    
    scanf("%d", &k);
    FOR(i,1,k) scanf("%d%d%d", &ruble[i], &from[i], &hasTicket[i]);
    
    floyd();

    FOR(i,1,n) {
        c = 0;
        FOR(j,1,k) {
            if (f[i][from[j]] == inf || !hasTicket[j] && f[i][from[j]] > ruble[j]) {
                c = inf;
                break;
            }
            if (!hasTicket[j])
                c += f[i][from[j]];
        }
        if (mi > c) {
            mi = c;
            p = i;
        }
    }

    if (mi == inf) puts("0");
    else printf("%d %d\n", p, mi);

    return 0;
}
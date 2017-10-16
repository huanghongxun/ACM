#include <cstdio>
#include <cstring>
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 30;

double dp[N][N][N];
int path[N][N][N];

void output(int i, int j, int t) {
    if (t == 0) printf("%d", i);
    else {
        output(i, path[i][j][t], t - 1);
        printf(" %d", j);
    }
}

int main() {
    int t, i, j, k, n;

    while (~scanf("%d", &n)) {
        memset(dp, 0, sizeof dp);
        FOR(i,1,n) FOR(j,1,n) {
            if (i == j) continue;
            scanf("%lf", &dp[i][j][1]);
            path[i][j][1] = i;
        }

        FOR(t,2,n) FOR(k,1,n) FOR(i,1,n) FOR(j,1,n)
            if (dp[i][j][t] < dp[i][k][t - 1] * dp[k][j][1]) {
                dp[i][j][t] = dp[i][k][t - 1] * dp[k][j][1];
                path[i][j][t] = k;
            }
        FOR(t,2,n) FOR(i,1,n) {
            if (dp[i][i][t] > 1.01) {
                output(i, i, t);
                goto end;
            }
        }
        printf("no arbitrage sequence exists");
        end: putchar('\n');
    }
    return 0;
}
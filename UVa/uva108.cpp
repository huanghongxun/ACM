#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 105;

int mat[N][N], sum[N][N];

int main() {
    int n, i, j, k;
    scanf("%d", &n);

    FOR(i,1,n) FOR(j,1,n) {
        scanf("%d", &mat[i][j]);
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i][j];
    }

    int ans = 0x80000000;
    FOR(i,1,n) FOR(j,1,i) { // j~i
        int mi = 0;
        FOR(k,1,n) {
            int t = sum[i][k] - sum[j - 1][k] - mi;
            if (t > ans) ans = t;
            if (sum[i][k] - sum[j - 1][k] < mi)
                mi = sum[i][k] - sum[j - 1][k];
        }
    }
    printf("%d\n", ans);

    return 0;
}
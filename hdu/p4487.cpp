// UVALive 6175, HDU 4487
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,j,k) for(i=j;i<=k;++i)
using namespace std;
const int OFF = 1000;
double f[2][2005][1005];

int main() {
    int T, n, kase, i, j, k, v;
    double l, r, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%lf%lf", &kase, &n, &l, &r);
        memset(f[0], 0, sizeof f[0]);
        f[0][n][0] = 1;
        FOR(k,1,n) {
            v = k & 1;
            memset(f[v], 0, sizeof f[v]);
            FOR(i,n-k+1,n+k-1) FOR(j,0,k) {
                f[v][i][j] += f[v ^ 1][i][j] * (1 - l - r);
                f[v][i - 1][j] += f[v ^ 1][i][j] * l;
                f[v][i + 1][j + (i - n == j)] += f[v ^ 1][i][j] * r;
            }
        }
        double ans = 0;
        FOR(i,0,n) FOR(j,0,n+n)
            ans += i * f[v][j][i];
        printf("%d %.4lf\n", kase, ans);
    }
    return 0;
}
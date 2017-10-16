#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,j,k) for(i=j;i<=k;++i)
using namespace std;
const int N = 105;
int m[N];
double dp[N * N], p[N];
int main() {
    int t, i, j, n, sum;
    double P;
    scanf("%d", &t);
    while (t--) {
        scanf("%lf%d", &P, &n);
        sum = 0;
        FOR(i,1,n) {
            scanf("%d%lf", &m[i], &p[i]);
            sum += m[i];
        }
        FOR(i,1,sum) dp[i] = 1;
        FOR(i,1,n)
            for (j = sum; j >= m[i]; --j)
                if (j - m[i] == 0) dp[j] = p[i];
                else dp[j] = min(dp[j], dp[j - m[i]] * p[i]);
        for (j = sum; j >= 1; --j) {
            printf("%lf ", dp[j]);
            if (dp[j] <= P)
                break;
        }
        printf("%d\n", j);
    }
    return 0;
}
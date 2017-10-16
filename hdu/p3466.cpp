#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,j,k) for(i=j;i<k;++i)
using namespace std;
struct node {
    int p, q, v;

    bool operator< (const node &b) const {
        return q - p < b.q - b.p;
    }
} a[505];
int dp[5005];
int main() {
    int n, m, i, j;

    while (scanf("%d%d", &n, &m) != EOF) {
        memset(dp, 0, sizeof dp);
        rep(i,0,n) scanf("%d%d%d", &a[i].p, &a[i].q, &a[i].v);
        sort(a, a + n);
        rep(i,0,n)
            for (j = m; j >= a[i].q; --j)
                dp[j] = max(dp[j], dp[j - a[i].p] + a[i].v);
        printf("%d\n", dp[m]);
    }

    return 0;
}
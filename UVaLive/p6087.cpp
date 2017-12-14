// UVALive 6087
#include <cstdio>
#include <algorithm>
#define rep(i,j,k) for(i=j;i<k;++i)
#define FOR(i,j,k) for(i=j;i<=k;++i)
using namespace std;
typedef long long ll;
const int N = 100005;

int fuel[N], pre[N], suf[N], ans[N], mi[N];

int main() {
    int i, n, kase = 0, cnt, st, sum;
    while (scanf("%d", &n) != EOF && n) {
        FOR(i,1,n) scanf("%d", &fuel[i]);
        st = 1; sum = cnt = 0;
        mi[0] = 0x7fffffff;
        FOR(i,1,n) {
            int reduce;
            scanf("%d", &reduce);
            fuel[i] -= reduce;
            sum += fuel[i];
            mi[i] = min(mi[i - 1], sum);
        }
        pre[1] = fuel[1];
        FOR(i,2,n) {
            if (pre[i - 1] < 0) {
                pre[i - 1] = 0;
                st = i;
            }
            pre[i] = pre[i - 1] + fuel[i];
        }
        ans[++cnt] = st;
        suf[n] = pre[n];
        for (i = n - 1; i > st; --i)
            suf[i] = min(suf[i + 1], pre[i]);
        FOR(i,st+1,n)
            if(suf[i] - pre[i - 1] >= 0 && mi[i - 1] + pre[n] - pre[i - 1] >= 0)
                ans[++cnt] = i;
        printf("Case %d:", ++kase);
        FOR(i,1,cnt) printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}
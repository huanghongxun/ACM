#include <cstdio>
#include <queue>
#include <algorithm>
#define rep(i,j,k) for(i=j;i<k;++i)
using namespace std;
double dp[1048576], res[20], arr[20];
queue<int> q;
int main() {
    int cnt0 = 0, i, n, k;
    scanf("%d%d", &n, &k);
    rep(i,0,n) {
        scanf("%lf", &arr[i]);
        cnt0 += (arr[i] == 0.0);
    }
    k = min(n - cnt0, k);
    dp[0] = 1.0;
    q.push(0);
    while (!q.empty()) {
        int prev = q.front(), cnt = 0; q.pop();
        double chance = 1;
        rep(i,0,n) if(prev & (1 << i)) {
            chance -= arr[i];
            ++cnt;
        }
        if (cnt == k) {
            rep(i,0,n) if (prev & (1 << i))
                res[i] += dp[prev];
            continue;
        }
        rep(i,0,n) if (!(prev & (1 << i))) {
            if (dp[prev | (1 << i)] == 0.0 && arr[i] != 0.0)
                q.push(prev | (1 << i));
            dp[prev | (1 << i)] += dp[prev] * (arr[i] / chance);
        }
    }
    rep(i,0,n) printf("%lf ", res[i]);
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define FORD(i,j,k) for(int i=j;i>=k;i--)
const int card[] = {0, 4, 3, 2};
int a[16], b[16], ans;

int sum() {
    int s = 0;
    memset(b, 0, sizeof b);
    FOR(i,0,14) if (i != 1) b[a[i]]++;
    while (b[4] > 0 && b[2] > 1) b[4]--, b[2] -= 2, s++;
    while (b[4] > 0 && b[1] > 1) b[4]--, b[1] -= 2, s++;
    while (b[3] > 0 && b[2] > 0) b[3]--, b[2] -= 1, s++;
    while (b[3] > 0 && b[1] > 0) b[3]--, b[1] -= 1, s++;
    return s + b[4] + b[3] + b[2] + b[1];
}

void dfs(int dep) {
    if (dep >= ans) return;
    int j;
    FORD(x,3,1) {
        FOR(i,3,13) {
            for (j = i; j <= 14 && a[j] >= x; j++);
            int len = (--j) - i + 1;
            if (len > card[x]) {
                FOR(k,i,j) a[k] -= x;
                FOR(k,i+card[x],j) dfs(dep + 1);
                FOR(k,i,j) a[k] += x;
            }
        }
    }
    ans = min(ans, dep + sum());
}

int main() {
    int t, n, x, y;
    scanf("%d%d", &t, &n);
    while (t--) {
        memset(a, 0, sizeof a);
        FOR(i,1,n) {
            scanf("%d%d", &x, &y);
            if (x == 1) x = 14;
            a[x] ++;
        }
        ans = min(n, 13);
        dfs(0);
        printf("%d\n", ans);
    }

    return 0;
}
#include <cstdio>
#include <algorithm>
#define MAX_N 100
#define INT_MAX 0x7ffffff
#define INT_MIN 0xf000000
using namespace std;
int up[MAX_N + 1], down[MAX_N + 1];
int unum, dnum;
int maxNum;
int dp[MAX_N + 1][MAX_N + 1];
int dpsolve(int u, int d) {
    if(u >= unum || d >= dnum) return 0;
    if(dp[u][d] != INT_MAX) return dp[u][d];
    int maxNum = 0;
    
    for(int d1 = d + 1; d1 <= dnum; d1++) {
        if(up[u] != down[d1]) continue;
        for(int u1 = u + 1; u1 <= unum; u1++) {
            if(down[d] != up[u1] || up[u] == up[u1]) continue;
            maxNum = max(maxNum, 2 + dpsolve(u1 + 1, d1 + 1));
        }
    }
    maxNum = max(maxNum, dpsolve(u + 1, d + 1));
    maxNum = max(maxNum, dpsolve(u + 1, d));
    maxNum = max(maxNum, dpsolve(u, d + 1));
    return dp[u][d] = maxNum;
}
int main() {
    int caseNum, i, j;
    scanf("%d", &caseNum);
    while(caseNum--) {
        scanf("%d%d", &unum, &dnum);
        for(i = 1; i <= unum; i++) scanf("%d", &up[i]);
        for(i = 1; i <= dnum; i++) scanf("%d", &down[i]);
        maxNum = INT_MIN;
        for(i = 1; i <= unum; i++)
            for(j = 1; j <= dnum; j++)
                dp[i][j] = INT_MAX;
        dpsolve(1, 1);
        printf("%d\n", dp[1][1]);
    }
    return 0;
}
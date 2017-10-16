// POJ 2599, URAL 1045
#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 1005;
int mp[N][N], dest, n;
bool flag[N];
int dfs(int m) {
    int i;
    FOR(i,1,n) if (mp[m][i] && !flag[i]) {
        flag[m] = true;
        if (!dfs(i)) {
            flag[m] = false;
            dest = i;
            return true;
        }
        flag[m] = false;
    }
    return false;
}
int main() {
    int i, k, u, v;
    scanf("%d%d", &n, &k);
    FOR(i,2,n) {
        scanf("%d%d", &u, &v);
        mp[u][v] = mp[v][u] = 1;
    }
    if (dfs(k))
        printf("First player wins flying to airport %d\n", dest);
    else
        puts("First player loses");
    return 0;
}

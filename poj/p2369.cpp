#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 1005;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int p[N], vis[N];

int main() {
    int n, ans = 1, i;
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d", &p[i]);
    FOR(i,1,n) if (!vis[i]) {
        int x = 0;
        for (int j = i; !vis[j]; j = p[j]) {
            vis[j] = 1;
            ++x;
        }
        ans = lcm(ans, x);
    }
    printf("%d\n", ans);

    return 0;
}
#include <cstdio>
using namespace std;
const int N = 30001, M = 200001;
int read() {
    int s = 0, f = 1; char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
    for (; '0' <= ch && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
    return s * f;
}
int h[N], p[M], v[M], d[N], cnt = 0, ans;
void dfs(int x) {
    ans--; d[x] = 1;
    for (int i = h[x]; i; i = p[i])
        if (!d[v[i]])
            dfs(v[i]);
}
int main() {
    int c, n, x, y;
    ans = read(); c = read(); n = read();
    for(int i = 1; i <= c; i++) {
        x = read(); y = read();
        p[++cnt] = h[x]; v[cnt] = y; h[x] = cnt;
        p[++cnt] = h[y]; v[cnt] = x; h[y] = cnt;
    }
    for(int i = 1; i <= n; i++)
        for (int i = h[read()]; i; i = p[i])
            d[v[i]] = 1;
    dfs(1);
    printf("%d", ans);
    return 0;
}
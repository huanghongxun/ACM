// 聪聪？？？
// 1. 无论Bob怎么走，Alice总是沿AB路径走而且不会某一步选择不动
// 2. Bob不会走回头路（这样做和在某个点停住不动是一个情况）
// 3. 可以认为Bob只在叶子停住不动（选择不动可以在中途也可以在最后，我们调整到最后）
// 4. AB间距不会增大（在2的前提下）
// 5.
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <functional>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
const int inf = 0x7ffffff;
const int N = 200005, M = 2 * N;
#define FOR(i,j,k) for(i=j;i<=k;++i)
#define rep(i,j,k) for(i=j;i<k;++i)

int read() {
    int s = 0, f = 1; char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
    for (; '0' <= ch && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
        return s * f;
}

int h[N], p[M], v[M], vis[N], edge = 0;
int rec1[N], recx[N], path[N], len;

void add(int x, int y) {
    p[++edge] = h[x]; v[edge] = y; h[x] = edge;
    p[++edge] = h[y]; v[edge] = x; h[y] = edge;
}

int n, x;

bool dfs(int x, int fa, int dep) {
    path[dep] = x; len = dep;
    if (x == 1) return true;
    for (int i = h[x]; i; i = p[i])
        if (v[i] != fa && dfs(v[i], x, dep + 1))
            return true;
    return false;
}

void dfs2(int x, int fa, int dep, int *rec) {
    rec[x] = dep;
    for (int i = h[x]; i; i = p[i])
        if (v[i] != fa && !vis[v[i]])
            dfs2(v[i], x, dep + 1, rec);
}

int main() {
    int i, ans = 0;
    n = read(); x = read();
    FOR(i,1,n) rec1[i] = recx[i] = -1;
    FOR(i,2,n) add(read(), read());
    dfs(x, 0, 1); dfs2(1, 0, 1, rec1);
    FOR(i, len / 2 + 1, len) vis[path[i]] = 1;
    if (!vis[x]) dfs2(x, 0, 1, recx);
    FOR(i,1,n) if (recx[i] != -1) ans = max(ans, rec1[i]);
    printf("%d", (ans - 1) * 2);

    return 0;
}
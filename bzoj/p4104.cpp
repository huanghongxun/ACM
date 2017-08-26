#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 200001;
#define FOR(i, j, k) for (i = j; i <= k; i ++)
int a[N], b[N], c[N], d[N], ans[N];

bool cmp(int x, int y) {
    if (a[x] != a[y])
        return a[x] < a[y];
    else if (b[x] != b[y])
        return b[x] < b[y];
    else
        return x < y;
}

int main() {
    int i, n, m, pos = 0;
    scanf("%d%d", &n, &m);
    FOR(i,0,n) scanf("%d", &a[i]), b[i] = a[i], c[i] = i;
    sort(b, b + n + 1); sort(c, c + n + 1, cmp);
    FOR(i,0,n) d[c[i]] = i;
    for (i = n - 1; i >= 0; i--) ans[i] = a[pos], pos = d[pos];
    FOR(i,0,n-1) printf("%d ", ans[i]);
    return 0;
}
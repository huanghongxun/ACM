#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 16384;
int c[32768], x[N], y[N], ans[N];

void add(int i, int x) {
    for (; i <= 33000; i += i & -i)
        c[i] += x;
}

int sum(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i)
        s += c[i];
    return s;
}

int main() {
    int i, n;

    scanf("%d", &n);
    FOR(i,1,n) scanf("%d%d", &x[i], &y[i]), ++x[i], ++y[i];
    FOR(i,1,n) {
        ++ans[sum(x[i])];
        add(x[i], 1);
    }
    FOR(i,0,n-1) printf("%d\n", ans[i]);

    return 0;
}
#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;++i)
int a[200005];
int main() {
    int n, i, s;
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", a + i);
        if (a[i] > 2) {
            a[i] &= 1;
            if (!a[i]) a[i] = 2;
        }
    }
    FOR(i, 1, n + 1) {
    l:
        if (a[i - 1] == 0) {
            if (a[i] == 2) a[i] = 0;
        } else if (a[i - 1] == 1) {
            if (a[i]) { --a[i - 1], --a[i]; goto l; }
            else return puts("NO"), 0;
        }
    }
    return puts("YES"), 0;
}
#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;++i)
int main() {
    int n, a, b, tot = 0, i;
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d", &a), tot += a;
    scanf("%d", &n);
    FOR(i,1,n) {
        scanf("%d%d", &a, &b);
        if (a <= tot && tot <= b) {
            printf("%d", tot);
            goto end;
        } else if (a > tot) {
            printf("%d", a);
            goto end;
        }
    }
    puts("-1");
end:
    return 0;
}
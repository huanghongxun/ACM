#include <cstdio>
#include <algorithm>
#define rep(i,j,k) for(i=j;i<k;i++)
int main() {
    int n, m, i, j, a[10], f[10];
    scanf("%d%d", &n, &m);
    rep(i,0,n) a[i] = i + 1;
    do {
        rep(i,0,n) f[i] = a[i];
        rep(i,0,n - 1) rep(j,0,n-i) f[j] += f[j + 1];
        if (f[0] == m) {
            rep(i,0,n - 1) printf("%d ", a[i]);
            printf("%d\n", a[n - 1]);
            break;
        }
    } while(std::next_permutation(a, a + n));
    return 0;
}

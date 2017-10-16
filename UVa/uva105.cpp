#include <cstdio>
#include <algorithm>
#define rep(i,j,k) for(i=j;i<k;++i)
using namespace std;

int ans[10005];

int main() {
    int L = 0x7fffffff, R = 0, l, h, r, i;
    while (scanf("%d %d %d", &l, &h, &r) == 3) {
        L = min(L, l); R = max(R, r);
        rep(i,l,r) ans[i] = max(ans[i], h);
    }
    rep(i,L,R) if (ans[i] != ans[i - 1])
        printf("%d %d ", i, ans[i]);
    printf("%d %d\n", R, 0);

    return 0;
}
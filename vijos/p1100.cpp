#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

ll a[31], mem[31][31];
ll dp(int left, int right) {   
    if (left <= right) {
        if (mem[left][right] != 0)  return mem[left][right];
        ll ans = 1;
        if (left == right) ans = a[left];
        else for (int i = left; i <= right; i++)
            ans = max(ans, dp(left, i-1)*dp(i+1, right) + a[i]);
        mem[left][right] = ans;
        return ans;
    }
    return 1;
}
void traceback(int l, int r) {   
    if (l < r) {
        for (int i = l; i <= r; i++)
            if (dp(l, r) == dp(l, i-1)*dp(i+1, r) + a[i]) {
                printf("%d ", i+1);
                 traceback(l, i-1);
                 traceback(i+1, r);
                 break;
            }
    } else if (l == r) printf("%d ", l+1);
}
int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%lld", &a[i]);
    memset(mem, 0, sizeof(mem));
    printf("%lld\n", dp(0, n-1));
    traceback(0, n-1);
    printf("\n");
    return 0;
}
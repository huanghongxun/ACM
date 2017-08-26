#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100001;
typedef long long ll;
ll b[N], p[N], n, m, a, bike = 0, z = 0, sum = 0;
void check(ll x) {
    sum = bike = z = 0;
    for(ll i = x, j = n; i > 0; i--, j--)
        if(p[i] <= b[j]) sum += p[i], bike++;
        else if(p[i] <= b[j] + a) sum += b[j], bike++, z += p[i] - b[j];
}
int main() {
    scanf("%I64d%I64d%I64d", &n, &m, &a);
    for (ll i = 1; i <= n; i++) scanf("%I64d", b + i);
    for (ll i = 1; i <= m; i++) scanf("%I64d", p + i);
    sort(b + 1, b + n + 1); sort(p + 1, p + m + 1);
    ll l = 1, r = min(n, m), x = -1;
    while (l <= r) {
        ll mid = l + r >> 1;
        check(mid);
        if (bike == mid && z <= a) l = mid + 1, x = mid; else r = mid - 1;
    }
    if (x == -1) a = -1000, z = 0; else check(x);
    a -= z;
    if (a >= 0 && a >= sum)
        printf("%I64d 0", x);
    else if (a >= 0 && a < sum)
        printf("%I64d %I64d", x, sum - a);
    else if (a < 0)
        printf("0 0");
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
const int N = 100005, M = N * 2;
typedef long long ll;
typedef pair<ll, ll> pii;
int a[N], h[N], p[M], v[M], rt, cnt = 0;
void add(int a, int b) {
    p[++cnt] = h[a]; v[cnt] = b; h[a] = cnt;
    p[++cnt] = h[b]; v[cnt] = a; h[b] = cnt;
}

pii dp(int x, int fa) {
    int i;
    ll now = a[x], ans = 0, remain = 0, use = 0;
    vector<pii> res;
    if (x != rt) --now;
    for (i = h[x]; i; i = p[i])
        if (v[i] != fa)
            res.push_back(dp(v[i], x)), remain += res.rbegin()->second;
    sort(res.begin(), res.end(), greater<pii>());
    for (i = 0; i < res.size() && now; ++i) ans += res[i].first + 2, --now;
    use = min(now, remain); ans += use * 2; now -= use;
    return pii(ans, now);
}

int main() {
    int n, i, x, y;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) scanf("%d", a + i);
    for (i = 1; i < n; ++i) {
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    scanf("%d", &rt);
    printf("%I64d", dp(rt, 0).first);
    return 0;
}
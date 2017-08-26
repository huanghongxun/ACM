#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2005;
const ll mod = 1e8 + 7;
ll n, m, k;
struct Point {
    int x, y;
    Point(int a = 0, int b = 0) : x(a), y(b) { }
    bool operator< (const Point &b) const { return x < b.x || x == b.x && y < b.y; }
    bool operator== (const Point &b) const { return x == b.x && y == b.y; }
} pt[N];
ll nonRemoved() {
    int k = min(n, m), i;
    ll ans = 0;
    for (i = 1; i <= k; ++i)
        ans = (ans + (n - i + 1) * (m - i + 1) % mod * i) % mod;
    return ans;
}
ll onceRemoved0(int l, int r, int h) {
    int z = min(l + r, h);
    if (z == 0) return 0;
    ll ans = z * (z + 3) / 2;
    if (z > l) ans -= (z - l) * (z - l + 1) / 2;
    if (z > r) ans -= (z - r) * (z - r + 1) / 2;
    return ans;
}
ll onceRemoved(int x, int y) {
    int t = x, b = n - x, l = y, r = m - y;
    return (onceRemoved0(t, b, l) + onceRemoved0(t, b, r) + onceRemoved0(l, r, t) + onceRemoved0(l, r, b)
            - min(l, t) - min(t, r) - min(r, b) - min(b, l)) % mod;
}
bool inMap(int x, int y) {
    return 0 <= x && x <= n && 0 <= y && y <= m;
}
void count(Point a, Point b, int &cnt2, int &cnt3, int &cnt4) {
    if (inMap(a.x, a.y) && inMap(b.x, b.y)) {
        t = mp.count(a) + mp.count(b);
        ++cnt2;
        if (t > 0) ++cnt3;
        if (t > 1) ++cnt4, ++cnt3;
    }
}
int main() {
    set<Point> mp;
    int i, j, r, t, x, y, dx, dy;
    scanf("%lld%lld%lld", &n, &m, &k);
    ll ans = nonRemoved();
    for (i = 0; i < k; ++i) {
        scanf("%d%d", &pt[i].x, &pt[i].y); mp.insert(pt[i]);
        (ans -= onceRemoved(pt[i].x, pt[i].y)) %= mod;
    }
    ll cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for (i = 0; i < k; ++i) {
        Point p = pt[i];
        for (j = i + 1; j < k; ++j) {
            Point q = pt[j];
            dx = p.x - q.x, dy = p.y - q.y;
            count(Point(p.x + dy, p.y - dx), Point(q.x + dy, q.y - dx), cnt2, cnt3, cnt4);
            count(Point(p.x - dy, p.y + dx), Point(q.x - dy, q.y + dx), cnt2, cnt3, cnt4);
            if ((abs(dx) + abs(dy)) & 1) continue;
            x = dx - dy >> 1, y = dx + dy >> 1;
            count(Point(p.x - x, p.y - y), Point(q.x + x, q.y + y), cnt2, cnt3, cnt4);
        }
    }
    cnt3 /= 3; cnt4 /= 6;
    ans = (ans + cnt2 - cnt3 + cnt4) % mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
}
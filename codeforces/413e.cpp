#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 200005, inf = 0x3f3f3f3e;

struct Seg {
    int d[2][2];
} t[N * 4];
char mp[2][N];

Seg merge(const Seg &a, const Seg &b) {
    Seg c;
    c.d[0][0] = min(inf, min(a.d[0][0] + b.d[0][0] + 1, a.d[1][0] + b.d[1][1] + 1));
    c.d[0][1] = min(inf, min(a.d[0][1] + b.d[0][1] + 1, a.d[1][1] + b.d[1][0] + 1));
    c.d[1][0] = min(inf, min(a.d[0][0] + b.d[1][0] + 1, a.d[1][0] + b.d[0][1] + 1));
    c.d[1][1] = min(inf, min(a.d[0][1] + b.d[1][1] + 1, a.d[1][1] + b.d[0][0] + 1));
    return c;
}

void build(int k, int l, int r) {
    if (l == r) {
        t[k].d[0][0] = t[k].d[0][1] = 0;
        t[k].d[1][0] = t[k].d[1][1] = 1;
        if (mp[0][l] == 'X') t[k].d[0][0] = t[k].d[1][0] = t[k].d[1][1] = inf;
        if (mp[1][r] == 'X') t[k].d[0][1] = t[k].d[1][0] = t[k].d[1][1] = inf;
    } else {
        int mid = l + r >> 1;
        build(k * 2, l, mid); build(k * 2 + 1, mid + 1, r);
        t[k] = merge(t[k * 2], t[k * 2 + 1]);
    }
}

Seg query(int k, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) return t[k];
    int mid = l + r >> 1;
    if (mid < ql) return query(k * 2 + 1, mid + 1, r, ql, qr);
    else if (qr <= mid) return query(k * 2, l, mid, ql, qr);
    else return merge(query(k * 2, l, mid, ql, mid), query(k * 2 + 1, mid + 1, r, mid + 1, qr));
}

int main() {
    int n, q, i, a, b, l, r;
    scanf("%d %d", &n, &q);
    scanf("%s%s", mp[0] + 1, mp[1] + 1);
    build(1, 1, n);
    while (q--) {
        scanf("%d %d", &a, &b);
        l = (a - 1) % n + 1, r = (b - 1) % n + 1;
        if (l > r) swap(a, b), swap(l, r);
        int ans = query(1, 1, n, l, r).d[((a - 1) / n) != ((b - 1) / n)][a > n];
        printf("%d\n", ans == inf ? -1 : ans);
    }
    return 0;
}
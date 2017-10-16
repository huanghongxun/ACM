#include <cstdio>
#include <algorithm>
using namespace std;

int read() {
    int s = 0, f = 1; char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
    for (; '0' <= ch && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
    return s * f;
}
const int N = 3005;

struct SegX {
    int t[N], tag[N];
    void changeX(int k, int l, int r, int ql, int qr, int qc) {
        t[k] = max(t[k], qc);
        if (l == ql && r == qr) { tag[k] = max(tag[k], qc); return; }
        int mid = l + r >> 1;
        if (mid < ql) changeX(k * 2 + 1, mid + 1, r, ql, qr, qc);
        else if (qr <= mid) changeX(k * 2, l, mid, ql, qr, qc);
        else changeX(k * 2, l, mid, ql, mid, qc), changeX(k * 2 + 1, mid + 1, r, mid + 1, qr, qc);
    }

    int queryX(int k, int l, int r, int ql, int qr) {
        if (l == ql && r == qr) return t[k];
        int mid = l + r >> 1;
        if (mid < ql) return max(tag[k], queryX(k * 2 + 1, mid + 1, r, ql, qr));
        else if (qr <= mid) return max(tag[k], queryX(k * 2, l, mid, ql, qr));
        else return max(tag[k], max(queryX(k * 2, l, mid, ql, mid), queryX(k * 2 + 1, mid + 1, r, mid + 1, qr)));
    }
};

struct SegY {
    SegX t[N], tag[N];
    int ql, qr, qc, n;
    void changeY(int k, int l, int r, int qt, int qb) {
        t[k].changeX(1, 1, n, ql, qr, qc);
        if (l == qt && r == qb) { tag[k].changeX(1, 1, n, ql, qr, qc); return; }
        int mid = l + r >> 1;
        if (mid < qt) changeY(k * 2 + 1, mid + 1, r, qt, qb);
        else if (qb <= mid) changeY(k * 2, l, mid, qt, qb);
        else changeY(k * 2, l, mid, qt, mid), changeY(k * 2 + 1, mid + 1, r, mid + 1, qb);
    }

    int queryY(int k, int l, int r, int qt, int qb) {
        if (l == qt && r == qb) return t[k].queryX(1, 1, n, ql, qr);
        int mid = l + r >> 1, t = tag[k].queryX(1, 1, n, ql, qr);
        if (mid < qt) return max(t, queryY(k * 2 + 1, mid + 1, r, qt, qb));
        else if (qb <= mid) return max(t, queryY(k * 2, l, mid, qt, qb));
        else return max(t, max(queryY(k * 2, l, mid, qt, mid), queryY(k * 2 + 1, mid + 1, r, mid + 1, qb)));
    }
} seg;

int main() {
    int D = read(), S = read(), n = read(), d, s, w, x, y;
    seg.n = D;
    while (n--) {
        d = read(), s = read(), w = read(), x = read(), y = read();
        seg.ql = x + 1; seg.qr = x + d;
        int ma = seg.queryY(1, 1, S, y + 1, y + s);
        seg.qc = ma + w;
        seg.changeY(1, 1, S, y + 1, y + s);
    }
    seg.ql = 1; seg.qr = D;
    printf("%d", seg.queryY(1, 1, S, 1, S));

    return 0;
}
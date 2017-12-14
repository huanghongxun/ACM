#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005, M = N * 4;
typedef long long ll;
ll a[N], b[N];
int mx[M], lmx[M], rmx[M]; // max continuous 'increasing first and decreasing later' sequence.
int po[M], lpo[M], rpo[M]; // max continuous positive sequence.
int ne[M], lne[M], rne[M]; // max continuous negative sequence.

void getMax(int &a, int b) {
    if (a < b)
        a = b;
}

int width(int l, int r) {
    return r - l + 1;
}

bool isPositive(ll a) {
    return a > 0;
}

bool isNegative(ll a) {
    return a < 0;
}

void update(int t, int l, int r, int *M, int *L, int *R, bool callback(ll)) {
    int mid = l + r >> 1;
    int lc = t * 2, rc = t * 2 + 1;
    
    if (l == r) {
        M[t] = L[t] = R[t] = callback(a[l]);
        return;
    }

    M[t] = max(M[lc], M[rc]);
    L[t] = L[lc]; R[t] = R[rc];
    
    if (L[lc] == width(l, mid)) L[t] += L[rc], getMax(M[t], L[t]);
    if (R[rc] == width(mid + 1, r)) R[t] += R[lc], getMax(M[t], R[t]);
    getMax(M[t], R[lc] + L[rc]);
}

void update(int t, int l, int r) {
    int mid = l + r >> 1;
    int lc = t * 2, rc = t * 2 + 1;
    
    update(t, l, r, po, lpo, rpo, isPositive);
    update(t, l, r, ne, lne, rne, isNegative);

    if (l == r) {
        mx[t] = lmx[t] = rmx[t] = a[l] != 0;
        return;
    }

    mx[t] = max(max(mx[lc], mx[rc]), max(rpo[lc] + lmx[rc], rmx[lc] + lne[rc]));
    lmx[t] = lmx[lc];
    if (mx[lc] == width(l, mid)) lmx[t] = max(lmx[t], mx[lc] + lne[rc]);
    if (po[lc] == width(l, mid)) lmx[t] = max(lmx[t], po[lc] + lmx[rc]);

    rmx[t] = rmx[rc];
    if (mx[rc] == width(mid + 1, r)) rmx[t] = max(rmx[t], rpo[lc] + mx[rc]);
    if (ne[rc] == width(mid + 1, r)) rmx[t] = max(rmx[t], rmx[rc] + ne[rc]);
}

void modify(int t, int l, int r, int x, int v) {
    if (l == r) {
        a[x] += v;
    } else {
        int mid = l + r >> 1;
        if (x <= mid) modify(t * 2, l, mid, x, v);
        else modify(t * 2 + 1, mid + 1, r, x, v);
    }
    update(t, l, r);
}

void build(int t, int l, int r) {
    int mid = l + r >> 1;
    if (l < r) {
        build(t * 2, l, mid);
        build(t * 2 + 1, mid + 1, r);
    }
    update(t, l, r);
}

int main() {
    int n, m, i, x, y, z;
    scanf("%d%d", &n, &m);

    for (i = 1; i <= n; ++ i) {
        scanf("%lld", &b[i]);
        a[i] = b[i] - b[i - 1];
    }
    build(1, 2, n);

    while (m --) {
        scanf("%d%d%d", &x, &y, &z);
        if (x >= 2)
            modify(1, 2, n, x, z);
        if (y + 1 <= n)
            modify(1, 2, n, y + 1, -z);
        printf("%d\n", mx[1] + 1);
    }
    return 0;
}
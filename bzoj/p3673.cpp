#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;
const int M = 200001;
class PersistantArray {
    struct Node {
        int v;
        Node *lc, *rc;
    } *a[M];
    Node pool[M * 20], *C;
    Node *new_node(Node *lc, Node *rc, int v) {
        C->lc = lc; C->rc = rc; C->v = v; return C++;
    }
    int version, last, n;

    Node *modify(Node *p, int l, int r, int pos, int val) {
        int mid = l + r >> 1;
        if (l == r)
            return new_node(NULL, NULL, val);
        else if (pos <= mid)
            return new_node(modify(p->lc, l, mid, pos, val), p->rc, 0);
        else
            return new_node(p->lc, modify(p->rc, mid + 1, r, pos, val), 0);
    }

    int get(Node *p, int l, int r, int pos) {
        int mid = l + r >> 1;
        if (l == r)
            return p->v;
        else if (pos <= mid)
            return get(p->lc, l, mid, pos);
        else
            return get(p->rc, mid + 1, r, pos);
    }

public:
    PersistantArray(int initial_capacity, int initial_data)
        : C(pool), version(0), last(0), n(initial_capacity) {
        a[0] = C++; a[0]->lc = a[0]->rc = a[0]; a[0]->v = initial_data;
    }
    void roll(int new_version) { version = new_version; }
    int latest_version() { return last; }
    int get(int x) { return get(a[version], 1, n, x); }
    void set(int x, int y) { a[++last] = modify(a[version], 1, n, x, y); }
    void set(int x, int y, bool) { modify(a[version], 1, n, x, y); }
} *fa, *sz;
int now = 0, ver[M];
int find(int x) {
    int fx = fa->get(x);
    if (!fx) return x;
    int ans = find(fx);
    fa->set(x, ans, false);
    return ans;
}
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    int sx = sz->get(x), sy = sz->get(y);
    if (sx < sy) swap(x, y), swap(sx, sy);
    fa->set(y, x); sz->set(x, sx + sy);
    now = fa->latest_version();
}

int main() {
    int i, p, x, y, n, m, ans = 0;
    scanf("%d%d", &n, &m);
    fa = new PersistantArray(n, 0);
    sz = new PersistantArray(n, 1);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &p); fa->roll(now); sz->roll(now);
        switch (p) {
        case 1: scanf("%d%d", &x, &y); merge(x, y); break;
        case 2: scanf("%d", &x); now = ver[x]; break;
        case 3: scanf("%d%d", &x, &y); printf("%d\n", find(x) == find(y)); break;
        }
        ver[i] = now;
    }

    return 0;
}
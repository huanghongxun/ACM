#include <cstdio>
const int N  = 610000;

int K = 1 << 24;
struct Trie {
    Trie *s[2];
    int sum;

    static Trie pool[N * 30], *C;
    void *operator new(size_t);

    static Trie *insert(Trie *p, int x, int dight) {
         Trie *rt = new Trie;
         rt->s[0] = p->s[0];
         rt->s[1] = p->s[1];
         rt->sum = p->sum + 1;
         if (!dight) return rt;
         int t = bool(x & dight);
         rt->s[t] = insert(p->s[t], x, dight >> 1);
         return rt;
    }

    static Trie *insert(Trie *p,  int x) {
        return insert(p, x, K);
    }

    static int query(Trie *p, Trie *q, int x, int dight) {
        if (!dight) return 0;
        int t = bool(x & dight);
        if (q->s[t ^ 1]->sum - p->s[t ^ 1]->sum)
            return dight | query(p->s[t ^ 1], q->s[t ^ 1], x, dight >> 1);
        else
            return query(p->s[t], q->s[t], x, dight>>1);
    }

    static int query(Trie *p, Trie *q, int x) {
        return query(p, q, x, K);
    }

    static void init();
} *trie_impl[N], *null, **trie = trie_impl;
Trie Trie::pool[N * 30], *Trie::C;
void *Trie::operator new(size_t) {
    return C++;
}
void Trie::init() {
    Trie::C = Trie::pool;
    trie[-1] = null = new Trie();
    null->s[0] = null->s[1] = null;
}

int n,m;
int a[N];
char tmp[10];
int main() {
    int i, l, r, x; char p[10];
    scanf("%d%d", &n, &m);
    Trie::init();
    for (int i=1;i<=n;i++) scanf("%d", &a[i]), a[i] ^= a[i - 1];
    for (int i=0;i<=n;i++) trie[i] = Trie::insert(trie[i - 1], a[i]);
    while (m--) {
        scanf("%s", p);
        if (p[0] == 'A'){
            scanf("%d", &a[++n]);
            a[n] ^= a[n - 1];
            trie[n] = Trie::insert(trie[n - 1], a[n]);
        } else {
            scanf("%d%d%d", &l, &r, &x);
            int ans = Trie::query(trie[l - 2], trie[r - 1], x ^ a[n]);
            printf("%d\n", ans);
        }
    }
    return 0;
}
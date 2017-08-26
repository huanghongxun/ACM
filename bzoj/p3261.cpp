#include <cstdio>
const int N = 600001;
int a[N], n, m; 
struct Trie {
    Trie* c[2]; int size;
    Trie() { c[0] = c[1] = this; size = 0; }
    Trie(Trie *l, Trie *r, int sz) { c[0] = l, c[1] = r, size = sz; }
    void* operator new(size_t) {
        static Trie pool[N * 30], *pointer = pool;
        return pointer++;
    }
    static Trie* put(Trie *p, int x, int digit) {
        if (!digit)
            return new Trie(p->c[0], p->c[1], p->size + 1);
        if (x & digit)
            return new Trie(p->c[0], put(p->c[1], x, digit >> 1), p->size + 1);
        else
            return new Trie(put(p->c[0], x, digit >> 1), p->c[1], p->size + 1);
    }
    static int get(const Trie *p1, const Trie *p2, int x, int digit) {
        if (!digit)
            return 0;
        bool t = bool(~x & digit);
        if (p1->c[t]->size - p2->c[t]->size)
            return digit | get(p1->c[t], p2->c[t], x, digit >> 1);
        else
            return get(p1->c[t ^ 1], p2->c[t ^ 1], x, digit >> 1);
    }
} *trie_impl[N], **trie = trie_impl + 1;

int main() {
    int i, l, r, x; char p[10];
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        scanf("%d", a + i), a[i] ^= a[i - 1];
    trie[-1] = new Trie();
    for (i = 0; i <= n; i++)
        trie[i] = Trie::put(trie[i - 1], a[i], 1 << 24);
    while (m--) {
        scanf("%s", p);
        if (p[0] == 'A') {
            scanf("%d", &a[++n]); a[n] ^= a[n - 1];
            trie[n] = Trie::put(trie[n - 1], a[n], 1 << 24);
        } else {
            scanf("%d%d%d", &l, &r, &x);
            printf("%d\n", Trie::get(trie[r - 1], trie[l - 2], a[n] ^ x, 1 << 24));
        }
    }
    return 0;
}
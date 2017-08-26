#include <cstdio>
#include <algorithm>
#define N 400001
using namespace std;
int n, ans, ma, a[N];
struct Trie {
    Trie* c[2]; int size;
    Trie() { c[0] = c[1] = NULL; size = 0; }
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
    static int get(const Trie *p1, const Trie *p2, int x, int digit, int k) {
        int i, temp = 0;
        if (!digit)
            return 0;
        bool rson = bool(~stack3[i] & digit), son = rson ^ 1;
        for (i = 1; i <= top; i++) {
            temp += stack1[i]->c[rson]->size;
            temp -= stack2[i]->c[rson]->size;
        }
        if (k <= temp) {
            for (i = 1; i <= top; i++) {
                stack1[i] = stack1[i]->c[rson];
                stack2[i] = stack2[i]->c[rson];
            }
            return digit | get(stack1, stack2, stack3, x, digit >> 1, k);
        } else {
            for (i = 1; i <= top; i++) {
                stack1[i] = stack1[i]->c[ son];
                stack2[i] = stack2[i]->c[ son];
            }
            return         get(stack1, stack2, stack3, x, digit >> 1, k - temp);
        }
    }
} *trie_impl[N], **trie = trie_impl + 1;
void getmax(int &a, int b) { if (a < b) a = b; }
int main() {
    int i, dep = 1 << 30;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
        a[i] ^= a[i - 1];
    }
    trie[-1] = new Trie();
    trie[-1]->c[0] = trie[-1]->c[1] = trie[-1];
    for (i = 0; i <= n; i++)
        trie[i] = Trie::put(trie[i - 1], a[i], dep);
    for (i = n - 1; i; i--) {
        
    }
    printf("%d", ans);
    return 0;
}
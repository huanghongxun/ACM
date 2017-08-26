#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#define N 200005
#define rep(i,j,k) for(int i=j;i<k;i++)
int sz[N], l[N], r[N], fa[N], rev[N], sk[N];

int n, m, k;
struct Data {
    unsigned a[32][2];
    Data() { rep (i,0,32) a[i][0]=0,a[i][1]=1; }
    Data(unsigned x) {
        rep(i,0,k) a[i][0]=1, a[i][1]=(x & (1u << i)) ? 0 : 1;
    }
    friend Data operator & (const Data &x, const Data &y) {
        static Data c;
        rep (i, 0, k) c.a[i][0] = y.a[i][x.a[i][0]], c.a[i][1] = y.a[i][x.a[i][1]];
        return c;
    }
    unsigned val() {
        unsigned res = 0;
        rep (i, 0, k) res |= a[i][0] << i;
    }
} val[N], lsum[N], rsum[N];

void init(int x, unsigned data) {
    val[x] = lsum[x] = rsum[x] = data;
}
  
void update(int x) {
    lsum[x] = lsum[l[x]] & val[x] & lsum[r[x]];
    lsum[x] = rsum[r[x]] & val[x] & rsum[l[x]];
}  
  
void pushdown(int x) {  
    if (rev[x]) rev[x] ^= 1, rev[l[x]] ^= 1, rev[r[x]] ^= 1, std::swap(l[x], r[x]); 
}  
  
bool isRoot(int x) {  
    return l[fa[x]] != x && r[fa[x]] != x;  
}  
  
void lrotate(int i) {  
    int z = r[i]; r[i] = l[z]; fa[r[i]] = i; l[z] = i;  
    if (i == l[fa[i]]) l[fa[i]] = z;  
    else if (i == r[fa[i]]) r[fa[i]] = z;  
    fa[z] = fa[i]; fa[i] = z;  
    update(i); update(z);  
}  
  
void rrotate(int i) {  
    int z = l[i]; l[i] = r[z]; fa[l[i]] = i; r[z] = i;  
    if (i == l[fa[i]]) l[fa[i]] = z;  
    else if (i == r[fa[i]]) r[fa[i]] = z;  
    fa[z] = fa[i]; fa[i] = z;  
    update(i); update(z);  
}  
  
void spaly(int x) {  
    int top = 0;  
    sk[++top] = x;  
    for (int i = x; !isRoot(i); i = fa[i]) sk[++top] = fa[i];  
    while (top) pushdown(sk[top--]);  
    while (!isRoot(x))  
        if (x == l[fa[x]]) rrotate(fa[x]);  
        else lrotate(fa[x]);  
    update(x);  
}  
  
void access(int x) { for(int t = 0; x; t = x, x = fa[x]) { spaly(x); r[x] = t; update(x); } }  
void makeroot(int x) { access(x); spaly(x); rev[x] ^= 1; }  
void modify(int x, Data v) { access(x); val[x] = v; update(x); }
void link(int x, int y) { makeroot(x); fa[x] = y; }
  
int main() {  
    int x, y; unsigned z;
    char op[10];
    scanf("%d%d%d", &n, &m, &k);
    rep(i,0,n) {
        scanf("%u",&z);
        init(i + 1, z);
    }
    rep(i,1,n) {
        scanf("%d%d", &x, &y);
        link(x, y);
    }
    rep(i,0,m) {
        scanf("%s", op);
        if (op[0] == 'Q') {
            scanf("%d%d", &x, &y);
            makeroot(x); access(y); spaly(y);
            printf("%u\n", lsum[y].val());
        } else {
            scanf("%d%u", &x, &z);
            spaly(x); val[x] = Data(z); update(x);
        }
    }
    return 0; 
}  
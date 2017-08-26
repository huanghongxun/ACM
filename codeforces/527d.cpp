#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define N 200001
int c[N * 2], v[N * 2];
int n, sz = 0;
inline int lowbit(int x) { return x & -x; }
inline int sum(int x) {
    int s = 0;
    for (; x >= 1; x -= lowbit(x)) s = max(c[x], s);
    return s; 
}
inline void update(int i, int x) {
    for (; i <= sz; i += lowbit(i)) c[i] =  max(c[i], x);
}
struct Ask {
    int x, l, r;
    friend bool operator < (const Ask &a, const Ask &b) {
        return a.x < b.x;
    }
} q[N];
map<int, int> hash;
int main(){
    int w, i;
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d%d", &q[i].x, &w);
        q[i].l = q[i].x - w;
        q[i].r = q[i].x + w;
    }
    sort(q + 1, q + 1 + n);
    FOR(i,1,m) {
        if(!hash.count(q[i].l)) hash[q[i].l]  = ++sz;
        if(!hash.count(q[i].r)) hash[q[i].r]  = ++sz;
    }
    FOR(i,1,n) update(hash[q[i].r], sum(hash[q[i].l]) + 1);
    printf("%d\n", sum(sz)); 
    return 0;
}
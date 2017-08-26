#include <cstdio>
#include <algorithm>
using namespace std;
int read() {
    int s=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;'0'<=ch&&ch<='9';ch=getchar())s=s*10+ch-'0';
    return s*f;
}
const int N = 100001, M = 5000001;
struct Flower {int a,b,c;
friend bool operator <(const Flower &a, const Flower &b) {
    return (a.a==b.a)?((a.b==b.b)?(a.c<b.c):(a.b<b.b)):(a.a<b.a);
}}f[N];
int s[M], l[M], r[M], w[M], v[M], rnk[M], root[N*2], ans[N], sum[N], id=0, n, m;
void upd(int k){s[k]=s[l[k]]+s[r[k]]+w[k];}
void lrot(int &k){int t=r[k];r[k]=l[t];l[t]=k;upd(k);upd(t);k=t;}
void rrot(int &k){int t=l[k];l[k]=r[t];r[t]=k;upd(k);upd(t);k=t;}
void insert(int &k, int x) {
    if(!k){k=++id;rnk[k]=rand();v[k]=x;s[k]=w[k]=1;return;}
    s[k]++;
    if(x==v[k])w[k]++;
    else if(x<v[k]) {insert(l[k],x);if(rnk[l[k]]<rnk[k])rrot(k);}
    else {insert(r[k],x);if(rnk[r[k]]<rnk[k])lrot(k);}
}
int rank(int k, int x) {
    if (!k) return 0;
    if (x == v[k]) return s[l[k]] + w[k];
    else if(x < v[k]) return rank(l[k], x);
    else return s[l[k]] + w[k] + rank(r[k], x);
}
int query(int k, int x) {
    int ans=0;
    for (; k; k -=  k & -k) ans += rank(root[k], x);
    return ans;
}
void add(int k, int x) {
    for (; k <= m; k += k & -k) insert(root[k], x);
}
int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++)
        f[i].a = read(), f[i].b = read(), f[i].c = read();
    sort(f + 1, f + n + 1);
    for (int i = 1; i <= n; i ++) {
        if (f[i].a == f[i+1].a && f[i].b == f[i+1].b && f[i].c == f[i+1].c && i!=n)
            sum[i+1] += sum[i] + 1;
        else
            ans[query(f[i].b,f[i].c)]+=sum[i]+1;
        add(f[i].b, f[i].c);
    }
    for (int i = 0; i < n; i ++)
        printf("%d\n", ans[i]);
    return 0;
}
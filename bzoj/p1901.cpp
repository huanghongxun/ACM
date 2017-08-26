#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define MAXN 10005
#define MAXA 1000000005
int n,m,a[MAXN];
struct node
{
    int ch[2],c,fa;
    node():c(0),fa(0){ch[0]=ch[1]=0;}
} q[MAXN*4*100];
int root[MAXN]={0},tot=0;
void insert(int &x,int l,int r,int c,int d)
{
    if (!x) x=++tot;
    q[x].c+=d;
    int m=l+r>>1;
    if (l==r) return;
    if (c<=m) insert(q[x].ch[0],l,m,c,d),q[q[x].ch[0]].fa=x;
    else insert(q[x].ch[1],m+1,r,c,d),q[q[x].ch[1]].fa=x;
}
void update(int x,int c,int d)
{
    for(int i=x;i<=n;i+=i&(-i)) insert(root[i],MINAi,MAXAi,c,d);
}
int ans[MAXN],ans_siz=0;
void qur(int x) {
    for(int i=x;i;i-=i&(-i)) ans[++ans_siz]=root[i];
}
void turn(bool c) {
    int i;
    FOR(i, 1, ans_siz) ans[i] = q[ans[i]].ch[c];
}
int main()
{
    int l, r, k, i;
    scanf("%d%d",&n,&m);
    For(i, n) scanf("%d",&a[i]),update(i,a[i],1);
    while (m--) {
        char c[2];
        scanf("%s",c);
        switch(c[0]) {
        case 'C':
            scanf("%d%d", &k, &k);
            update(l, a[l], -1);
            update(l, a[l] = k, 1);
            break;
        case 'Q':
            scanf("%d%d%d", &l, &r, &k);
            ans_siz = 0;
            qur(r);
            int ad_end = ans_siz;
            qur(l-1);	
            l = MINAi, r = MAXAi;
            while (l<r) {
                int m = l + r >> 1, s = 0;
                FOR(i, 1, ad_end) s+=q[q[ans[i]].ch[0]].c;
                FOR(i, ad_end + 1, ans_siz) s-=q[q[ans[i]].ch[0]].c;
                if (k <= s) turn(0), r = m;
                else turn(1), l = m + 1, k -= s;
            }
            cout<<l<<endl;
            break;
        }
    }
    
    return 0;
}
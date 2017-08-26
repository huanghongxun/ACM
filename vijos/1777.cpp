#include <cstdio>
#include <iostream>
#include <cstring>
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define INF (~0U>>4)
using namespace std;
int n,m;
int h[502][502];
int f[502];
bool arr[502];
typedef void (*FOR_CALLBACK)(int,int,int);
struct Q
{
    int x,y;
} q[1000006];
int ll[502][502],rr[502][502];
int ans1=0;
bool vst[502][502];
const int px[4]={0,1,0,-1},py[4]={1,0,-1,0};
bool check(int x,int y) {
    if (x<0 || y<0) return false;
    if (x>n || y>m) return false;
    if (vst[x][y]) return false;
    return true;
}
void forcallback1(int newx, int newy, int u) {
    ll[newx][newy]=u;
}
void forcallback2(int newx, int newy, int u) {
    rr[newx][newy]=u;
}
void bfs(int u)
{ 
    int l=0,r=0;
    q[++r].x=1,q[r].y=u;
    vst[1][u]=true;
    while (l!=r)
    {
        ++l;
        l%=1000006;
        Q x=q[l];
        for (int i=0;i<4;i++)
            if (check(x.x+px[i],x.y+py[i]) && h[x.x][x.y]>h[x.x+px[i]][x.y+py[i]])
            {
                vst[x.x+px[i]][x.y+py[i]]=true;
                ++r,r%=1000006;
                q[r].x=x.x+px[i],q[r].y=x.y+py[i];
            }
    }
}
void bfs2(int u, FOR_CALLBACK func)
{ 
    int l=0,r=0;
    q[++r].x=1,q[r].y=u;
    vst[n][u]=true;
    while (l!=r)
    {
        ++l;
        l%=1000006;
        Q x=q[l];
        for (int i=0;i<4;i++)
            if (check(x.x+px[i],x.y+py[i]) && h[x.x][x.y]<h[x.x+px[i]][x.y+py[i]])
            {
                vst[x.x+px[i]][x.y+py[i]]=true;
                (*func)(x.x+px[i],x.y+py[i],u);
                ++r,r%=1000006;
                q[r].x=x.x+px[i],q[r].y=x.y+py[i];
            }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int i,j;
    FOR(i,1,n) FOR(j,1,m) scanf("%d",h[i]+j);
    FOR(i,1,m) if (!vst[1][i]) bfs(i);
    int x=0;
    FOR(i,1,m) x+=vst[n][i];
    if (x!=m) {
        puts("0");
        printf("%d\n",m-x);
        return 0;
    }
    memset(vst,0,sizeof(vst));
    FOR(i,1,m) if (!vst[n][i]) { ll[n][i]=i; Bfs1(i); }
    memset(vst,0,sizeof(vst));
    for (i=m;i;i--) if (!vst[n][i]) { rr[n][i]=i; Bfs2(i); }
    FOR(i,1,m) if (ll[1][i]) f[ll[1][i]]=max(f[ll[1][i]],rr[1][i]);
    int last=f[1],r=f[1];
    int ans=1;
    for (i=1;i<=m && last<m;i++) {
        if (i>last) last=max(f[i],r),ans++;
        r=max(r,f[i]);
    }
    puts("1");
    printf("%d\n",ans);
    return 0;
}
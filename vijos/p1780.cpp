#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#define inf 5000000000LL
#define ll long long
#define FOR(i,j,k) for(i=j;i<=k;i++)
using namespace std;
int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int N = 100005;
int bin[20];
int n;
int h[N];
ll a[N],b[N],va[N][17],vb[N][17];
int fa[N],fb[N],to[N][17];
set<ll> q;
map<ll,int> mp;
struct data{ll h,key;}t[5];
bool operator<(data a,data b) {
    return a.key<b.key||(a.key==b.key&&a.h<b.h);
}
void pre() {
	int j, k;
    for(int i=n;i;i--) {
        q.insert(h[i]);
        t[1].h=*--q.lower_bound(h[i]),t[2].h=*q.upper_bound(h[i]);
        if(t[1].h!=-inf)t[3].h=*--q.lower_bound(t[1].h);
		else t[3].h=-inf;
		if(t[2].h!=inf)t[4].h=*q.upper_bound(t[2].h);
		else t[4].h=inf;
        FOR(k,1,4)
            t[k].key=abs(t[k].h-h[i]);
        sort(t+1,t+5);
        a[i]=t[2].key;fa[i]=mp[t[2].h];
        b[i]=t[1].key;fb[i]=mp[t[1].h];
        FOR(j,0,16)
            if(j==0) {
                if(fa[i]){va[i][0]=a[i];to[i][0]=fa[i];}
            } else if(j==1) {
                if(fb[fa[i]]){va[i][1]=a[i];vb[i][1]=b[fa[i]];to[i][1]=fb[fa[i]];}
            } else if(to[to[i][j-1]][j-1]) {
                va[i][j]=va[i][j-1]+va[to[i][j-1]][j-1];
                vb[i][j]=vb[i][j-1]+vb[to[i][j-1]][j-1];
                to[i][j]=to[to[i][j-1]][j-1];
            }
			else break;
    }
}
pair<int,int> cal(int x,int val) {
    int t1=0,t2=0;
    for(int i=16;i>=0;i--)
        if(to[x][i]&&t1+va[x][i]+t2+vb[x][i]<=val) {
            t1+=va[x][i];t2+=vb[x][i];
            x=to[x][i];
        }
    return make_pair(t1,t2);
}
void solve1() {
    double mn=1e60;int ans,x0=read(),i;
    FOR(i,1,n) {
    	pair<int,int> p=cal(i,x0);
        double t=p.second==0?inf:(1.0*p.first/p.second);
        if(t<mn||(t==mn&&h[i]>h[ans])) {
            mn=t;ans=i;
        }
    }
    printf("%d\n",ans);
}
void solve2() {
    int m=read(),i;
    FOR(i,1,m) {
        int s=read(),x=read();
        pair<int,int> p=cal(s,x);
        printf("%d %d\n", p.first,p.second);
    }
}
int main() {
    n=read(); int i;
    q.insert(-inf);q.insert(inf);
    FOR(i,1,n) mp[h[i]=read()]=i;
    pre(); solve1(); solve2();
    return 0;
}
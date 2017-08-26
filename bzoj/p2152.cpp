#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<algorithm>
#define ll long long
#define inf 1000000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,cnt,ans,root,sum;
int last[20005],son[20005],f[20005],d[20005],t[5];
bool vis[20005];
struct edge{int to,next,v;}e[40005];
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
void insert(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;e[cnt].v=w;
}
void getroot(int x,int fa) {
	son[x]=1;f[x]=0;
	for(int i=last[x];i;i=e[i].next)
		if(!vis[e[i].to]&&e[i].to!=fa) {
			getroot(e[i].to,x);
			son[x]+=son[e[i].to];
			f[x]=max(f[x],son[e[i].to]);
		}
	f[x]=max(f[x],sum-son[x]);
	if(f[x]<f[root])root=x;
}
void getdeep(int x,int fa) {
	t[d[x]]++;
	for(int i=last[x];i;i=e[i].next)
		if(!vis[e[i].to]&&e[i].to!=fa) {
			d[e[i].to]=(d[x]+e[i].v)%3;
			getdeep(e[i].to,x);
		}
}
int cal(int x,int now) {
    t[0]=t[1]=t[2]=0;
    d[x]=now;getdeep(x,0);
	return t[1]*t[2]*2+t[0]*t[0];
}
void work(int x) {
	ans+=cal(x,0);
	vis[x]=1;
	for(int i=last[x];i;i=e[i].next)
		if(!vis[e[i].to]) {
			ans-=cal(e[i].to,e[i].v);
			root=0;sum=son[e[i].to];
			getroot(e[i].to,0);
			work(root);
		}
}
int main() {
	n=read();
	for(int i=1;i<n;i++) {
		int u=read(),v=read(),w=read()%3;
		insert(u,v,w);
	}
	f[0]=sum=n;
	getroot(1,0);
	work(root);
	int t=gcd(ans,n*n);
	printf("%d/%d",ans/t,n*n/t);
	return 0;
}
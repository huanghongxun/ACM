#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,K,cnt,sum,ans,root;
int head[10005],deep[10005],d[10005],f[10005],son[10005];
bool vis[10005];
struct data{int to,next,v;}e[20005];
void ins(int u,int v,int w)
{e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;e[cnt].v=w;}
void insert(int u,int v,int w)
{ins(u,v,w);ins(v,u,w);}
void getroot(int x,int fa)
{
	son[x]=1;f[x]=0;
	for(int i=head[x];i;i=e[i].next)
	{
		if(e[i].to==fa||vis[e[i].to])continue;
		getroot(e[i].to,x);
		son[x]+=son[e[i].to];
		f[x]=max(f[x],son[e[i].to]);
	}
	f[x]=max(f[x],sum-son[x]);
	if(f[x]<f[root])root=x;
}
void getdeep(int x,int fa)
{
	deep[++deep[0]]=d[x];
	for(int i=head[x];i;i=e[i].next)
	{
		if(e[i].to==fa||vis[e[i].to])continue;
		d[e[i].to]=d[x]+e[i].v;
		getdeep(e[i].to,x);
	}
}
int cal(int x,int now)
{
	d[x]=now;deep[0]=0;
	getdeep(x,0);
	sort(deep+1,deep+deep[0]+1);
	int t=0,l,r;
	for(l=1,r=deep[0];l<r;)
	{
		if(deep[l]+deep[r]<=K){t+=r-l;l++;}
        else r--;
    }
	return t;
}
void work(int x)
{
	ans+=cal(x,0);
	vis[x]=1;
	for(int i=head[x];i;i=e[i].next)
	{
		if(vis[e[i].to])continue;
		ans-=cal(e[i].to,e[i].v);
		sum=son[e[i].to];
		root=0;
		getroot(e[i].to,root);
		work(root);
	}
}
int main()
{
	while(1)
	{
		ans=0;root=0;cnt=0;
		memset(vis,0,sizeof(vis));
		memset(head,0,sizeof(head));
	    n=read();K=read();
		if(n==0)break;
	    for(int i=1;i<n;i++)
     	{
    		int u=read(),v=read(),w=read();
    		insert(u,v,w);
    	}
    	sum=n;f[0]=inf;
     	getroot(1,0);
    	work(root);
    	printf("%d\n",ans);
    }
	return 0;
}

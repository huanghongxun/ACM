#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define mod 1000000007
#define inf 1000000000
#define ll long long
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int top,cnt;
int b[105],last[105],ans[105],mark[105];
int d[105],tmp[105];
string a;
struct edge{
	int to,next;
}e[5005];
void insert(int u,int v)
{
	e[++cnt]=(edge){v,last[u]};last[u]=cnt;
	d[v]++;
}
bool check(int x,int id)
{
	for(int i=1;i<=top;i++)tmp[b[i]]=d[b[i]];
	for(int i=1;i<x;i++)
	{
		int t=ans[i];
		for(int j=last[t];j;j=e[j].next)
			tmp[e[j].to]--;
	}
	return tmp[id]==0;
}
void dfs(int x)
{
	if(x==top+1)
	{
		for(int i=1;i<=top;i++)
			printf("%c",ans[i]+'a');
		puts("");
		return;
	}
	for(int i=1;i<=top;i++)
		if(!mark[i]&&check(x,b[i]))
		{
			ans[x]=b[i];
			mark[i]=1;
			dfs(x+1);
			mark[i]=0;
		}
}
int main()
{
	while(getline(cin,a))
	{
		cnt=top=0;
		memset(last,0,sizeof(last));
		memset(d,0,sizeof(d));
		for(int i=0;i<a.length();i+=2)
			b[++top]=a[i]-'a';
		sort(b+1,b+top+1);
		getline(cin,a);
		for(int i=0;i<a.length();i+=4)
			insert(a[i]-'a',a[i+2]-'a');
		dfs(1);
		puts("");
	}
	return 0;
}

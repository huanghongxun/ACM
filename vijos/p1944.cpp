#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <cmath>
#include <map>
#include <functional>
#include <utility>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef long long ll;
#define inf 0x7ffffff
#define eps 1e-6
#define rep(i,j,k) for(i=j;i<k;i++)
#define repd(i,j,k) for(i=j-1;i>=k;i--)
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define foreach(i,j) for(i=j.begin();i!=j.end();i++)

ll read() {
    ll x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}

#define N 1005
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

pair<int,int> ask[100005], node[N*N];
int mp[N][N], vis[N*N], visnum=0, res[100005];
int fa[N*N];

int n, m, ans=0;

int find(int i) {
	return fa[i]==i?i:fa[i]=find(fa[i]);
}

bool merge(int x, int y) {
	int f1=find(x),f2=find(y);
	if(f1==f2) return 0;
	fa[f1]=f2;
	return 1;
}

int main() {
	n = read(); m = read();
	int i, j;
	rep(i,0,n) rep(j,0,m) node[i*m+j].first=mp[i][j]=read(),node[i*m+j].second=fa[i*m+j]=i*m+j;
	int t = read();
	rep(i,0,t) ask[i]=make_pair(read(),i);
	sort(ask,ask+t,greater<pair<int,int> >());
	sort(node,node+n*m,greater<pair<int,int> >());
	int p=0;
	rep(i,0,t) {
		while(node[p].first>ask[i].first) {
			if(!vis[node[p].second]) {
				ans++;
				vis[node[p].second]=1;
				//printf("NEW %d %d\n", node[p].second/m+1, node[p].second%m+1);
			}
			FOR(j,0,3) {
				int tx=node[p].second/m+dx[j],ty=node[p].second%m+dy[j];
				if(0<=tx&&tx<n&&0<=ty&&ty<m&&vis[tx*m+ty]) {
					int t=merge(node[p].second,tx*m+ty);
					//if(t)
						//printf("MERGE %d %d %d %d\n", node[p].second/m+1, node[p].second%m+1, tx+1, ty+1);
					ans-=t;
				}
			}
			p++;
		}
		res[ask[i].second]=ans;
		//printf("GOT %d %d\n", ask[i].second+1, ans);
	}
	rep(i,0,t) printf("%d ", res[i]);
	
	return 0;
}


#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
#define FOR(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
int n,x,t1,t2;
string a1,a2,a3;
vector<int>ve[25];
vector<string>ans[25];
string nam[25];
bool vis[25];
void solve(int x) {
	if (vis[x]) return;
	vis[x] = 1;
	if (ve[x].size() < t1) ans[x].push_back(a1);
	else if (ve[x].size() < t2) ans[x].push_back(a2);
	else ans[x].push_back(a3);
	FOR(i,0,ve[x].size()-1) solve(ve[x][i]);
}
int main() {
	while(cin>>n) {
		if(n == 0) break;
		FOR(i,1,n) ve[i].clear(), ans[i].clear();
		FOR(i,1,n) while(cin>>x && x) ve[i].push_back(x);
		while (cin>>x && x) {
			cin>>t1>>t2>>a1>>a2>>a3;
			memset(vis,0,sizeof(vis));
			solve(x);
			FOR(i,1,n) if (!vis[i]) ans[i].push_back(a1);
		}
		FOR(i,1,n) cin>>nam[i];
		FOR(i,1,n) {
			cout<<nam[i]<<": ";
			FOR(j,0,ans[i].size()-1) cout<<ans[i][j]<<' ';
			cout<<endl;
		}
	}
	return 0;
}

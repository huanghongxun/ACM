#include <cstdio>
#include <map>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
map<int, int> mp[5005];
void pre() {
	mp[0][0]=1; mp[1][1]=2;
	mp[2][0]=3; mp[3][1]=4;
	FOR(i,2,5000) mp[i][i]=mp[i-2][i-2]+4;
	FOR(i,4,5000) mp[i][i-2]=mp[i-2][i-4]+4;
}
int main() {
	pre();
	int n, x, y;
	scanf("%d", &n);
	FOR(i,1,n) {
		scanf("%d%d", &x, &y);
		if(!mp[x][y]) puts("No Number");
		else printf("%d\n", mp[x][y] - 1);
	}
	return 0;
}

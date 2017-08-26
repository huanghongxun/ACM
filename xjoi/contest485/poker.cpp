#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define rep(i,j,k) for(i=j;i<k;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
using namespace std;
typedef long long ll;
ll read() {
	ll s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}

#define N 100005
ll lor[N], ror[N], a[N];

int main() {
	ll i, ans = 0, n, x;
	n=read();x=read();
	FOR(i,1,n) a[i]=read();
	lor[0]=ror[n+1]=0;
	FOR(i,1,n) lor[i]=lor[i-1]|a[i];
	FORD(i,n,1) ror[i]=ror[i+1]|a[i];
	FOR(i,1,n) ans=max(ans,lor[i-1]|ror[i+1]|(a[i]*x));
	printf("%lld", ans);
	return 0;
}

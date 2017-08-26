#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 105
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define rep(i,j,k) for(i=j;i<k;i++)
#define _max(i,j) ((i)>(j)?(i):(j))

int n, ma, i, j;
int up[MAXN], down[MAXN], line[MAXN];

int main()
{
	cin>>n;
	rep(i,0,n) cin>>line[i], up[i] = down[i] = 1;
	up[0] = 0;
	down[n] = 0;
	rep(i,0,n)
		rep(j,0,i)
			if(line[i]>line[j])
				up[i]=_max(up[i],up[j]+1);
	FORD(i,n-1,0)
		FORD(j,n-1,i+1)
			if(line[i]>line[j])
				down[i]=_max(down[i],down[j]+1);
	int ma = 0;
	rep(i,0,n) {
		if(up[i]+down[i]-1>ma) {
			ma=up[i]+down[i]-1;
		}
	}
	cout<<n-ma<<endl;
	return 0;
}
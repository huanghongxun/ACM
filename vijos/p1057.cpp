#include <iostream>
#include <memory.h>
#define N 1001
using namespace std;

long a[N][N];
long f[N][N];
long i, j, n, m;

inline long min(long a, long b) {
	return a<b?a:b;
}

inline long min(long a, long b, long c) {
	return min(min(a,b),c);
}

int main() {
	long max = 0;
	memset(f,0,sizeof(f));
	memset(a,0,sizeof(a));
	cin>>n>>m;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			cin>>a[i][j];
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(a[i][j] == 1)
				f[i][j] = min(f[i-1][j], f[i][j-1], f[i-1][j-1]) + 1;
	
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(max < f[i][j])
				max = f[i][j];
	cout<<max;

	return 0;
}
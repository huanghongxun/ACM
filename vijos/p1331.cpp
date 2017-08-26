#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

long a[2501][3];
long f[2501];
char c[2501], str[100];
long n,d,i,j;

int main()
{
	scanf("%d %d\n", &n, &d);
	for(i = 1; i <= n; i++)
	{
		scanf("%s", str);
		c[i] = str[0];
		if(c[i] == 'H') a[i][1]++;
		if(c[i] == 'J') a[i][2]++;
		a[i+1][1] = a[i][1];
		a[i+1][2] = a[i][2];
	}
	for(i = 1; i <= n; i++)
		f[i] = 10000000;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= i; j++)
			if ((trunc(abs(a[i][1]-a[j-1][1]-a[i][2]+a[j-1][2]))<=d)||((c[i]==c[j])&&((a[i][1]==a[j][1])||(a[i][2]==a[j][2]))))
				f[i] = min(f[i], f[j - 1] + 1);
	printf("%d", f[n]);
	return 0;
}
#include <cstdio>
#include <cstring>
#include <iostream>
#define N 45
#define K 10
using namespace std;

typedef long long ull;
ull a[N];
ull f[N][K];
ull n, k;

ull compute(int from, int to) {
	ull re = 0;
	for(int i = from; i <= to; i++) {
		re *= 10;
		re += a[i];
	}
	return re;
}

int main() {

	scanf("%d%d", &n, &k);
	char chars[100];
	gets(chars);
	gets(chars);
	for(int i = 0; i < strlen(chars); i++) {
		a[i] = chars[i] - '0';
	}
	memset(f,-1,sizeof(f));
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= k+1; j++) {
			for(int k = 0; k < i; k++)
				if(j-1>=0)
				{
					ull temp = f[k][j-1]*compute(k,i-1);
					if(temp > f[i][j])
						f[i][j] = temp;
					//printf("f[%d,%d]=max(...,f[%d,%d]=%lld*compute(k=%d,i-1=%d)=%lld=%lld)=%lld\n",i,j,k,j-1,f[k][j-1],k,i-1,compute(k,i-1),temp,f[i][j]);
				}
			//printf("f[%d,%d]=%d\n",i,j,f[i][j]);
		}
	printf("%lld", f[n][k+1]);

	return 0;
}
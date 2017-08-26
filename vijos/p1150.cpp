#define maxn 1001
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define GetW(a,b) ( W[N]-(W[(b)]-W[(a)-1]) )
#define GetT(a,b) ( abs(T[(a)]-T[(b)]) )

long long W[maxn],T[maxn],N,S,D[maxn][maxn];

int main(void){
	long i,k,j;
	scanf("%ld%ld",&N,&S);
	W[0] = 0;
	for (i=1;i<=N;i++){
		scanf("%ld%ld",&T[i],&W[i]);
		W[i]+=W[i-1];
	}
	memset(D,0x7f,sizeof(D));
	D[0][0]=0;
	for (k=1;k<N;k++)
		for (i=1;i<N;i++) {
			if ((j=i+k)>N) break;
			D[i][j]=min(D[i][j-1]+GetW(i,j-1)*GetT(j-1,j),
			D[j-1][i]+GetW(i,j-1)*GetT(i,j) );
			D[j][i]=min(D[j][i-1]+GetW(i+1,j)*GetT(i,i+1),
			D[i-1][j]+GetW(i+1,j)*GetT(i,j) );
		}
	printf("%ld\n",min(D[1][N],D[N][1]));
	return 0;
}
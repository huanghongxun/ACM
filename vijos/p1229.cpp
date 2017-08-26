#include <cstdio>
#include <cmath>
#define sqr(i) ((i)*(i))
int main() {
	int k;
	scanf("%d", &k);
	//for(int i=1,n=0;i<=50000;i++) {
	int i=36,n=0;
		for(int j=1;j<=floor(sqrt(i));j++)
			if(i%j==0) n++;
		n*=2;
		if(sqr((int)floor(sqrt(i)))==i) n--;
		printf("%d ", n);
		if(n==k) {
			printf("%d", i);
			goto end;
		}
	//}
	printf("NO SOLUTION");
end:
	return 0;
}
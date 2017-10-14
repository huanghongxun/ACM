#include <cstdio>
#define rep(i,j,k) for(i=j;i<k;++i)

int main() {
	int n, i, j, k;
	while (scanf("%d", &n) && n) {
		rep(i,1,n) {
			k = 0;
			rep(j,1,n) (k += i) %= j;
			if (k == 11) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}

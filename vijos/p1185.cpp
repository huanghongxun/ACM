#include <cstdio>
#include <cmath>
#include <cstdio>
long i, n;
long double m;
int main() {
	scanf("%llf", &m);
	while(m != 0) {
		if(abs(m) > 32767 * 32768 / 2) {
			printf("0\n");
		} else if(abs(m) == 1) {
			printf("1\n");
		} else {
			n = floor(abs(m));
			i = 2;
			while(i*(i+1)/2<n || (i*(i+1)/2%2==1) ^ (n%2==1))
				i++;
			printf("%ld\n", i);
		}
		scanf("%llf", &m);
	}
	return 0;
}
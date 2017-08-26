#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 2000

char *mul(char *a, char *b, int alen, int blen)
{
	char c[MAXN]; int tmp, k;
	memset(c, 0, sizeof(c));
	for(int i = 1; i < blen; i++) {
		for(int j = 1; j < alen; j++) {
			tmp = a[j] * b[i];
			k = i;
			while(tmp>0) {
				c[k++] += tmp%10;
				tmp /= 10;
			}
		}
	}
	
}

int main()
{
	return 0;
}
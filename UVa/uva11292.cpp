#include <cstdio>
#include <algorithm>
using namespace std;

#define N 20005

int a[N], b[N];

int main() {
	
	int n, m, i;

	while(scanf("%d%d", &n, &m) != EOF && n && m) {
		for(i=0;i<n;i++) scanf("%d", &a[i]);
		for(i=0;i<m;i++) scanf("%d", &b[i]);
		sort(a, a+n);
		sort(b, b+n);
		int cur = 0, cost = 0;
		for(i=0;i<m;i++) {
			if(b[i]>=a[cur]) {
				cost+=b[i];
				cur++;
				if(cur==n) break;
			}
		}

		if(cur<n) printf("Loowater is doomed!\n");
		else printf("%d\n", cost);
	}

	return 0;
}
#include <cstdio>
#include <cstring>
#define N 50005

int n;
int cA[N], cB[N];

inline int lowbit(int &t) {
	return t & (-t);
}

inline void add(int *c, int pos, int add) {
	while(pos <= n) {
		c[pos] += add;
		pos += lowbit(pos);
	}
}

inline int sum(int *c, int end) {
	int s = 0;
	while(end > 0) {
		s += c[end];
		end -= lowbit(end);
	}
	return s;
}

int main() {
	int m, k, l, r;

	memset(cA, 0, sizeof(cA));
	memset(cB, 0, sizeof(cB));

	scanf("%d%d", &n, &m);
	while(m--) {
		scanf("%d%d%d", &k, &l, &r);
		if(k == 1) {
			add(cA, l, 1);
			add(cB, r, 1);
		} else {
			printf("%d\n", sum(cA, r-1) - sum(cB, l-1));
		}
	}

	return 0;
}
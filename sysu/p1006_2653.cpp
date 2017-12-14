#include <cstdio>
#include <algorithm>
using namespace std;
int mp[105][10005], line[105];
int main() {
	int n, m, q, i, j, op, x, y;
	scanf("%d%d%d", &n, &m, &q);

	for (i = 1; i <= n; ++ i) line[i] = i;

	while (q --) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d", &op, &x, &y);
			mp[line[x]][y] = op;
		} else if (op == 2) {
			scanf("%d%d", &x, &y);
			swap(line[x], line[y]);
		}
	}

	for (i = 1; i <= n; ++ i) {
		for (j = 1; j <= m; ++ j)
			switch (mp[line[i]][j]) {
				case 0: putchar('.'); break;
				case 1: putchar('w'); break;
				case 2: putchar('b'); break;
			}
		putchar('\n');
	}

	return 0;
}
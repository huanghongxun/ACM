#include <cstdio>

int main() {
	int n, a, i, mx = 0, sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++ i) {
		scanf("%d", &a);
		sum += a;
		if (a > mx)
			mx = a;
	}
	if (mx > 2)
		sum = sum - mx + 2;
	printf("%d\n", sum);

	return 0;
}
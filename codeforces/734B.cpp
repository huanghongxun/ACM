#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int k2, k3, k5, k6, k;
	scanf("%d%d%d%d", &k2, &k3, &k5, &k6);
	k = min(min(k2, k5), k6);
	k2 -= k; k5 -= k; k6 -= k;
	printf("%d", 256 * k + min(k2, k3) * 32);
	return 0;
}
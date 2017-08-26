#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t, n, m, ans;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		ans = 0; n--; m--;
		if (n > m) swap(n, m);
		if (m) {
			ans = n + 1; m -= n; if (!n) m--;
			if (m){
				if ((m - 1) & 1) ans += (m - 1) / 2 + 2;
				else ans += (m - 1) / 2 + 1;
			}
		}
		printf("%d\n",ans);
	}
}
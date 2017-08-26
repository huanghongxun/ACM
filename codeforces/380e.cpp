#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;i++)
int main(){
	const int N = 300001;
	static int a[N], p[N], l[N], r[N];
	int i, n, k, j; double ans = 0;
	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", a + i), p[i] = i, l[i] = i - 1, r[i] = i + 1;
	sort(p + 1, p + n + 1, [](int x, int y) { return a[x] < a[y]; });
	FOR(i,1,n) {
		int k = p[i], x = k, y = k;
		double L = 0, R = 0, z = 1;
		FOR(j,1,55) {
			if (x > 0)  L += (x - l[x]) * z, x = l[x];
			if (y <= n) R += (r[y] - y) * z, y = r[y];
			z /= 2;
		}
		ans += a[k] * L * R / (n * n * 2);
		l[r[k]] = l[k]; r[l[k]] = r[k];
	}
	printf("%.6lf\n",ans);
    return 0;
}
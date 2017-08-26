#include <cstdio>
#define rep(i,j,k) for(i=j;i<k;++i)
const int N = 200005;
int bit[N][32], bitsum[32], b2[N], c2[N], b[N], c[N], d[N], a[N];
int main() {
	int n, i, j; long long sd = 0;
	scanf("%d", &n);
	rep(i,0,n) scanf("%d", &b[i]);
	rep(i,0,n) scanf("%d", &c[i]);
	rep(i,0,n) d[i] = b[i] + c[i], sd += d[i];
	sd /= 2 * n;
	rep(i,0,n) {
		a[i] = (d[i] - sd) / n;
		if (a[i] < 0) return puts("-1");
	}
	rep(i,0,n) rep(j,0,31) bit[i][j] = (a[i] & (1 << j)) ? 1 : 0;
	rep(i,0,n) rep(j,0,31) bitsum[j] += bit[i][j];
	rep(i,0,n) rep(j,0,31) {
		b2[i] += (bit[i][j] ? bitsum[j] : 0) << j;
		c2[i] += (bit[i][j] ? n : bitsum[j]) << j;
	}
	rep(i,0,n) if (b2[i] != b[i] || c2[i] != c[i])
		return puts("-1");
	rep(i,0,n) printf("%d ", a[i]);
	return 0;
}
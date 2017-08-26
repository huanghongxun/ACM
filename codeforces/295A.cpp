#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 100005, M = N;
typedef long long ll;
int l[M], r[M], p[M], n;
ll a[N], c[N], d[M];
void add(int i, ll x) {
	for (; i <= n; i += i & -i) c[i] += x;
}
ll sum(int i) {
	ll s = 0;
	for (; i; i -= i & -i) s += c[i];
	return s;
}
int main() {
	int m, k, i, x, y, q = 0;
	scanf("%d%d%d", &n, &m, &k);
	FOR(i,1,n) scanf("%I64d", a + i), add(i, a[i]), add(i + 1, -a[i]);
	FOR(i,1,m) scanf("%d%d%d", l + i, r + i, d + i);
	FOR(i,1,k) {
		scanf("%d%d", &x, &y);
		++p[x]; --p[y + 1];
	}
	FOR(i,1,m) {
		q += p[i]; add(l[i], d[i] * q); add(r[i] + 1, -d[i] * q);
	}
	FOR(i,1,n) printf("%I64d ", sum(i));
	return 0;
}
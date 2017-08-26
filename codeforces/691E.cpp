#include <cstdio>
#include <cstring>
#define rep(i,k) for(i=0;i<k;++i)
using namespace std;
typedef long long ll;
const int N = 101;
const int mod = 1e9 + 7;


inline void inc(int& a, int b) { a += b; if (a >= mod) a -= mod; }
inline int mul(int a, int b) { return (int)(1ll * a * b % mod); }

int countBit(ll x) {
	int ans = 0;
	for (; x; x &= x - 1) ++ans;
	return ans;
}

struct Matrix { // must be n * n, to support power operation.
	int a[N][N];
	int n;

	Matrix() { memset(a, 0, sizeof a); n = 0; }

	int *operator[](int i) { return a[i]; }

	Matrix &operator*= (const Matrix &b) {
		static int c[N][N];
		int i, j, k;
		rep(i,n) rep(j,n) {
			c[i][j] = 0;
			rep(k,n) inc(c[i][j], mul(a[i][k], b.a[k][j]));
		}
		memcpy(a, c, sizeof c);
		return *this;
	}

	Matrix &operator^= (ll b) {
		static Matrix c, t;
		int i, j;
		t = *this; c.n = n;
		rep(i,n) rep(j,n) c.a[i][j] = i == j ? 1 : 0; // initial unit matrix
		for (; b; t *= t, b /= 2) // quick power
			if (b & 1) c *= t;
		rep(i,n) rep(j,n) a[i][j] = c.a[i][j]; 
		return *this;
	}
};

int main() {
	int n, i, j, ans = 0;
	ll k, a[N];
	scanf("%d%I64d", &n, &k);
	rep(i,n) scanf("%I64d", a + i);
	Matrix x;
	rep(i,n) {
		rep(j,n) x[i][j] = countBit(a[i] ^ a[j]) % 3 == 0;
		x[i][n] = 1;
	}

	x.n = n + 1;
	x ^= k;

	rep(i, n + 1) inc(ans, x[i][n]);
	printf("%d", ans);
	return 0;
}
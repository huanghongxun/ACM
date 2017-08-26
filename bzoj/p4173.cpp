#include <cstdio>
#define ll long long
#define mod 998244353
using namespace std;
ll n, m;
ll phi(ll n) {
	ll tmp = n;
	for (ll i = 2; i * i <= n; i ++)
		if (n % i == 0) {
			tmp /= i; tmp *= i - 1;
			while(n % i == 0) n /= i;
		}
	if (n != 1) tmp /= n, tmp *= n - 1;
	return tmp % mod;
}
int main() {
	scanf("%lld%lld", &n, &m);
	printf("%lld", phi(n)*phi(m)%mod*(n%mod)%mod*(m%mod)%mod);
	return 0;
}
#include <cstdio>

typedef long long ll;
ll n, m, k, x;
ll quick(ll i, ll j)
{
	ll ans = 1;
	while(j != 0) {
		if(j & 1 == 1)
			ans = (ans * i) % n;
		i = (i * i) % n;
		j /= 2;
	}
	return ans;
}



int main()
{
	scanf("%lld%lld%lld%lld", &n, &m, &k, &x);
	printf("%lld", (x + quick(10, k) * m) % n);
	return 0;
}
#include <cstdio>

typedef long long ll;
ll n,m,k,x;

ll quick_exp(ll x) {
	if(!x) return 1;
	if(x==1) return 10%n;
	if(x&1)
		return ((quick_exp(x/2)*quick_exp(x/2))%n)%10%n;
	else
		return ((quick_exp(x/2)*quick_exp(x/2))%n)%n;
}

int main() {
	scanf("%d%d%d%d",&n,&m,&k,&x);
	printf("%lld",(quick_exp(k)*m%n+x)%n);

	return 0;
}
// UVALive 6084
#include <cstdio>
typedef long long ll;

int main() {
    ll l, p, v, ans, tmp;
    int kase = 0;
    while (scanf("%lld%lld%lld", &l, &p, &v) == 3 && (l || p || v)) {
        tmp = v % p;
        if (tmp >= l) tmp = l;

        printf("Case %d: %lld\n", ++kase, v / p * l + tmp);
    }
    
    return 0;
}
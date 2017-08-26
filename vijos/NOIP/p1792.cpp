#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define N 10001
#define M 30005

const int inf = 0x7ffffff;
typedef long long ll;

ll s[N], pri[M];
long n, m1, m2, i, j, d, b, res, ma = inf;

void get_primes(int number, int mul) {
	memset(pri, 0, sizeof(pri));
	for(int p = 2; p <= number; p++) {
		while(number % p == 0) {
			pri[p] ++;
			number /= p;
		}
		pri[p] *= mul;
	}
}

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	cin>>n>>m1>>m2;
	get_primes(m1, m2);
	for(i = 1; i <= n; i++) {
		cin>>s[i];
		res = 0;
		for(j = 1; j <= m1; j++)
		if(pri[j] != 0)
		{
			d = 0;
			while(s[i] % j == 0) {
				s[i] /= j;
				d++;
			}
			if(d == 0) {
				res = inf;
				break;
			}
			if(pri[j] % d == 0)
				b = pri[j] / d;
			else
				b = pri[j] / d + 1;
			if(b > res)
				res = b;
		}
		if(res < ma) ma = res;
	}

	if(ma == inf) cout<<-1;
	else cout<<ma;

	return 0;
}
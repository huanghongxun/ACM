#include <iostream>
#include <cstring>
#define N 100005
using namespace std;

typedef long long ll;
ll a[N];
ll cnt[2*N];
ll n, k, i, ki, sum, ans;

int main() {
	memset(cnt, 0, sizeof(cnt));
	cin>>n>>k;
	for(i = 0; i < n; i++) {
		cin>>a[i];
		if(a[i] > k) a[i] = 1;
		else if(a[i] == k) { a[i] = 0; ki = i; }
		else a[i] = -1;
	}
	ans = 1; sum = 0;
	for(i = ki - 1; i >= 0; i--) {
		sum += a[i];
		cnt[sum + N]++;
		if(sum == 0) ans++;
	}
	sum = 0;
	for(i = ki + 1; i < n; i++) {
		sum += a[i];
		ans += cnt[-sum + N];
		if(sum == 0) ans++;
	}
	cout<<ans;

	return 0;
}
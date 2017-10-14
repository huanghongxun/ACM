#include <queue>
#include <set>
#include <cstdio>
using namespace std;
typedef long long ll;
int main() {
	ll i = 0;
	priority_queue<ll, vector<ll>, greater<ll> > x;
	set<ll> s;
	x.push(1);
	while (true) {
		++i;
		ll u = x.top();
		x.pop();

		if (i == 1500) {
			printf("The 1500'th ugly number is %d.\n", (int) u);
			break;
		}
		if (s.find(u * 2) == s.end()) {
			x.push(u * 2);
			s.insert(u * 2);
		}
		if (s.find(u * 3) == s.end()) {
			x.push(u * 3);
			s.insert(u * 3);
		}
		if (s.find(u * 5) == s.end()) {
			x.push(u * 5);
			s.insert(u * 5);
		}
	}

	return 0;
}
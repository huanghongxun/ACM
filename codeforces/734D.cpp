#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > v, h, dl, dr;
int main() {
	int n, x, y, i, a, b; char c[3];
	vector<pair<int, int> >::iterator it;
	scanf("%d%d%d", &n, &x, &y);
	for (i = 0; i < n; ++i) {
		scanf("%s%d%d", c, &a, &b);
		bool rook = c[0] == 'R' || c[0] == 'Q';
		bool shop = c[0] == 'B' || c[0] == 'Q';
		if (a == x) v.push_back(make_pair(b, rook));
		if (b == y) h.push_back(make_pair(a, rook));
		if (a + b == x + y) dl.push_back(make_pair(a, shop));
		if (a - b == x - y) dr.push_back(make_pair(a, shop));
	}
	#define check(p,v) \
		v.push_back(p);\
		sort(v.begin(), v.end());\
		it = lower_bound(v.begin(), v.end(), p);\
		if (it != v.end() - 1 && (it + 1)->second) return puts("YES"), 0;\
		if (it != v.begin() && (it - 1)->second) return puts("YES"), 0;
	check(make_pair(y, 0), v)
	check(make_pair(x, 0), h)
	check(make_pair(x, 0), dl)
	check(make_pair(x, 0), dr)
	
	return puts("NO"), 0;
}
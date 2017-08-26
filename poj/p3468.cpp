#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N 100005
typedef long long ll;

struct SegmentTreeNode {
	ll add, sum, l, r;
} tree[6*N];
ll a[N];

void updateNode(ll t) {
	tree[t].sum = tree[t * 2].sum + tree[t * 2 + 1].sum;
}

void build(ll t, ll l, ll r) {
	tree[t].l = l;
	tree[t].r = r;
	if(l == r) {
		tree[t].sum = a[l];
		return;
	}
	ll mid = (l + r) / 2;
	build(t * 2, l, mid);
	build(t * 2 + 1, mid + 1, r);
	updateNode(t);
}

void pushDown(ll t) {
	if(tree[t].add != 0) {
		tree[t * 2].add += tree[t].add;
		tree[t * 2 + 1].add += tree[t].add;
		tree[t].sum += (tree[t].r - tree[t].l + 1) * tree[t].add;
		tree[t].add = 0;
	}
}

ll pos, chg;
void update(ll t, ll l, ll r) {
	if(l == tree[t].l && tree[t].r == r) {
		tree[t].add += chg;
		return;
	}
	
	tree[t].sum += (r - l + 1) * chg;
	
	ll mid = (tree[t].l + tree[t].r) / 2;
	if(r <= mid) update(t * 2, l, r);
	else if(mid < l) update(t * 2 + 1, l, r);
	else {
		update(t * 2, l, mid);
		update(t * 2 + 1, mid + 1, r);
	}
}

ll query(ll t, ll l, ll r) {
	pushDown(t);
	
	if(l == tree[t].l && tree[t].r == r) {
		return tree[t].sum;
	}
	ll mid = (tree[t].l + tree[t].r) / 2;
	ll res = 0;
	if(r <= mid) res += query(t * 2, l, r);
	else if(mid < l) res += query(t * 2 + 1, l, r);
	else {
		res += query(t * 2, l, mid);
		res += query(t * 2 + 1, mid + 1, r);
	}
	return res;
}

int main() {
	ll n, m, x, y, z;
	char t;
	scanf("%lld%lld", &n, &m);
	for(z = 1; z <= n; z++) scanf("%lld", &a[z]);
	build(1, 1, n);
	
	while(m--) {
		getchar();
		scanf("%c%lld%lld", &t, &x, &y);
		if(t == 'Q') {
			printf("%lld\n", query(1, x, y));
		} else {
			scanf("%lld", &z);
			chg = z;
			update(1, x, y);
		}
	}
	
	return 0;
}
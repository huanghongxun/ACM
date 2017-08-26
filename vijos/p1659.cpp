#include <cstdio>
#define N 100005
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;

ll a[N];
struct SegmentTreeNode {
	ll max, l, r;
	ll add;
} tree[3*N];

void updateNode(int t) {
	tree[t].max = max(tree[t * 2].max + tree[t * 2].add, tree[t * 2 + 1].max + tree[t * 2 + 1].add);
}

void build(ll t, ll l, ll r) {
	tree[t].l = l;
	tree[t].r = r;
	tree[t].add = 0;
	if(l == r) {
		tree[t].max = a[l];
		return;
	}
	ll mid = (l + r) / 2;
	build(t * 2, l, mid);
	build(t * 2 + 1, mid + 1, r);
	updateNode(t);
}

void update(ll t, ll l, ll r, ll add) {
	if(l == tree[t].l && tree[t].r == r) {
		tree[t].add += add;
		return;
	}
	ll mid = (tree[t].l + tree[t].r) / 2;
	if(r <= mid) update(t * 2, l, r, add);
	else if(mid < l) update(t * 2 + 1, l, r, add);
	else {
		update(t * 2, l, mid, add);
		update(t * 2 + 1, mid + 1, r, add);
	}

	updateNode(t);
}

ll query(ll t, ll l, ll r) {
	if(l == tree[t].l && tree[t].r == r) {
		return tree[t].max + tree[t].add;
	}
	ll mid = (tree[t].l + tree[t].r) / 2;
	if(r <= mid) return query(t * 2, l, r) + tree[t].add;
	else if(mid < l) return query(t * 2 + 1, l, r) + tree[t].add;
	else {
		return max(query(t * 2, l, mid), query(t * 2 + 1, mid + 1, r)) + tree[t].add;
	}
}

int main() {
	ll n, m, i, t, x, y;
	scanf("%lld", &n);
	for(i = 1; i <= n; i++) scanf("%lld", &a[i]);
	build(1, 1, n);
	scanf("%lld", &m);
	while(m--) {
		scanf("%lld%lld%lld", &t, &x, &y);
		if(t == 1) {
			scanf("%lld", &i);
			update(1, x, y, i);
		} else {
			printf("%lld\n", query(1, x, y));
		}
	}

	return 0;
}
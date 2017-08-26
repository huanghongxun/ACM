#include <cstdio>
#include <algorithm>
using namespace std;
int random() {
	static int base = 123456789;
	return base += (base << 2) + 1;
}

class PersistantTreap {
private:
	struct Node {
		int v, delta, rev, size, minx, w;
		Node *l, *r;
		
		void up() {
			minx = v;
			size = 1;
			if(l) size += l->size, minx = min(minx, l->minx);
			if(r) size += r->size, minx = min(minx, r->minx);
		}
		
		void down() {
			if(delta) {
				if(l) l->delta += delta, l->v += delta, l->minx += delta;
				if(r) r->delta += delta, r->v += delta, r->minx += delta;
				delta = 0;
			}
			if(rev) {
				swap(l, r);
				if(l) l->rev ^= 1;
				if(r) r->rev ^= 1;
				rev = 0;
			}
		}
	} *root;
	
	struct Pool {
		Node *list;
		
		Pool() { list = NULL; }
		
		void new_node(Node *&o, int val) {
			if(list == NULL) {
				Node *tt = new Node[100];
				for(int i = 0; i < 100; i++) {
					tt[i].w = random();
					tt[i].r = list;
					list = tt + i;
				}
			}
			o = list;
			list = o->r;
			o->l = o->r = NULL;
			o->v = o->minx = val;
			o->size = 1;
			o->delta = o->rev = 0;
		}
		
		void collectGarbage(Node *a) { if(a) a->r = list; list = a; }
	} pool;
	
	static int size(Node *a) { return a ? a->size : 0; }
	
	static void split(Node *o, Node *&p, Node *&q, int num) {
		if(num == 0) {
			p = NULL; q = o;
		} else if(num == size(o)) {
			p = o; q = NULL;
		} else {
			o->down();
			if(num <= size(o->l)) {
				q = o;
				split(o->l, p, q->l, num);
				q->up();
			} else {
				p = o;
				split(o->r, p->r, q, num-size(o->l)-1);
				p->up();
			}
		}
	}
	
	static void merge(Node *&o, Node *p, Node *q) {
		if(!p || !q) {
			o = p ? p : q;
		} else {
			if(p->w > q->w) {
				p->down();
				o = p;
				merge(o->r, p->r, q);
			} else {
				q->down();
				o = q;
				merge(o->l, p, q->l);
			}
			o->up();
		}
	}
	
	void insert(Node *&o, int pos, int val) {
		if(o == NULL) {
			pool.new_node(o, val);
		} else {
			o->down();
			if (size(o->l) >= pos) {
				insert(o->l, pos, val);
				if(o->l->w > o->w) {
					Node *t = o;
					o = o->l;
					o->down();
					t->l = o->r;
					o->r = t;
					o->r->up();
				}
			} else {
				insert(o->r, pos - size(o->l) - 1, val);
				if(o->r->w > o->w) {
					Node *t = o;
					o = o->r;
					o->down();
					t->r = o->l;
					o->l = t;
					o->l->up();
				}
			}
			o->up();
		}
	}

	int *temp;

	void build(int l, int r, Node *&a) {
		if (l>r) return;
		int mid = l + r >> 1;
		pool.new_node(a, temp[mid]);
		if (l == r) return;
		build(l, mid - 1, a->l);
		build(mid + 1, r, a->r);
		a->up();
	}
public:

	void insert(int pos, int val) {
		insert(root, pos, val);
	}

	// 插入区间
	void insertRange(int pos, int *arr, int n) {
		temp = arr;
		Node *a, *b, *c;
		build(1, n, b);
		split(root, a, c, pos);
		merge(a, a, b);
		merge(root, a, c);
	}
	
	void remove(int pos) {
		Node *a, *b, *c;
		split(root, a, b, pos - 1);
		split(b, b, c, 1);
		merge(root, a, c);
		pool.collectGarbage(b);
	}
	
	void add(int l, int r, int val) {
		Node *a, *b, *c;
		split(root, a, b, l-1);
		split(b,b,c,r-l+1);
		b->v += val;
		b->minx += val;
		b->delta += val;
		merge(a,a,b);
		merge(root,a,c);
	}
	
	int query(int l, int r) {
		Node *a, *b, *c;
		split(root, a, b, l - 1);
		split(b, b, c, r - l + 1);
		int ret = b->minx;
		merge(a, a, b);
		merge(root, a, c);
		return ret;
	}
	
	void reverse(int l, int r) {
		Node *a, *b, *c;
		split(root, a, b, l-1);
		split(b, b, c, r-l+1);
		b->rev ^= 1;
		merge(a, a, b);
		merge(root, a, c);
	}
	
	void revolve(int l, int m, int r) {
		Node *a, *b, *c, *d;
		split(root, a, b, l-1);
		split(b,b,c,m-l+1);
		split(c,c,d,r-m);
		merge(a,a,c);
		merge(a,a,b);
		merge(root,a,d);
	}
} pt;

int temp[100005];

int main() {
	int n, d, nq, a, b;
	char s[10];
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", temp+i);
	}
	pt.insertRange(0, temp, n);
	scanf("%d", &nq);
	while(nq--) {
		scanf("%s", s);
		if(s[0] == 'A') {
			scanf("%d%d%d", &a, &b, &d);
			pt.add(a, b, d);
		} else if(s[0] == 'I') {
			scanf("%d%d", &a, &d);
			pt.insert(a, d);
		} else if(s[0] == 'D') {
			scanf("%d", &a);
			pt.remove(a);
		} else if(s[0] == 'M') {
			scanf("%d%d", &a, &b);
			printf("%d\n", pt.query(a, b));
		} else if(s[3] == 'E') {
			scanf("%d%d", &a, &b);
			pt.reverse(a, b);
		} else if(s[3] == 'O') {
			scanf("%d%d%d", &a, &b, &d);
			int t = b-a+1;
			d = (d%t+t)%t;
			if(d) pt.revolve(a,b-d,b);
		}
	}
	return 0;
}

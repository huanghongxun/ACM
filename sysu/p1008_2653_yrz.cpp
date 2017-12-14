#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn=int(1e5)+100;

struct node
{
	LL Lv, Rv;
	int maxv[5];
	bool turn[2];

	node()
	{
		Lv=Rv=0;
		turn[0]=turn[1]=false;
		for (int i=0; i<5; ++i)
			maxv[i]=1;
	}
};

struct data
{
	int x, y, v;
};

int n, G;
node tree[maxn*4];
LL lazy[maxn*4];
data dat;

void down(int cur)
{
	lazy[cur<<1]+=lazy[cur];
	lazy[cur<<1 | 1]+=lazy[cur];
	tree[cur<<1].Lv+=lazy[cur];
	tree[cur<<1].Rv+=lazy[cur];
	tree[cur<<1 | 1].Lv+=lazy[cur];
	tree[cur<<1 | 1].Rv+=lazy[cur];
	lazy[cur]=0;
}
void update(int cur, int L, int R)
{
	int mid=(L+R)>>1;
	int sgn=0;
	if (tree[cur<<1].Rv<tree[cur<<1 | 1].Lv) sgn=-1;
	if (tree[cur<<1].Rv>tree[cur<<1 | 1].Lv) sgn=1;

	tree[cur].Lv=tree[cur<<1].Lv;
	tree[cur].Rv=tree[cur<<1 | 1].Rv;
	tree[cur].maxv[2]=max(tree[cur<<1].maxv[2], tree[cur<<1 | 1].maxv[2]);
	/*
	if (tree[cur<<1].Rv!=tree[cur<<1 | 1].Lv)
		tree[cur].maxv[2]=max(tree[cur].maxv[2], tree[cur<<1].maxv[1]+tree[cur<<1 | 1].maxv[0]);*/

	tree[cur].maxv[0]=tree[cur<<1].maxv[0];
	if (tree[cur<<1].maxv[0]==(mid-L+1) && sgn==1)
		tree[cur].maxv[0]=tree[cur<<1].maxv[0]+tree[cur<<1 | 1].maxv[0];

	tree[cur].maxv[1]=tree[cur<<1 | 1].maxv[1];
	if (tree[cur<<1 | 1].maxv[1]==(R-mid) && sgn==-1)
		tree[cur].maxv[1]=tree[cur<<1 | 1].maxv[1]+tree[cur<<1].maxv[1];

	tree[cur].maxv[2]=max(tree[cur].maxv[2], tree[cur].maxv[0]);
	tree[cur].maxv[2]=max(tree[cur].maxv[2], tree[cur].maxv[1]);

	if (sgn==1)
		tree[cur].maxv[2]=max(tree[cur].maxv[2], tree[cur<<1].maxv[4]+tree[cur<<1 | 1].maxv[0]);
	if (sgn==-1)
		tree[cur].maxv[2]=max(tree[cur].maxv[2], tree[cur<<1 | 1].maxv[3]+tree[cur<<1].maxv[1]);

	tree[cur].maxv[3]=tree[cur<<1].maxv[3];
	tree[cur].turn[0]=tree[cur<<1].turn[0];
	if (tree[cur].maxv[3]==(mid-L+1))
	{
		if (tree[cur].turn[0] && sgn==1)
			tree[cur].maxv[3]+=tree[cur<<1 | 1].maxv[0];
		if (!tree[cur].turn[0])
		{
			if (sgn==1)
			{
				tree[cur].maxv[3]+=tree[cur<<1 | 1].maxv[0];
				tree[cur].turn[0]=true;
			}
			if (sgn==-1)
			{
				tree[cur].maxv[3]+=tree[cur<<1 | 1].maxv[3];
				tree[cur].turn[0]=tree[cur<<1 | 1].turn[0];
			}
		}
	}

	tree[cur].maxv[4]=tree[cur<<1 | 1].maxv[4];
	tree[cur].turn[1]=tree[cur<<1 | 1].turn[1];
	if (tree[cur].maxv[4]==(R-mid))
	{
		if (tree[cur].turn[1] && sgn==-1)
			tree[cur].maxv[4]+=tree[cur<<1].maxv[1];
		if (!tree[cur].turn[1])
		{
			if (sgn==-1)
			{
				tree[cur].maxv[4]+=tree[cur<<1].maxv[1];
				tree[cur].turn[1]=true;
			}
			if (sgn==1)
			{
				tree[cur].maxv[4]+=tree[cur<<1].maxv[4];
				tree[cur].turn[1]=tree[cur<<1].turn[1];
			}
		}
	}

	tree[cur].maxv[2]=max(tree[cur].maxv[2], tree[cur].maxv[3]);
	tree[cur].maxv[2]=max(tree[cur].maxv[2], tree[cur].maxv[4]);
}
void insert(int cur, int L, int R)
{
	if (dat.x>R || dat.y<L) return;
	if (dat.x<=L && R<=dat.y)
	{
		lazy[cur]+=dat.v;
		tree[cur].Lv+=dat.v;
		tree[cur].Rv+=dat.v;
		return;
	}
	int mid=(L+R)>>1;
	if (lazy[cur]!=0) down(cur);
	insert(cur<<1, L, mid);
	insert(cur<<1 | 1, mid+1, R);
	update(cur, L, R);
}
void read()
{
	scanf("%d%d", &n, &G);
	for (int i=1; i<=n; ++i)
	{
		scanf("%d", &dat.v);
		dat.x=dat.y=i;
		insert(1, 1, n);
	}
}
void solve()
{
	while (G--)
	{
		scanf("%d%d%d", &dat.x, &dat.y, &dat.v);
		insert(1, 1, n);
		printf("%d\n", tree[1].maxv[2]);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	read();
	solve();
	return 0;
}

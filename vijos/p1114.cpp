#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct TreeNode {
	char type;
	TreeNode *l, *r;
} *root;

char FBI[1030];

int n;

string substring(const string &str, int l, int r) {
	return str.substr(l, r-l+1);
}

void create(TreeNode *&root, int l, int r) {
	root = new TreeNode;
	if(r-l+1==1) {
		root->l = root->r = NULL;
		if(FBI[l]=='1') {
			root->type = 'I';
		} else root->type = 'B';
	}
	else {
		int m = (l+r)/2;
		create(root->l, l, m);
		create(root->r, m+1, r);
		if(root->l->type==root->r->type&&root->l->type!='F') {
			root->type = root->l->type;
		} else root->type = 'F';
	}
}

void last_order(TreeNode *r) {
	if(!r) return;
	last_order(r->l);
	last_order(r->r);
	cout<<r->type;
}

int main() {
	cin>>n;
	cin>>FBI + 1;
	n = pow(2, n);
	create(root, 1, n);
	last_order(root);
	return 0;
}
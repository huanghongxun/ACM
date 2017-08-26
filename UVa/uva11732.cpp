#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;

char words[1010];

#define nodesize 4444444

class Trie {
	struct Node {
		char value;
		int size, count;
		Node *l, *r;
	} dict[nodesize], *root;
	LL count;
	int	size;
public:  
	Trie() {
		init();
	}

	void init() {
		memset(dict, 0, sizeof dict);
		size=0; count=0LL; root = newnode(0);
	}

	Node* newnode(char c) {
		dict[size].value = c;
		return &dict[size ++];
	}

	void insert(char* word, int L) {
		Node* now = root->r, *save = root;
		int same = 1;
		for (int i = 0; i <= L; i ++) { 
			if (!now) {
				save->r = newnode(word[i]);
				now = save->r;
				now->count = 1;
				same = 0;
			} else {
				if (i) count += now->count;
				count += now->count ++;
				while (now->l && now->value != word[i])
					now = now->l;
				if (now->value != word[i]) {
					now->l = newnode(word[i]); 
					now = now->l;
					same = 0;
				}
			}
			save = now;
			now = save->r;
		}
		if (same) save->size ++;
		count += save->size;
	}

	LL query() { return count; }
} trie;

int main() {
	int kase = 1, n;
	while (scanf("%d",&n) != EOF) {
		if (!n) break;
		
		trie.init();
		for (int i = 0; i < n; i ++) {
			scanf("%s", words);
			trie.insert(words, strlen(words));
		}
		
		printf("Case %d: %lld\n", kase ++, trie.query());
	}
	return 0;
}


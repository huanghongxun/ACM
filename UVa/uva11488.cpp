#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

char words[50004][204];

#define NODE_SIZE 4000004
#define DICT_SIZE 2

struct Node {
	int deep, value, flag; 
	Node* next[DICT_SIZE];  
} dict[NODE_SIZE];
int ID[256];

class Trie {
private:  
	int max;
	int size;
	Node* root;
public:  
	Trie() {
		makeID(); initial();
	}

	void makeID() {
		ID['0'] = 0;
		ID['1'] = 1;
	}

	void initial() {
		memset(dict, 0, sizeof dict);
		root = NULL; size = 0; root = newnode();
	}

	Node* newnode() {
		return &dict[size++];
	}

	void insert(char* word, int L) {
		Node* now = root;  
		for (int i = 0; i < L; i++) {
			if (!now->next[ID[word[i]]])
				now->next[ID[word[i]]] = newnode();
			now = now->next[ID[word[i]]];
			now->deep = i+1;
			now->value ++;
		}
		now->flag = 1;
	}

	void output() {
		max = 0;
		for (int i = 0; i < size; i++)
			if (max < dict[i].value*dict[i].deep)
				max = dict[i].value*dict[i].deep;
		printf("%d\n",max);
	}
} trie;

int cmp(const void *a, const void *b) {
    return strlen((char*)a) - strlen((char*)b);
}

int main() {
	int T, n;
	while (scanf("%d", &T) != EOF) 
	for (int t = 1; t <= T ; t++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%s", words[i]);
		qsort(words, n, sizeof(words[0]), cmp);
		
		trie.initial();
		for (int i = 0; i < n; i++)
			trie.insert(words[i], strlen(words[i]));
		
		trie.output();
	}
	return 0;
}

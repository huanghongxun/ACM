#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define rep(i,j,k) for(i=j;i<k;++i)
using namespace std;

struct Word {
	char origin[128];
	char lower[128];
	bool alone;

	bool operator<(const Word &b) const {
		return strcmp(origin, b.origin) < 0;
	}
} word[1024];

int main() {
	int n, i, j;
	for (n = 0; scanf("%s", word[n].origin) && word[n].origin[0] != '#'; ++n) {
		for (j = 0; word[n].origin[j]; ++j)
			word[n].lower[j] = tolower(word[n].origin[j]);
		word[n].lower[j] = 0;
		sort(word[n].lower, word[n].lower + j);
		word[n].alone = true;
	}

	rep(i,0,n) rep(j,i+1,n)
		if (strcmp(word[i].lower, word[j].lower) == 0)
			word[i].alone = word[j].alone = false;

	sort(word, word + n);
	rep(i,0,n) if (word[i].alone) puts(word[i].origin);

	return 0;
}
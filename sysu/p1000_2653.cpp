#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

char s[100005];

int main() {
	int i, sum = 0;
	bool hasZero = false;
	scanf("%s", s);

	for (i = 0; s[i]; ++ i) {
		if (s[i] == '0')
			hasZero = true;
		sum = (sum + s[i] - '0') % 3;
	}
	if (sum == 0 && hasZero) {
		sort(s, s + i, greater<char>());
		puts(s);
	} else
		puts("-1");
	return 0;
}
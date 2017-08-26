#include <cstdio>
char s[100005];
int main() {
	int n, i, d = 0, a = 0;
	scanf("%d%s", &n, s);
	for (i = 0; i < n; ++i)
		if (s[i] == 'A') ++a;
		else if (s[i] == 'D') ++d;
	if (a > d) puts("Anton");
	else if (a < d) puts("Danik");
	else puts("Friendship");
	return 0;
}
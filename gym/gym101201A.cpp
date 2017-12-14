#include <bits/stdc++.h>
using namespace std;

int a[100];
int f[100];
int ans;
int len;

void read()
{
	char ch;
	while (!isalpha(ch=getchar()));
	a[len=1]=ch-'a';
	while (isalpha(ch=getchar())) a[++len]=ch-'a';
}
void solve()
{
	for (int i=1; i<=len; ++i)
	{
		f[i]=1;
		for (int j=1; j<i; ++j)
			if (a[j]<a[i]) f[i]=max(f[i], f[j]+1);
	}
	for (int i=1; i<=len; ++i)
		ans=max(f[i], ans);
	printf("%d\n", 26-ans);
}
int main()
{
	read();
	solve();
	return 0;
}
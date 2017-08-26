#include <map>
#include <string>
#include <iostream>
#include <algorithm>
int top, id;
string q[1000005];
map<string,int> mp;
void dfs(int x,string t,int now) {
	if(x==0) { q[++top]=t; return; }
	for(int i=now+1;i<26;i++) dfs(x-1,t+(char)(i+'a'),i);
}
int main() {
	for(int i=1;i<=5;i++) {
		top=0;
		dfs(i,"",-1);
		sort(q+1,q+top+1);
		for(int j=1;j<=top;j++)
			mp[q[j]]=++id;
	}
	string t;
	while(cin>>t)
		printf("%d\n",mp[t]);
	return 0;
}

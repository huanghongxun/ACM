#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[105][105];
char a[105];

int main() {

	while(scanf("%s",a)>0&&a[0]!='e') {
		int len=strlen(a);
		memset(dp,0,sizeof(dp));
		for(int i=len-2;i>=0;i--) {
			for(int j=i+1;j<len;j++) {
				dp[i][j]=dp[i+1][j];
				for(int k=i+1;k<=j;k++) {
					if(a[i]=='('&&a[k]==')'||a[i]=='['&&a[k]==']')
						dp[i][j]=max(dp[i][j],dp[i+1][k-1]+dp[k][j]+2);
				}
			}
		}
		printf("%d\n", dp[0][len-1]);
	}

	return 0;
}
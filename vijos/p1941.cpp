#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <cmath>
#include <map>
#include <functional>
#include <utility>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef long long ll;
#define inf 0x7ffffff
#define eps 1e-6
#define rep(i,j,k) for(i=j;i<k;i++)
#define repd(i,j,k) for(i=j-1;i>=k;i--)
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define foreach(i,j) for(i=j.begin();i!=j.end();i++)

ll read() {
    ll x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}

int num[205][4];
int show[105][4];

int main() {
	int n = read(), i, j;
	memset(show,0,sizeof(show));
	FOR(i,1,n) FOR(j,1,3) show[num[i][j]=read()][j]++;
	FOR(i,1,n) {
		int mark=0;
		FOR(j,1,3) if(show[num[i][j]][j]==1) mark+=num[i][j];
		printf("%d\n", mark);
	}
	
	return 0;
}


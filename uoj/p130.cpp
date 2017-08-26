#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,j,k) for(i=j;i<k;i++)
typedef pair<long long, int> pli;
priority_queue<pli, vector<pli>, greater<pli> > pq;
long long w[200005];
int main() {
	int n, k, i, j;
	scanf("%d%d",&n,&k);
	rep(i,0,n) scanf("%lld", w+i);
	while((n-1)%(k-1)) n++;
	rep(i,0,n) pq.push(pli(w[i],0));
	long long ans=0;
	while(pq.size()>1) {
		long long sum=0;int ma=0;
		rep(j,0,k) {
			if(!pq.size())break;
			pli a=pq.top();pq.pop();
			sum+=a.first; ma=max(ma,a.second);
		}
		pq.push(pli(sum,ma+1));
		ans+=sum;
	}
	printf("%lld\n%d",ans,pq.top().second);
	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
double a[1005], b[1005], d[1005];
int main() {
	int n, k, i;
	while(scanf("%d%d", &n, &k)==2&&!(n==0&&k==0)) {
		for(i=0;i<n;i++) scanf("%lf",a+i);
		for(i=0;i<n;i++) scanf("%lf",b+i);
		double l=0,r=1,mid;
		while(r-l>1e-7) {
			mid=(l+r)/2;
			for(i=0;i<n;i++) d[i]=a[i]-mid*b[i];
			sort(d,d+n);
			double tmp=0;
			for(i=k;i<n;i++) tmp+=d[i];
			if(tmp>0) l=mid; else r=mid;
		}
		printf("%.0lf\n",mid*100);
	}
	return 0;
}

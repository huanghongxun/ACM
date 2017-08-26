#include <stdio.h>

typedef long long ll;

long a[21],b[21];
ll pd[21];
ll mi(long d,long m){
	int i;
	ll ans;
	if(d==0)
	return 0;
	ans=1;
	for(i=1;i<=m;i++)
	ans*=d;
	return ans;
}
int main(){
	ll i,j,k,m,n;
	ll tmp;
	ll min;
	scanf("%lld%lld",&n,&m);
	ll ans=0;
	for(i=1;i<=m;i++)
	scanf("%ld%ld",&a[i],&b[i]);
	for(i=1;i<=n;i++){
		min=0x7fffffff;
		for(j=1;j<=m;j++){
			k=a[j]*mi(pd[j]+1,b[j])-a[j]*mi(pd[j],b[j]);
			if(k<min){
				min=k;
				tmp=j; 
			}
		} 
		ans+=min;
		pd[tmp]++; 
	}
	printf("%lld\n",ans);
	return 0; 
}
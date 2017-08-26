#include<cstdio>
char ch,B[1<<15],*S=B,*T=B;
int F(){
	while(ch=getchar(),ch<'0'||ch>'9');int aa=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')aa=aa*10+ch-'0';return aa;
}
#define N 200010
#define rep(i,n)
int n,dfs[N],pos[N],ans,l=1,r,a[N];
int main(){
	n=r=F();
	rep(i,n) dfs[i]=F();
	rep(i,n) pos[F()]=i;
	rep(i,n) dfs[i]=pos[dfs[i]];
	rep(i,n) pos[dfs[i]]=i;
	rep(i,n) {
		a[pos[i]]=1;
		if(i<=2||pos[i]<pos[i-1])ans+=2;
		else if(pos[i]==l&&i==n-r+l&&pos[i]==pos[i-1]+1)ans++;
		while(a[l])l++;while(a[r])r--;
	}
	printf("%.3lf\n",ans*.5);
}
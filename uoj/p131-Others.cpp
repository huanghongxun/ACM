#include<cstdio>
#include<algorithm>
char ch,B[1<<15],*S=B,*T=B;
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<15,stdin),S==T)?0:*S++)
int aa,bb;int F(){
	while(ch=getc(),(ch<'0'||ch>'9')&&ch!='-');ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
	while(ch=getc(),ch>='0'&&ch<='9')aa=aa*10+ch-'0';return bb?aa:-aa;
}
char U[1<<15],*O=U,*W=U+(1<<15),stk[20],ts;
#define mod 1000000000
#define pr(x) (x<0?putc('-'),x=-x:1,x>=mod?pri(x/mod),pr9(x%mod):pri(x))
#define putc(c) (O==W?fwrite(U,1,1<<15,stdout),O=U,1:1,*O++=c)
#define outp() fwrite(U,1,O-U,stdout)
void pri(int x){
	if(!x)putc('0');else{
		for(ts=0;x;x/=10)stk[++ts]=x%10+'0';
		for(;ts;putc(stk[ts--]));
	}
}
void pr9(int x){
	for(int i=1;i<=9;i++)stk[i]=x%10+'0',x/=10;
	for(int i=9;i;putc(stk[i--]));
}
#define N 300010
#define cmax(a,b) (a<b?a=b:1)
#define cmin(a,b) (a>b?a=b:1)
int n,sa[N],hei[N],rk[N],fa[N]={0,1},siz[N]={0,1},max[N],min[N],X[N],Y[N],c[N],*x=X,*y=Y,*t,yt,i,j,k,m='z';
long long ans[N][2];
char s[N];
struct E{int x,y,v;}d[N];
bool operator<(const E&a,const E&b){return a.v>b.v;}
#define cmp(u,v) (x[u]!=x[v]||x[u+k]!=x[v+k])
int gf(int x){return fa[x]==x?x:fa[x]=gf(fa[x]);}
int main(){
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++)c[x[i]=s[i]]++;
	for(i=1;i<=m;i++)c[i]+=c[i-1];
	for(i=n;i;i--)sa[c[x[i]]--]=i;
	for(k=1;k<n&&(k==1||m<n);k<<=1,t=x,x=y,y=t){
		for(yt=0,i=n-k+1;i<=n;i++)y[++yt]=i;
		for(i=1;i<=n;i++)if(sa[i]>k)y[++yt]=sa[i]-k;
		for(i=1;i<=m;i++)c[i]=0;
		for(i=1;i<=n;i++)c[x[i]]++;
		for(i=1;i<=m;i++)c[i]+=c[i-1];
		for(i=n;i;i--)sa[c[x[y[i]]]--]=y[i];
		for(i=1,m=0;i<=n;i++)y[sa[i]]=(i==1||cmp(sa[i],sa[i-1])?++m:m);
	}
	for(i=1;i<=n;i++)rk[sa[i]]=i;
	for(i=1,k=0;i<=n;hei[rk[i++]]=k)
	for(k?k--:0,j=sa[rk[i]-1];s[i+k]==s[j+k];k++);
	for(i=1;i<=n;i++)max[rk[i]]=min[rk[i]]=F();
	for(i=2;i<=n;i++)fa[i]=i,siz[i]=1,d[i-1]=(E){i-1,i,hei[i]};
	for(std::sort(d+1,d+n),i=d[1].v,j=1;i>=0;i--){
		for(ans[i][0]=0,ans[i][1]=-1LL<<62;j<n&&d[j].v==i;j++){
			int x=gf(d[j].x),y=gf(d[j].y);
			cmax(ans[i][1],1LL*max[x]*max[y]),
			cmax(ans[i][1],1LL*min[x]*min[y]);
			ans[i][0]+=1LL*siz[x]*siz[y],fa[x]=y,siz[y]+=siz[x];
			cmax(max[y],max[x]),cmin(min[y],min[x]);
		}
		if(ans[i][0]+=ans[i+1][0],ans[i+1][0])cmax(ans[i][1],ans[i+1][1]);
	}
	for(i=0;i<n;i++)pr(ans[i][0]),putc(' '),pr(ans[i][1]),putc('\n');outp();
}

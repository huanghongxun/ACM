#include<cstdio>
#include<cstring>
int read() {
	int s = 0, f = 1; char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
#define N 100010
int n,d,m,A[N][110],B[N],C[N],AA[N],flag,pos,id[110][110],cnt;
int check(int i,int j){int f=0;
	for(int k=1;k<=d;k++)f+=A[i][k]*A[j][k];
	return f%m==0;
}
#define rep(i,n) for(int i=1;i<=n;i++)
void work2(){
	rep(i,n)rep(j,d)B[j]+=A[i][j];
	rep(i,d)B[i]%=m;
	rep(i,n)rep(j,d)C[i]+=A[i][j]*B[j];
	rep(i,n)C[i]=(C[i]%m-AA[i]+m+m)%m;
}
void work3(){
	rep(i,d)rep(j,d)id[i][j]=++cnt;
	rep(i,n)rep(j,d)rep(k,d)B[id[j][k]]+=A[i][j]*A[i][k];
	rep(i,cnt)B[i]%=m;
	rep(i,n)rep(j,d)rep(k,d)C[i]+=A[i][j]*A[i][k]*B[id[j][k]];
	rep(i,n)C[i]=(C[i]-AA[i]*AA[i]+m+m)%m;
}
int main(){
	n=read(),d=read(),m=read();
	rep(i,n)rep(j,d)A[i][j]=read()%m,AA[i]=AA[i]+A[i][j]*A[i][j];
	rep(i,n)AA[i]%=m;
	if(m==2)work2();else work3();
	for(int i=1;i<=n&&!flag;i++)if((n-1)%m!=C[i])flag=1,pos=i;
	if(flag==0)return puts("-1 -1"),0;
	rep(i,n)if(i!=pos&&check(pos,i)){
		if(pos<i)printf("%d %d\n",pos,i);
		else printf("%d %d\n",i,pos);
		return 0;
	}
}

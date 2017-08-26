#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ext/pb_ds/priority_queue.hpp>
typedef long long ll;
char ch,_B[1<<15],*_S=_B,*_T=_B;
#define _getc() (_S==_T&&(_T=(_S=_B)+fread(_B,1,1<<15,stdin),_S==_T)?0:*_S++)
int aa,_swp;int F(){
	while(ch=_getc(),ch<'0'||ch>'9');aa=ch-'0';
	while(ch=_getc(),ch>='0'&&ch<='9')aa=aa*10+ch-'0';return aa;
}
#define swap(a,b) (_swp=a,a=b,b=_swp)
#define min(a,b) (a<b?a:b)
#define Mem(a) memset(a,0,sizeof(a))

const int N=55,M=3010,oo=1<<28;
int n,m,S,T,k,x[300010],y[300010],v[300010],max_v;
class Graph{public:
	int et,la[N],nxt[M],to[M],fl[M];
	Graph(){et=1;}
	void add(int x,int y,int v){
		to[++et]=y,fl[et]=v,nxt[et]=la[x],la[x]=et;
		to[++et]=x,fl[et]=0,nxt[et]=la[y],la[y]=et;
	}
};
namespace Task1{
	Graph G;
	int ans[1<<20|10],tot,vis[N],tim,now,use[M];
	bool dfs(int x){
		if(x==T)return 1;vis[x]=tim;
		for(int i=G.la[x];i;i=G.nxt[i])
		if(!use[i>>1]&&vis[G.to[i]]!=tim&&G.fl[i]&&dfs(G.to[i]))return 1;
		return 0;
	}
	void solve(){
		for(int i=1;i<=m;i++)G.add(x[i],y[i],v[i]);
		for(int s=0;s<1<<m;s++){
			tim++,now=0;
			for(int i=1;i<=m;i++)
			if(s&(1<<i-1))now+=v[i],use[i]=1;
			else use[i]=0;
			if(dfs(S)==0)ans[++tot]=now;
		}
		std::sort(ans+1,ans+1+tot);
		for(int i=1;i<=tot&&i<=k;i++)printf("%d\n",ans[i]);
		if(k>tot)puts("-1");
	}
}
namespace Task2{
	struct P{
		int x,y;
		bool operator<(const P&a)const{return x<a.x||x==a.x&&y<a.y;}
	}a[300010];
	ll ans;
	struct D{
		int x,type;ll v;
		bool operator<(const D&a)const{return v>a.v;}
	}tmp;
	std::priority_queue<D>q;
	void solve(){
		for(int i=1;i<=m;i++){
			if(x[i]!=S&&y[i]!=T)swap(x[i],y[i]);
			if(x[i]==S)a[y[i]].x=v[i];else a[x[i]].y=v[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
			ans+=a[i].x,a[i].x=a[i].y-a[i].x;
		}
		std::sort(a+1,a+1+n);
		printf("%lld\n",ans);
		for(q.push((D){3,0,ans+a[3].x});--k&&!q.empty();){
			tmp=q.top(),q.pop();
			printf("%lld\n",tmp.v);
			if(tmp.type==0){
				q.push((D){tmp.x,1,tmp.v-a[tmp.x].x+a[tmp.x].y});
				if(tmp.x<n)q.push((D){tmp.x+1,0,tmp.v-a[tmp.x].x+a[tmp.x+1].x});
			}
			if(tmp.x<n)q.push((D){tmp.x+1,0,tmp.v+a[tmp.x+1].x});
		}
		if(k)puts("-1");
	}
}
namespace Network_Flow{
	int s,t,la[N],d[N];
	int bfs(Graph&G){
		static int q[N],l,r,i;Mem(d);
		for(q[l=r=0]=t,d[t]=1;l<=r;l++)
		for(i=G.la[q[l]];i;i=G.nxt[i])
		if(G.fl[i^1]&&!d[G.to[i]])
		d[q[++r]=G.to[i]]=d[q[l]]+1;
		return d[s];
	}
	int dfs(Graph&G,int x,int ret){
		if(x==t||ret==0)return ret;
		int tmp,flow=0;
		for(int&i=la[x];i;i=G.nxt[i])
		if(d[x]==d[G.to[i]]+1){
			tmp=dfs(G,G.to[i],min(G.fl[i],ret-flow));
			G.fl[i]-=tmp,G.fl[i^1]+=tmp,flow+=tmp;
			if(flow==ret)return flow;
		}
		return flow;
	}
	int maxflow(Graph&G,int _s,int _t){
		if(s=_s,t=_t,s==t)return oo;
		int flow=0;
		while(bfs(G)){
			memcpy(la,G.la,sizeof(G.la)),flow+=dfs(G,s,oo);
			if(flow>oo)return oo;
		}
		return flow;
	}
}
namespace Task3{
	bool checkS[N],checkT[N],cut[M],vis[N];
	int fs[N],ft[N],flow;Graph G,oG,tar;
	void dfs(Graph&G,int x){
		vis[x]=1;
		for(int i=G.la[x];i;i=G.nxt[i])
		if(G.fl[i]&&!vis[G.to[i]])dfs(G,G.to[i]);
	}
	void cutG(Graph&G){
		memset(vis,0,sizeof(vis)),dfs(G,S);
		for(int i=1;i<=m;i++)cut[i]=vis[x[i]]&&!vis[y[i]];
	}
	struct D{
		bool in[M],out[M];
		int pos,val,now;
		bool operator<(const D&a)const{return val>a.val;}
		void calc(){
			G=oG;pos=now=0;val=oo;
			for(int i=1;i<=m;i++)
			if(in[i])now+=v[i],G.fl[i<<1]=G.fl[i<<1|1]=0;
			else if(out[i])G.fl[i<<1]=oo,G.fl[i<<1|1]=0;
			Mem(checkS),Mem(checkT),Mem(fs),Mem(ft);
			flow=Network_Flow::maxflow(G,S,T);cutG(G);
			for(int i=1;i<=m;i++)if(!in[i]&&!out[i])
			if(cut[i]){
				if(tar=G,!checkS[x[i]])checkS[x[i]]=1,fs[x[i]]=Network_Flow::maxflow(tar,S,x[i]);
				if(tar=G,!checkT[y[i]])checkT[y[i]]=1,ft[y[i]]=Network_Flow::maxflow(tar,y[i],T);
				if(min(fs[x[i]],ft[y[i]])<val)val=min(fs[x[i]],ft[y[i]]),pos=i;
			}
			else if(v[i]<val)val=v[pos=i];
			val+=now+flow;
		}
	}a,b;
	__gnu_pbds::priority_queue<D>q;
	void solve(){
		for(int i=1;i<=m;i++)oG.add(x[i],y[i],v[i]);
		a.calc();printf("%d\n",flow);
		if(a.val<oo)q.push(a);
		while(--k&&!q.empty()){
			a=b=q.top(),q.pop(),printf("%d\n",a.val);
			a.in [a.pos]=1;a.calc();if(a.val<oo)q.push(a);
			b.out[b.pos]=1;b.calc();if(b.val<oo)q.push(b);
		}
		if(k)puts("-1");
	}
}
int main(){
	n=F(),m=F(),S=F(),T=F(),k=F();
	for(int i=1;i<=m;i++)x[i]=F(),y[i]=F(),v[i]=F(),v[i]>max_v?max_v=v[i]:1;
	if(n<=10&&m<=20&&max_v<=65536)Task1::solve();
	else if(n<=50&&m<=1500&&k<=100&&max_v<=65536)Task3::solve();
	else Task2::solve();
}
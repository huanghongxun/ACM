#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,x,y) for(i=x;i<=y;i++)
#define REP(i,x,y) for(int i=(x);i<=(y);i++)
#define CL(S,x) memset(S,x,sizeof(S))
#define CP(S1,S2) memcpy(S1,S2,sizeof(S2))
#define pb push_back
const int N=12010,inf=int(1e9),V=100010,E=500010;
int n,n0,i,j,k,l,r,p,x,y,z,L,X[N],o[N];
struct FlowG{
    int S,T,N,edge,e[E],b[E],c[E],fir[V],last[V],vh[V],h[V],cur[V],pre[V];
    void clear(){edge=1;CL(fir,0);}
    void add2(int x,int y,int z){e[++edge]=y;c[edge]=z;b[edge]=fir[x];fir[x]=edge;}
    void add(int x,int y,int z){add2(x,y,z);add2(y,x,0);}
    int sap(){
        int i,k,p,flow,minh,ans=0;CL(h,0);CL(vh,0);vh[0]=N;CP(cur,fir);CL(pre,0);pre[S]=S;
        for(i=S;h[S]<N;){
            if(i==T){
                flow=inf;for(p=S;p!=T;p=e[cur[p]])flow=min(flow,c[cur[p]]);
                ans+=flow;for(p=S;p!=T;p=e[cur[p]])c[cur[p]]-=flow,c[cur[p]^1]+=flow;i=S;
            }
            for(k=cur[i];k;k=b[k])
            if(c[k]&&h[e[k]]+1==h[i]){cur[i]=k;pre[e[k]]=i;i=e[k];break;}
            if(!k){
                if(--vh[h[i]]==0)break;
                cur[i]=fir[i];minh=N;for(k=cur[i];k;k=b[k])if(c[k])minh=min(minh,h[e[k]]+1);
                ++vh[h[i]=minh];i=pre[i];
            }
        }
        return ans;
    }
}F;
 
struct graph{
    int edge,fir[N],e[N],b[N],w[N];bool done[N];
    int fa[N],fae[N],sz[N],ms[N],st[N],st1[N],st2[N];
    void clear(){edge=1;CL(fir,0);}void add2(int x,int y,int z){e[++edge]=y;w[edge]=z;b[edge]=fir[x];fir[x]=edge;}
    void add(int x,int y,int z){add2(x,y,z);add2(y,x,z);}
    int dfs(int i,int f,int ma){st[++st[0]]=i;fa[i]=f;sz[i]=1;ms[i]=ma;for(int k=fir[i];k;k=b[k])if(!done[k]&&e[k]!=f)fae[e[k]]=k,sz[i]+=dfs(e[k],i,max(ma,w[k]));return sz[i];}
    void fadd(){
        int t1=++F.N;REP(p,1,st1[0])F.add(st1[p],t1,inf); REP(p,1,st2[0])if(ms[st2[p]]>=L)F.add(t1,n+st2[p],inf);
        int t2=++F.N;REP(p,1,st1[0])if(ms[st1[p]]>=L)F.add(st1[p],t2,inf); REP(p,1,st2[0])F.add(t2,n+st2[p],inf);
    }
    void fun(int r){
        st[0]=0;int sz0=dfs(r,0,0),best=N,A,B,O,p;if(sz0<=1)return;
        rep(p,2,st[0]){int i=st[p],tt;if((tt=max(sz0-sz[i],sz[i]))<best)best=tt,A=i,B=fa[i],O=fae[i];}
        done[O]=done[O^1]=1;
        st[0]=0;dfs(A,0,w[O]);rep(i,0,st[0])st1[i]=st[i];
        st[0]=0;dfs(B,0,w[O]);rep(i,0,st[0])st2[i]=st[i];
        fadd();rep(i,0,sz0)swap(st1[i],st2[i]);fadd();
        fun(A);fun(B);
    }
    bool ok(){
        F.clear();F.S=2*n+1;F.N=F.T=2*n+2;REP(i,1,n0)F.add(F.S,i,1);REP(i,1,n0)F.add(n+i,F.T,X[i]);
        CL(done,0);fun(1);return F.sap()==n0;
    }
}H;
 
struct ori{
    vector<int> e[N],ew[N];int li[N],lw[N];
    void adde(int x,int y,int z){e[x].pb(y);ew[x].pb(z);}
    void work(int x,int y,int f){
        if(x==y){H.add(f,li[x],lw[x]);return;}
        int nod=++n;H.add(f,nod,0);work(x,(x+y)/2,nod);work((x+y)/2+1,y,nod);
    }
    void bui(int i,int f){
        li[0]=0;for(int k=0;k<e[i].size();k++)if(e[i][k]!=f)li[++li[0]]=e[i][k],lw[li[0]]=ew[i][k];
        if(li[0])work(1,li[0],i);for(int k=0;k<e[i].size();k++)if(e[i][k]!=f)bui(e[i][k],i);
    }
}G;
 
int main(){
    scanf("%d",&n);n0=n;
    rep(i,1,n-1)scanf("%d%d%d",&x,&y,&z),G.adde(x,y,z),G.adde(y,x,z),o[i]=z;rep(i,1,n)scanf("%d",&X[i]);
    sort(o+1,o+1+(n-1));o[0]=1;rep(i,2,n-1)if(o[i]!=o[i-1])o[++o[0]]=o[i];
    H.clear();G.bui(1,0);
    for(l=1,r=o[0];l<r;){int mid=(l+r+1)/2;L=o[mid];if(H.ok())l=mid;else r=mid-1;}printf("%d\n",o[l]);
    return 0;
}

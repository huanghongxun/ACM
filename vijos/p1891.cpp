#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#define inf 1000000000
#define ll long long 
using namespace std;
inline ll read() {
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define N 605
#define M 100005
ll ans;
int n,K,T,cnt=1;
ll a[605];
bool mark[605];
class ZKW {
protected:
    int start, end, ans; //�����յ�
    int to[M], next[M], head[N], cnt; //�ڽӱ�
	int dis[N], w[M], c[M], vis[N]; //��κ�ͼ
	int q[N*8];
    //���Ĵ�������￪ʼ
    bool spfa() { //�������ͼ
        memset(dis,-1,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[end]=0; vis[end]=1;
        int f=0,r=0; q[r++]=end;
        while(f<r) {
            int sta=q[f++];
            for(int i=head[sta];i!=-1;i=next[i])
                if(w[i^1]>0&&dis[to[i]]<dis[sta]+c[i^1]) {
                    dis[to[i]]=dis[sta]+c[i^1];
                    if(!vis[to[i]]) { vis[to[i]] = 1; q[r++]=to[i]; }
                }
            vis[sta]=0;
        }
        return dis[start]!=-1;
    }
    int find(int x,int low) { //Ѱ������·
        int tmp=0,result=0; vis[x]=1;
        if(x==end) return low;
        for(int i=head[x];i!=-1&&result<low;i=next[i])
            if(w[i]>0&&dis[to[i]]==dis[x]-c[i]&&!vis[to[i]]) {
                tmp=find(to[i],min(w[i],low-result));
                w[i]-=tmp; w[i^1]+=tmp;
                ans+=tmp*c[i];
                result+=tmp;
            }
        return result;
    }
    //���Ĵ�����������
public:
    void init(int start, int end) { //��������涨�����յ�
        this->start = start;
        this->end = end;
        memset(head,-1,sizeof(head));
        memset(next,-1,sizeof(next));
        cnt = 0;
    }
    void add(int a,int b,int flow,int cost) { //�����������ͼ
        to[cnt]=b,next[cnt]=head[a],w[cnt]=flow,c[cnt]=cost,head[a]=cnt++; //�����
        to[cnt]=a,next[cnt]=head[b],w[cnt]=0,c[cnt]=-cost,head[b]=cnt++; //�����
    }
    int zkw() { //������������������
        ans=0;
        while(spfa()) {
        	vis[end]=1;
        	while(vis[end]) {
	        	memset(vis,0,sizeof(vis));
				find(start,inf);
			}
		}
        return ans;
    }
} g;
void build() {
    for(int i=2;i<=n+1;i++)g.add(1,i,1,-a[i-1]);
    for(int i=n+2;i<=2*n+1;i++)g.add(i-n,i,1,-a[i-1]);
    for(int i=n+2;i<=2*n+1;i++)g.add(i,2*n+2,1,-a[i-1+n]);
    for(int i=2;i<=2*n+2;i++)g.add(i-1,i,K,0);
    g.add(0,1,K,0);
    g.add(2*n+2,T,K,0);
}
int main() {
    n=read();K=read();T=2*n+3;
    for(int i=1;i<=3*n;i++)a[i]=read();
    g.init(0,T);
    build();
    g.zkw();
    printf("%lld",-ans);
    return 0;
}

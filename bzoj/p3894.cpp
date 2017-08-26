#include <cstdio>
#include <cstring>
#include <queue>
#define FOR(i,1,n) for(i=1;i<=n;i++)
#define M 30300
#define S 0
#define T 30299
#define INF 0x3f3f3f3f
#define P(i,j) ((i)*n-n+(j))
using namespace std;
const int dx[]={0,0,0,1,-1};
const int dy[]={0,1,-1,0,0};
int m,n,ans;
class Dinic {
protected:
    int start, end; //起点和终点
    int to[M], next[M], head[M], cnt; //邻接表
	int level[M],w[M]; //层次和图
	queue<int> que; 
    //核心代码从这里开始
    bool bfs() { //构建层次图
        memset(level,-1,sizeof(level));
        level[start]=0;
        que.push(start);
        while(!que.empty()) {
            int sta=que.front();
            que.pop();
            for(int i=head[sta];i!=-1;i=next[i])
                if(w[i]>0&&level[to[i]]<0) {
                    level[to[i]]=level[sta]+1;
                    que.push(to[i]);
                }
        }
        return level[end]!=-1;
    }
    int find(int x,int low) { //寻找增广路
        int tmp=0,result=0;
        if(x==end) return low;
        for(int i=head[x];i!=-1&&result<low;i=next[i])
            if(w[i]>0&&level[to[i]]==level[x]+1) {
                tmp=find(to[i],min(w[i],low-result));
                w[i]-=tmp; w[i^1]+=tmp;
                result+=tmp;
            }
        if(!result) level[x]=-1;
        return result;
    }
    //核心代码从这里结束
public:
    Dinic() { //构造函数
        memset(head,-1,sizeof(head));
        memset(next,-1,sizeof(next));
    }
    void init(int start, int end) { //再用这个规定起点和终点
        this->start = start;
        this->end = end;
    }
    void add(int a,int b,int flow) { //先用这个构建图
        to[cnt]=b,next[cnt]=head[a],w[cnt]=flow,head[a]=cnt++; //反向边
        to[cnt]=a,next[cnt]=head[b],w[cnt]=0,head[b]=cnt++; //正向边
    }
    int dinic() { //最后用这个计算网络流
        int ans=0,tmp;
        while(bfs()) ans+=find(start,INF);
        return ans;
    }
} g;

int main() {
	int i,j,k,x;
	cin>>m>>n;

	FOR(i,1,m) FOR(j,1,n) {
		scanf("%d",&x);
		ans+=x;
		g.add(S,P(i,j),x);
	}

	FOR(i,1,m) FOR(j,1,n) {
		scanf("%d",&x);
		ans+=x;
		g.add(P(i,j),T,x);
	}

	FOR(i,1,m) FOR(j,1,n) {
		scanf("%d",&x);
		ans+=x;
		g.add(S,P(i,j)+m*n,x);
		FOR(k,0,4) {
			int xx=i+dx[k];
			int yy=j+dy[k];
			if(xx<=0||yy<=0||xx>m||yy>n)
				continue;
			g.add(P(i,j)+m*n,P(xx,yy),INF);
		}
	}

	FOR(i,1,m) FOR(j,1,n) {
		scanf("%d",&x);
		ans+=x;
		g.add(P(i,j)+2*m*n,T,x);
		FOR(k,0,4) {
			int xx=i+dx[k];
			int yy=j+dy[k];
			if(xx<=0||yy<=0||xx>m||yy>n)
				continue;
			g.add(P(xx,yy),P(i,j)+2*m*n,INF);
		}
	}

	cout<<ans-g.dinic()<<endl;
	return 0;
}

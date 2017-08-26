#include<cstdio>

inline int max(int a,int b) { return a>b?a:b; }

int n,m,p;

class Queue
{
public:
        Queue():head(0),tail(-1) {}
        int Head() { return head<=tail?q[head]:-0xfffffff; }
        int num() { return t[head]; }
        void push(int num,int val)
        {
                while(head<=tail && q[tail]<=val) tail--;
                q[++tail]=val; t[tail]=num;
        }
        void pop() { head++; }
private:
        int q[1000],t[1000],head,tail;
};

template<class T>
class ModArr
{
public:
        T& operator[](int x) { return a[(x%n+n)%n]; }
private:
        T a[1000];
};
ModArr<int> a[1000],f[1000];
ModArr<Queue> q;
int cost[1000];

void init()
{
        scanf("%d%d%d",&n,&m,&p);
        for(int i=0;i<n;i++)
                for(int j=0;j<m;j++) scanf("%d",&a[j][i]);
        for(int i=1;i<m;i++)
                for(int j=0;j<n;j++) a[i][j]+=a[i-1][j-1];
        for(int i=0;i<n;i++) scanf("%d",&cost[i]);
}

void work()
{
        int ans=-0x7fffffff;
        for(int j=0;j<n;j++)
        {
                f[0][j]=a[0][j]-cost[j];
                q[j].push(0,-cost[j]);
                ans=max(ans,f[0][j]);
        }
        for(int i=1;i<m;i++)
        {
                int temp=ans;
                for(int j=0;j<n;j++)
                {
                        if(q[j-i].num()<=i-p) q[j-i].pop();
                        q[j-i].push(i,temp-a[i-1][j-1]-cost[j]);
                        f[i][j]=q[j-i].Head()+a[i][j];
                        ans=max(ans,f[i][j]);
                }
        }
        printf("%d\n",ans);
}

int main()
{
        init();
        work();
        return 0;
}
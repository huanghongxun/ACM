#include <cstdio>
#include <algorithm>
using namespace std;

int Son[50004],Parent[50004],Ecnt,Belong[50004],Bcnt;
long long Least_Cost[50004],Deep[50004];
struct Edge {
    int next,link;
    long long len;
}ed[100005];

inline void Add(int u,int v,long long l) {
    ed[++Ecnt].next=Son[u],ed[Ecnt].link=v,ed[Ecnt].len=l;
    Son[u]=Ecnt;
}

void Get_Deep_and_Parent(int x,int pa,long long dep) {
    Parent[x]=pa,Deep[x]=dep;
    for (int i=Son[x];i;i=ed[i].next)
        if (ed[i].link!=pa) Get_Deep_and_Parent(ed[i].link,x,dep+ed[i].len);
}

void Get_Least_Cost(int x,bool sep,long long len) {
    if (!sep)
    for (int i=Son[x],s=0;i;i=ed[i].next)
    if (ed[i].link!=Parent[x])
    {
        s++;
        if (s>=2)
        {
            sep=true;
            break;
        }
    }
    Least_Cost[x]=len;
    for (int i=Son[x];i;i=ed[i].next)
    if (ed[i].link!=Parent[x])
    {
        Belong[ed[i].link]=Belong[x];
        if (sep) Get_Least_Cost(ed[i].link,sep,len+ed[i].len);
        else Get_Least_Cost(ed[i].link,sep,0);
    }
}
int Length[50004];
inline bool Cmp(const int& A,const int& B) {
    return Deep[A]<Deep[B];
}

inline bool Cmp1(const int &A,const int& B) {
    return Length[A]>Length[B];
}
inline bool Cmp2(const long long& A,const long long& B) {
    return A>B;
}

int Seq[50004];
long long Sum=0;
bool Go[50004];
long long Rest[50004];
int N[50004];
int m,n;
int Last[50004],Cur[50004];
bool Vs[50004];

bool Check(long long Dis)
{
    for (int i=Son[1];i;i=ed[i].next) Go[ed[i].link]=false,Cur[ed[i].link]=0;
    Rest[0]=0;
    for (int i=1;i<=m;i++)
    {
        if (Dis>Deep[Seq[i]])
        {
            Rest[++Rest[0]]=Dis-Deep[Seq[i]];
            Last[Rest[0]]=Cur[Belong[Seq[i]]];
            Cur[Belong[Seq[i]]]=Rest[0];
            Vs[Rest[0]]=false;
            continue;
        }
        if (!Go[Belong[Seq[i]]] && Dis>=Least_Cost[Seq[i]]) Go[Belong[Seq[i]]]=true;
    }
    N[0]=0;
    for (int i=Son[1];i;i=ed[i].next)
        if (!Go[ed[i].link]) N[++N[0]]=ed[i].link;
    sort(Rest+1,Rest+Rest[0]+1,Cmp2);
    sort(N+1,N+N[0]+1,Cmp1);
    if (N[0]>Rest[0]) return false;
    for (int i=1,j=1;i<=N[0]&&j<=Rest[0];i++)
    {
        while (Vs[Cur[N[i]]]) Cur[N[i]]=Last[Cur[N[i]]];
        if (Cur[N[i]]) Vs[Cur[N[i]]]=true;
        else
        {
            if (Rest[j]<Length[N[i]]) return false;
            Vs[j]=true;
        }
        while (Vs[j]) j++;
    }
    return true;
}

int main() {
    scanf("%d",&n);
    for (int i=1,u,v,l;i<n;i++) scanf("%d%d%d",&u,&v,&l),Add(u,v,l),Add(v,u,l),Sum=Sum+l;
    Get_Deep_and_Parent(1,0,0);
    for (int i=Son[1];i;i=ed[i].next) Length[ed[i].link]=ed[i].len,Belong[ed[i].link]=ed[i].link,Bcnt++,Get_Least_Cost(ed[i].link,false,0);
    scanf("%d",&m);
    if (m<Bcnt) {
        puts("-1");
        return 0;
    }
    for (int i=1;i<=m;i++) scanf("%d",Seq+i);
    sort(Seq+1,Seq+m+1,Cmp);
    long long l=0,r=Sum,mid;
    while (l<r-1) {
        mid=(l+r)>>1;
        if (Check(mid)) r=mid;
        else l=mid;
    }
    for (long long i=l;i<=r;i++)
        if (Check(i)) {
            printf("%lld\n",i);
            return 0;
        }
    puts("-1");
    return 0;
}

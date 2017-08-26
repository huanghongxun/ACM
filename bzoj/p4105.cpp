#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 100100
using namespace std;
int n,m,p;
int v[M],on_ring[M],T;
struct List{
    int val;
    List *next;
    friend List* Merge(List *r2,List *r3,int len)
    {
        int i;
        List *head=new List,*r1=head;
        r1->val=r2->val+r3->val;
        for(i=2;i<=len;i++)
        {
            r1->next=new List;
            r1=r1->next;
            r2=r2->next;
            r3=r3->next;
            r1->val=r2->val+r3->val;
        }
        return r1->next=head;
    }
    friend void Merge(List *r1,List *r2,List *r3,int len)
    {
        int i;
        for(i=1;i<=len;i++)
        {
            r1->val=r2->val+r3->val;
            r1=r1->next;
            r2=r2->next;
            r3=r3->next;
        }
    }
};
List* Get_Ring(int x,int &len)
{
    List *head=new List,*last=head;
    int i;
    head->val=x;len=1;
    for(i=x*x%p;i!=x;i=i*i%p)
    {
        last->next=new List;
        last=last->next;
        last->val=i;len++;
    }
    return last->next=head;
}
struct Segtree{
    Segtree *ls,*rs;
    int sum,len,mark;
    List *ring;
    void* operator new (size_t)
    {
        static Segtree mempool[M<<1],*C=mempool;
        return C++;
    }
    void Rotate(int x)
    {
        mark+=x;
        for(x%=len;x;x--)
            ring=ring->next;
        sum=ring->val;
    }
    void Push_Up()
    {
        if(!len&&ls->len&&rs->len)
        {
            len=ls->len*rs->len/__gcd(ls->len,rs->len);
            ring=Merge(ls->ring,rs->ring,len);
        }
        sum=ls->sum+rs->sum;
        Merge(ring,ls->ring,rs->ring,len);
    }
    void Push_Down()
    {
        if(mark)
        {
            ls->Rotate(mark);
            rs->Rotate(mark);
            mark=0;
        }
    }
    void Build_Tree(int x,int y,int a[])
    {
        int mid=x+y>>1;
        if(x==y)
        {
            sum=a[mid];
            if(on_ring[sum])
                ring=Get_Ring(sum,len);
            return ;
        }
        (ls=new Segtree)->Build_Tree(x,mid,a);
        (rs=new Segtree)->Build_Tree(mid+1,y,a);
        Push_Up();
    }
    void Modify(int x,int y,int l,int r)
    {
        int mid=x+y>>1;
        if(x==l&&y==r)
        {
            if(len)
                Rotate(1);
            else if(x==y)
            {
                sum=sum*sum%p;
                if(on_ring[sum])
                    ring=Get_Ring(sum,len);
            }
            else
            {
                ls->Modify(x,mid,l,mid);
                rs->Modify(mid+1,y,mid+1,r);
                Push_Up();
            }
            return ;
        }
        Push_Down();
        if(r<=mid)
            ls->Modify(x,mid,l,r);
        else if(l>mid)
            rs->Modify(mid+1,y,l,r);
        else
            ls->Modify(x,mid,l,mid) , rs->Modify(mid+1,y,mid+1,r) ;
        Push_Up();
    }
    int Get_Ans(int x,int y,int l,int r)
    {
        int mid=x+y>>1;
        if(x==l&&y==r)
            return sum;
        Push_Down();
        if(r<=mid)
            return ls->Get_Ans(x,mid,l,r);
        if(l>mid)
            return rs->Get_Ans(mid+1,y,l,r);
        return ls->Get_Ans(x,mid,l,mid) + rs->Get_Ans(mid+1,y,mid+1,r) ;
    }
}*tree=new Segtree;
void DFS(int x)
{
    if(v[x])
    {
        if(v[x]!=T)
            return ;
        int i=x;
        do{
            on_ring[i]=true;
            i=i*i%p;
        }while(i!=x);
        return ;
    }
    v[x]=T;
    DFS(x*x%p);
}
int main()
{
    #ifdef PoPoQQQ
    freopen("4105.in","r",stdin);
    freopen("4105.out","w",stdout);
    #endif
    static int a[M];
    int i,op,x,y;
    cin>>n>>m>>p;
    for(i=0;i<p;i++)
        if(!v[i])
            ++T,DFS(i);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    tree->Build_Tree(1,n,a);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&op,&x,&y);
        if(op==0)
            tree->Modify(1,n,x,y);
        else
            printf("%d\n",tree->Get_Ans(1,n,x,y));
    }
    return 0;
}
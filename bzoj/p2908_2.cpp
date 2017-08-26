#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 100100
#define rep(i,j,k) for(int i=j;i<k;i++)
using namespace std;

int n,m,k;

namespace Link_Cut_Tree {
    struct data{
        unsigned a[32][2];
        //a[i][j]表示第i位输入为j时的输出
        data() {}
        data(unsigned x) { rep(i,0,k) a[i][0]=1,a[i][1]=x&(1u<<i)?0:1; }
        friend data operator +(const data &x,const data &y) {
            static data z;
            rep(i,0,k)
                z.a[i][0]=y.a[i][x.a[i][0]],
                z.a[i][1]=y.a[i][x.a[i][1]];
            return z;
        }
        unsigned val() {
            unsigned re=0;
            rep(i,0,k) re |= a[i][0] << i;
            return re;
        }
    };
    struct abcd {
        abcd *ls,*rs,*fa;
        data val,sum_l,sum_r;
        bool rev_mark;
        abcd() {
            int i;
            ls=rs=fa=0x0;
            for(i=0;i<32;i++)
            {
                sum_l.a[i][0]=sum_r.a[i][0]=val.a[i][0]=0;
                sum_l.a[i][1]=sum_r.a[i][1]=val.a[i][1]=1;
            }
            rev_mark=false;
        }
        abcd(unsigned int);
        void Push_Up();
        void Push_Down();
        void Reverse();
    }*null=new abcd,*tree[M];
    abcd :: abcd(unsigned int x)
    {
        ls=rs=fa=null;
        sum_l=sum_r=val=data(x);
        rev_mark=false;
    }
    void abcd :: Push_Up()
    {
        sum_l=ls->sum_l+val+rs->sum_l;
        sum_r=rs->sum_r+val+ls->sum_r;
    }
    void abcd :: Push_Down()
    {
        if(fa->ls==this||fa->rs==this)
            fa->Push_Down();
        if(rev_mark)
        {
            ls->Reverse();
            rs->Reverse();
            rev_mark=false;
        }
    }
    void abcd :: Reverse()
    {
        swap(ls,rs);
        swap(sum_l,sum_r);
        rev_mark^=1;
    }
    void Zig(abcd *x)
    {
        abcd *y=x->fa;
        y->ls=x->rs;
        x->rs->fa=y;
        x->rs=y;
        x->fa=y->fa;
        if(y==y->fa->ls)
            y->fa->ls=x;
        else if(y==y->fa->rs)
            y->fa->rs=x;
        y->fa=x;
        y->Push_Up();
    }
    void Zag(abcd *x)
    {
        abcd *y=x->fa;
        y->rs=x->ls;
        x->ls->fa=y;
        x->ls=y;
        x->fa=y->fa;
        if(y==y->fa->ls)
            y->fa->ls=x;
        else if(y==y->fa->rs)
            y->fa->rs=x;
        y->fa=x;
        y->Push_Up();
    }
    void Splay(abcd *x)
    {
        x->Push_Down();
        while(x->fa->ls==x||x->fa->rs==x)
        {
            abcd *y=x->fa,*z=y->fa;
            if(x==y->ls)
            {
                if(y==z->ls)
                    Zig(y);
                Zig(x);
            }
            else
            {
                if(y==z->rs)
                    Zag(y);
                Zag(x);
            }
        }
        x->Push_Up();
    }
    void Access(abcd *x)
    {
        abcd *y=null;
        while(x!=null)
        {
            Splay(x);
            x->rs=y;
            x->Push_Up();
            y=x;x=x->fa;
        }
    }
    void Move_To_Root(abcd *x)
    {
        Access(x);
        Splay(x);
        x->Reverse();
    }
    void Link(abcd *x,abcd *y)
    {
        Move_To_Root(x);
        x->fa=y;
    }
}

int main()
{
    using namespace Link_Cut_Tree;
    int i,x,y;
    unsigned int z;
    char p[10];
    cin>>n>>m>>k;
    rep(i,1,n+1)
    {
        scanf("%u",&z);
        tree[i]=new abcd(z);
    }
    rep(i,1,n)
    {
        scanf("%d%d",&x,&y);
        Link(tree[x],tree[y]);
    }
    rep(i,0,m)
    {
        scanf("%s",p);
        if(p[0]=='Q')
        {
            scanf("%d%d",&x,&y);
            Move_To_Root(tree[x]);
            Access(tree[y]);
            Splay(tree[x]);
            printf("%u\n",tree[x]->sum_l.val());
        }
        else
        {
            scanf("%d%u",&x,&z);
            Splay(tree[x]);
            tree[x]->val=data(z);
            tree[x]->Push_Up();
        }
    }
    return 0;
}
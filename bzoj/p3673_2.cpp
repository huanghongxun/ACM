#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
#define M 200200  
using namespace std;  
struct Tree{  
    Tree *ls,*rs;  
    int num;  
}*fa[M],*siz[M],mempool[M*40],*C=mempool;  
int n,m,now,version[M],tot;  
inline Tree* New_Node(Tree *_,Tree *__,int ___)  
{  
    C->ls=_;  
    C->rs=__;  
    C->num=___;  
    return C++;  
}  
Tree* Modify(Tree *p,int x,int y,int pos,int val)  
{  
    int mid=x+y>>1;  
    if(x==y)  
        return New_Node(0x0,0x0,val);  
    if(pos<=mid)  
        return New_Node(Modify(p->ls,x,mid,pos,val),p->rs,0);  
    else  
        return New_Node(p->ls,Modify(p->rs,mid+1,y,pos,val),0);  
}  
int Access(Tree *p,int x,int y,int pos)  
{  
    int mid=x+y>>1;  
    if(x==y)  
        return p->num;  
    if(pos<=mid)  
        return Access(p->ls,x,mid,pos);  
    else  
        return Access(p->rs,mid+1,y,pos);  
}  
inline int Find(int x)  
{  
    int y;  
    while(x)  
        x=Access(fa[now],1,n,y=x);  
    return y;  
}  
inline void Unite(int x,int y)  
{  
    int fx=Find(x),fy=Find(y);  
    if(fx==fy)  
        return;  
    ++tot;  
    int sx=Access(siz[now],1,n,fx);  
    int sy=Access(siz[now],1,n,fy);  
    if( sx<sy )  
        swap(x,y),swap(fx,fy),swap(sx,sy);  
    fa[tot]=Modify(fa[now],1,n,fy,fx);  
    siz[tot]=Modify(siz[now],1,n,fx,sx+sy);  
    now=tot;  
}  
inline bool Query(int x,int y)  
{  
    return Find(x)==Find(y);  
}  
int main()  
{  
    int i,p,x,y;  
    cin>>n>>m;  
    fa[0]=New_Node(C,C,0);  
    siz[0]=New_Node(C,C,1);  
    for(i=1;i<=m;i++)  
    {  
        scanf("%d",&p);  
        switch(p)  
        {  
            case 1:scanf("%d%d",&x,&y),Unite(x,y);break;  
            case 2:scanf("%d",&x),now=version[x];break;  
            case 3:scanf("%d%d",&x,&y),printf("%d %d\n", Find(x), Find(y));;break;  
        }  
        version[i]=now;  
    }  
}  
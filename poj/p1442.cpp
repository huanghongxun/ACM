//顺序插入数字，动态查询第i大的数，每次查询i递增
//直接暴treap
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

#define MX 30010

struct SBT
{
    int left,right,size,key;
    SBT()
    {
        left=right=0;
        size=1;
    }
} tree[MX];
int tot=0,root=0;
void left_rotate(int &x)//左旋
{
    int y=tree[x].right;
    tree[x].right=tree[y].left;
    tree[y].left=x;
    tree[y].size=tree[x].size;
    tree[x].size=tree[tree[x].left].size+tree[tree[x].right].size+1;
    x=y;
}
void right_rotate(int &x)//右旋
{
    int y=tree[x].left;
    tree[x].left=tree[y].right;
    tree[y].right=x;
    tree[y].size=tree[x].size;
    tree[x].size=tree[tree[x].left].size+tree[tree[x].right].size+1;
    x=y;
}
void maintain(int &x,int flag)
{
    if(flag==0)
    {
        if(tree[tree[tree[x].left].left].size > tree[tree[x].right].size)
           right_rotate(x);
        else if(tree[tree[tree[x].left].right].size > tree[tree[x].right].size)
            left_rotate(tree[x].left),right_rotate(x);
        else return;
    }
    else
    {
        if(tree[tree[tree[x].right].right].size > tree[tree[x].left].size)
            left_rotate(x);
        else if(tree[tree[tree[x].right].left].size > tree[tree[x].left].size)
            right_rotate(tree[x].right),left_rotate(x);
        else return;
    }
    maintain(tree[x].left,0);
    maintain(tree[x].right,1);
    maintain(x,0);
    maintain(x,1);
}
//插入元素，相同元素放在右子树中
void insert(int &x,int key)
{
    if(x==0)
    {
        x=++tot;
        tree[x].key=key;
    }
    else
    {
        tree[x].size++;
        if(key<tree[x].key)insert(tree[x].left,key);
        else insert(tree[x].right,key);
        maintain(x,key>=tree[x].key);
    }
}

int get_Kth(int &x,int k)
{
    if(k<=tree[tree[x].left].size)
       return get_Kth(tree[x].left,k);
    if(k>tree[tree[x].left].size+1)
       return  get_Kth(tree[x].right,k-tree[tree[x].left].size-1);
    return tree[x].key;
}


int n, m;
int s[MX];
int p, c, inc=0;
int main()
{
    c = 0;
    cin>>m>>n;
    for(int i = 0;i < m;i++) {
        cin>>s[i];
    }

    for(int i = 0;i < n;i++)
    {
        cin>>p;
        while(c < p)
            insert(root,s[c++]);
        cout<<get_Kth(root,i+1)<<endl;
    }
    return 0;
}


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#define MAX 20001

using namespace std;

int c,n,ls[MAX];
struct node{
    int l,r;
    int c;
}tree[MAX*4];
struct ln{
    int li,num;//num表示第几张海报
}line[MAX];
int set[MAX][2];
bool visit[MAX];
int ans;

bool cmp(struct ln a,struct ln b){
    return a.li<b.li;
}

void build(int pos,int l,int r){
    tree[pos].l = l;
    tree[pos].r = r;
    tree[pos].c = 0;
    if(l==r) return;
    int mid = (l+r)>>1;
    build(pos*2,l,mid);
    build(pos*2+1,mid+1,r);
}

void update(int pos,int l,int r,int color){
    if(tree[pos].l == l && tree[pos].r == r){
        tree[pos].c = color;
        return;
    }
    if(tree[pos].c > 0 && tree[pos].c != color){
        tree[pos*2].c = tree[pos].c;
        tree[pos*2+1].c = tree[pos].c;
        tree[pos].c = 0;
    }
    int mid = (tree[pos].l + tree[pos].r)>>1;
    if(r<=mid)
        update(pos*2,l,r,color);
    else if(l>mid)
        update(pos*2+1,l,r,color);
    else {
        update(pos*2,l,mid,color);
        update(pos*2+1,mid+1,r,color);
    }
}

void query(int pos){
    if(tree[pos].c!=0){
        if(!visit[tree[pos].c]){//tree[pos].c
            visit[tree[pos].c] = true;
            ans++;
        }
        return;
    }
    query(2*pos);
    query(2*pos+1);
}

int main()
{
    int i;
    while(scanf("%d",&c)!=EOF){
        while(c--){
            scanf("%d",&n);
            for(i = 0;i < n;++i){//离散化
                scanf("%d%d",&set[i][0],&set[i][1]);
                line[2*i].li = set[i][0];
                line[2*i].num = -(i+1);//用负数表示 线段起点
                line[2*i+1].li = set[i][1];
                line[2*i+1].num = i+1;
            }
            sort(line,line+2*n,cmp);
            int temp = line[0].li,tp = 1;
            for(i = 0;i < 2*n;++i){
                if(line[i].li != temp){
                    tp++;
                    temp = line[i].li;
                }
                if(line[i].num < 0){
                    set[-line[i].num-1][0] = tp;
                }
                else{
                    set[line[i].num-1][1] = tp;
                }
            }//离散化
        
            build(1,1,tp);
            for(i = 0;i < n;++i){
                update(1,set[i][0],set[i][1],i+1);
            }
            memset(visit,0,sizeof(visit));
            ans = 0;
            query(1);
            printf("%d\n",ans);
        }
    }
    return 0;
}

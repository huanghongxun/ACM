#include <cstdio>
#include <iostream>
using namespace std;
int n;
void paste(int num[],int a,int b,int c) {
    int tmp[n];
    int i, len = b - a + 1;
    /*for (i=a;i<=n;i++)
    {
        result[i]=num[i];
        num[i]=num[i+b-a];
    }*/
    if(c<a) {
        for (i=c+1;i<a;i++)
            tmp[i]=num[i];
        for (i=1;i<=len;i++)
            num[c+i]=num[c+i+len-1];
        for (i=c+1;i<a;i++)
            num[i+len]=tmp[i];
    } else if(c > b) {
        for (i=b+1;i<c;i++)
            tmp[i]=num[i];
        for (i=len;i>=1;i--)
            num[a+c-b-1+i]=num[b-len+1];
        for (i=a;i<a+c-b;i++)
            num[i]=tmp[b+i];
    }
}

int main()
{
    int k,a,b,c;
    scanf("%d %d",&n,&k);
    int ans[n*2+1];
    for (int i=1;i<=n;i++)
        ans[i]=i;
    for (int i=1;i<=k;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        paste(ans,a,b,c);
    }
    
    for (int i=1;i<=10;i++)
        cout<<ans[i]<<endl;
    return 0;
}
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int ans[10001];
int main() {
    int R = 0, L = 0x7fffffff, l, h, r;
    memset(ans,0,sizeof(ans));
    while(scanf("%d%d%d", &l, &h, &r) == 3)
    {
        R=max(R,r);
        L=min(L,l);
        for(int i=l;i<r;i++)
        {
            if(ans[i]<h)
                ans[i]=h;
        }
    }
    for(int i=L;i<R;i++)
        if(ans[i]!=ans[i-1])
                cout<<i<<" "<<ans[i]<<" ";
    cout<<R<<" "<<0<<endl;
    return 0;
}
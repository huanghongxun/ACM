#include <iostream>
using namespace std;
int main()
{
    int ys[12];
    cin>>ys[0]>>ys[1]>>ys[2]>>ys[3]>>ys[4]>>ys[5]>>ys[6]>>ys[7]>>ys[8]>>ys[9]>>ys[10]>>ys[11];
    int money[12]={300,300,300,300,300,300,300,300,300,300,300,300};
    int save=0,i,monthsave=0;
    for(i=0;i<12;i++)
    {
        if(i>0)money[i]+=money[i-1];
        if(money[i]<ys[i])
        {
            cout<<'-'<<i+1;
            return 0;
        }
        monthsave=(money[i]-ys[i])/100*100;
        save+=monthsave;
        money[i]-=ys[i]+monthsave;
        monthsave=0;
    }
    cout<<1.2*save+money[11];
    return 0;
}
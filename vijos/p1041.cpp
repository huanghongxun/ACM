#include <iostream>
using namespace std;
int main()
{
    int i;
    float p,q;
    cin>>p>>q;
    p=p/100; 
    q=q/100; 
    for(i=1;i<=32767;i++)
    {
        if(int(q*i-0.000001)-int(p*i+0.000001)>=1) 
        {
            cout<<i;
            break;
        }
    }
    return 0;
}
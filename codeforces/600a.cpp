#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#define INF 2147483647
#define random(x) rand()%x
#define ll long long
#define ull unsigned long long
using namespace std;
    string s,tmp,emp;
    int len,i,al,bl;
    bool sz;
    string a[100010];
    string b[100010];
int main()
{
    cin>>s;
    len=s.size();
    sz=true;
    for (i=0;i<=len-1;i++)
    {
        if (s[i]==','||s[i]==';') 
        {
            if ((sz&&tmp[0]!='0'&&tmp!=emp)||(tmp=="0")) a[++al]=tmp;
            else b[++bl]=tmp;
            tmp=emp;sz=true;
        }
        else 
        {
            if (s[i]<'0'||s[i]>'9') sz=false; 
            tmp=tmp+s[i];
        }
    }
    if ((sz&tmp[0]!='0'&&tmp!=emp)||(tmp=="0")) a[++al]=tmp;
    else b[++bl]=tmp;
    tmp=emp;sz=true;
    if (al==0) cout<<"-\n"; else
    {
        cout<<'"';
        for (i=1;i<=al;i++)
        {
            if (i>1) cout<<',';
            cout<<a[i];
        }
        cout<<'"'<<'\n';
    }
    if (bl==0) cout<<"-\n"; else
    {
        cout<<'"';
        for (i=1;i<=bl;i++)
        {
            if (i>1) cout<<',';
            cout<<b[i];
        }
        cout<<'"'<<'\n';
    }
    return 0;
}
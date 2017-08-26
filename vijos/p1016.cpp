#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;
int a[10],b[10][10]={{0,0,0,0,0,0,0,0,0,0},
                     {0,1,1,0,1,1,0,0,0,0},
                     {0,1,1,1,0,0,0,0,0,0},
                     {0,0,1,1,0,1,1,0,0,0},
                     {0,1,0,0,1,0,0,1,0,0},
                     {0,0,1,0,1,1,1,0,1,0},
                     {0,0,0,1,0,0,1,0,0,1},
                     {0,0,0,0,1,1,0,1,1,0},
                     {0,0,0,0,0,0,0,1,1,1},
                     {0,0,0,0,0,1,1,0,1,1}},s=0,m=1000000,c[10],d[10],e[10];
void find() {
    for(c[1]=0;c[1]<=3;c[1]++)
      for(c[2]=0;c[2]<=3;c[2]++)
        for(c[3]=0;c[3]<=3;c[3]++)
          for(c[4]=0;c[4]<=3;c[4]++)
            for(c[5]=0;c[5]<=3;c[5]++)
              for(c[6]=0;c[6]<=3;c[6]++)
                for(c[7]=0;c[7]<=3;c[7]++)
                  for(c[8]=0;c[8]<=3;c[8]++)
                    for(c[9]=0;c[9]<=3;c[9]++)
                    {
                        bool flag=true;
                        for (int i=1; i<=9; i++) a[i]=d[i];
                        for (int i=1; i<=9; i++)
                        {
                            for (int j=1; j<=9; j++) a[i]+=c[j]*b[j][i];
                            a[i]%=4;
                            if (a[i]!=0) {flag=false; break;} 
                        }
                        if (flag)
                        {
                            int ss=0;
                            for (int i=1; i<=9; i++) ss+=c[i];
                            if (ss<m) ss=m;
                            for(int i=1; i<=9; i++) e[i]=c[i];
                        }
                    }
}
int main() {
    for(int i=1; i<=9; i++) {
        cin>>a[i];
        d[i]=a[i]; 
    }
    find();
    bool flag=false;
    for(int i=1;i<=9;i++)
        for(int j=1; j<=e[i]; j++)
        {
            if(flag) cout<<" "; else flag=true;
            cout<<i;
        }
    return 0;
}
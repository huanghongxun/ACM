#include<iostream>
#include<cstring>
using namespace std;
int a[101][101],b[101];
int dp(int a[],int n)
{
    int sum = 0,max = 0;
    for (int i=0; i<n; i++)
    {
        sum += a[i];
        if (sum < 0)sum = 0;
        if (sum > max)max = sum;
    }
    return max;
}
int main()
{
    int i,j,n;
    while (cin >> n)
    {
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                cin >> a[i][j];
        int sum=0,max = 0;
        for (i=0; i<n; i++)
            for (j=i; j<n; j++)
            {
                memset(b,0,sizeof(b));
                for (int z=0; z<n; z++)
                    for (int k=i; k<=j; k++)
                        b[z] += a[k][z];
                sum = dp(b,n);
                if (max < sum)max = sum;
            }
        cout << max << endl;
    }
    return 0;
}      
#include <iostream>  
#include <algorithm>  
#include <cstring>  
#include <cstdio>  
#include <string>  
#include <queue>  
#define INF 0x3f3f3f3f  
#define MAX_N 100  
  
using namespace std;  
  
int num[MAX_N];  
int dp[MAX_N][MAX_N];  
  
int main()  
{  
    int n;  
    cin >> n;  
    for(int i = 1;i <= n;i++)  
    {  
        int k;  
        cin >> k;  
        num[k] = i;          //  按照给的顺序排列下  
    }  
        printf("num:");
        for (int i = 1;i<=n;++i)printf("%d ", num[i]);
            putchar('\n');
    int a[MAX_N];  
    int c;  
    memset(dp,0,sizeof(dp));  
    while(cin >> c)  
    {  
        a[c] = 1;  
        for(int i = 2;i <= n;i++)  
        {  
            cin >> c;  
            a[c] = i;             //   按照给的顺序排列下  
        }  
        printf("a:");
        for (int i = 1;i<=n;++i)printf("%d ", a[i]);
            putchar('\n');
        for(int i = 1;i <= n;i++)        // dp求最长公共子序列  
        {  
            for(int j = 1;j <= n;j++)  
            {  
                if(num[i] == a[j])  
                {  
                    dp[i + 1][j + 1] = dp[i][j] + 1;  
                }  
                else  
                dp[i + 1][j + 1] = max(dp[i][j + 1],dp[i + 1][j]);  
            }  
        }  
        cout << dp[n + 1][n + 1] << endl;  
    }  
    return 0;  
}  
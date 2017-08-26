#include <cstdio>
#define rep(i,j,k) for(int i=j;i<k;i++)
const int mod = 10000;  
struct Matrix {  
    int v[2][2];  
    Matrix(int x = 0) { rep(i,0,2)rep(j,0,2)v[i][j]=0;rep(i,0,2) v[i][i] = x; }  
    int *operator [](int x) { return v[x]; }  
    friend Matrix operator *(Matrix a, Matrix b){  
        Matrix c;  
        rep(i,0,2) rep(j,0,2) rep(k,0,2)  
            c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;  
        return c;  
    }  
    friend Matrix operator ^(Matrix a, int n){  
        Matrix ans(1);  
        for (; n; n >>= 1, a = a * a)  
            if (n & 1) ans = ans * a;  
        return ans;  
    }
} b;
int main() {  
    b[0][0]=b[0][1]=b[1][0]=1; int n;
    while(scanf("%d", &n)!=EOF&&n!=-1)
        if(n==0)puts("0");else
        printf("%d\n", (b^(n-1))[0][0]);
    return 0;  
}  
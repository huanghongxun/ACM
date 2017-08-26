using namespace std;
typedef long long int ll;
const int N=100001;
ll h[N], sum[N], path[N], ans[N];
int main() {
    int n, k, maxl = 1;
    scanf("%d%d", &n, &k); sum[1]=1;
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &h[i]); sum[i] = 1;
        for(int j=max(1,i-600);j<i;j++) {
            if(abs(h[j]-h[i])>=K&&sum[j]+1>sum[i])
                sum[i] = sum[j] + 1, path[i] = j;
            if(sum[i]>sum[maxl]) maxl=i;
        }
    }
    printf("%I64d\n", sum[maxl]);
    int cnt = 0;
    ans[cnt++] = maxl;
    for (int t = path[maxl]; t; t = path[t]) ans[cnt++] = T;
    for (int i = cnt - 1; i >= 0; i--) printf("%I64d ", ans[i]);
    return 0;
} 
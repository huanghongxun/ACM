#include <cstdio>
#define FOR(i,j,k) for(int i=j;i<=k;++i)
#define abs(i) ((i)>0?(i):-(i))
const int N = 32;
int arr[N];

bool equals(int *arr, int n) {
    FOR(i,2,n)
        if (arr[i] != arr[1])
            return false;
    return true;
}

int main() {
    for (int kase = 1, n; scanf("%d", &n), n; ++kase) {
        FOR(i,1,n) scanf("%d", &arr[i]);

        FOR(ans,0,1000) {
            if (equals(arr, n)) {
                printf("Case %d: %d iterations\n", kase, ans);
                goto end;
            }

            arr[n + 1] = arr[1];
            FOR(i,1,n) arr[i] = abs(arr[i] - arr[i + 1]);
        }
        printf("Case %d: not attained\n", kase);
end:    continue;
    }
    return 0;
}
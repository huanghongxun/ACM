#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1024;
int l[N], r[N], sum, ans;

bool dfs(int s) {
    int val; bool flag = true;
    while (getchar() != '(');
    if (scanf("%d", &val) == 1) {
        bool l = dfs(s + val);
        bool r = dfs(s + val);
        if (!l && !r && s + val == sum)
            ans = true;
    } else flag = false;
    while (getchar() != ')');
    return flag;
}

int main() {
    while (scanf("%d", &sum) != EOF) {
        ans = false;
        dfs(0);
        puts(ans ? "yes" : "no");
    }
    return 0;
}
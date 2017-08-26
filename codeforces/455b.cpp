#include <cstdio>
#include <cstring>

struct Trie {
    int ch[100001][26];
    int cnt;
    Trie() { memset (ch[0], 0, sizeof ch[0]); cnt = 1;}
    void insert(const char *s) {
        int n = strlen(s), u = 0;
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if(!ch[u][c]) {
                memset(ch[cnt], 0, sizeof ch[cnt]);
                ch[u][c] = cnt++;
            }
            u = ch[u][c];
        }
    }
    int dfs(int u) {
        bool leaf = 1;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if(ch[u][i]) {
                leaf = 0;
                ans |= 3 - dfs(ch[u][i]);
            }
        }
        if (leaf) ans = 1;
        return ans;
    }
} trie;
int main(){
    static char str[1000];
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; i++) {
        scanf("%s", str); trie.insert(str);
    }
    int ans = trie.dfs(0);
    if(ans < 2) puts("Second");
    else if(ans == 2) puts(k & 1 ? "First" : "Second");
    else puts("First");
    return 0;
}
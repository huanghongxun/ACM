#include <cstdio>
#include <cstring>
int idx[256];
char pattern[30][30];
double p[256];
int n;
struct ACAutomaton {
    struct Node {
        int cnt, val;
        Node *ch[64], *fail, *last;
        double dp[105];
        bool vis[105];
        void init() {
            cnt=val=0;fail=last=0;for(int i=0;i<n;i++) ch[i]=0;
            memset(vis, 0, sizeof vis);
        }
    } *root, *q[4096], pool[1024];
    int pool_used;

    void init() {
        root = &pool[0];
        pool_used = 1;
    }

    void createNode(Node *&a) {
        a = &pool[pool_used ++];
        a->init();
    }

    void insert(char *w) {
        int len=strlen(w);
        Node *p=root;
        for(int i=0;i<len;i++) {
            int j=idx[w[i]];
            if(!p->ch[j])
                createNode(p->ch[j]);
            p = p->ch[j];
        }
        p->cnt++;
        p->val = 1;
    }

    void build() {
        int f = 0, r = 0;
        q[r ++] = root;
        while (f < r) {
            Node *x = q[f++];
            for(int i=0;i<n;i++)
                if(x->ch[i]) {
                    Node *u = x->ch[i];
                    if(u==root) u->fail=root;
                    else {
                        Node *p=x->fail;
                        for(; p; p = p->fail) {
                            if(p->ch[i]) {
                                u->fail=p->ch[i];
                                break;
                            }
                        }
                        if(!p) u->fail = root;
                    }
                    u->val |= u->fail->val;
                    q[r++] = u;
                }
        }
    }

    double dp(Node *u, int l) {
        if (l == 0) return 1;
        if (u->vis[l]) return u->dp[l];
        u->vis[l] = true;

        double &ans = u->dp[l];
        ans = 0;
        for (int i = 0; i < n; i ++)
            if (u->ch[i] && !u->ch[i]->val)
                ans += p[i] * dp(u->ch[i], l - 1);
        return ans;
    }
} ac;

int main() {
    int kase, k;
    scanf("%d", &kase);
    for (int num = 1; num <= kase; num ++) {
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
            scanf("%s", pattern[i]);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            char ch[2];
            scanf("%s %lf", ch, &p[i]);
            idx[ch[0]] = i;
        }
        ac.init();
        for (int i = 0; i < k; i++)
            ac.insert(pattern[i]);
        ac.build();
        scanf("%d", &k);
        printf("Case #%d: %.6lf\n", num, ac.dp(ac.root, k));
    }
}

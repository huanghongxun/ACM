#include <cstdio>
#include <cstring>
#define kind 26
const int N = 10000000;

int read() {
    int s=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
    return s*f;
}

struct ACAutomaton {
    struct Node {
        int cnt;
        Node *ch[26], *fail;
        Node() {
            cnt=0;fail=0;for(int i=0;i<26;i++) ch[i]=0;
        }
    } *root, *q[N];
    void insert(char *w) {
        int len=strlen(w);
        Node *p=root;
        for(int i=0;i<len;i++) {
            int j=w[i]-'a';
            if(!p->ch[j])
                p->ch[j] = new Node;
            p = p->ch[j];
        }
        p->cnt++;
    }
    void build() {
        int f=0,r=0;
        q[r++]=root;
        while(f<r) {
            Node *u = q[f++];
            for(int i=0;i<26;i++)
                if(u->ch[i]) {
                    if(u==root) u->ch[i]->fail=root;
                    else {
                        Node *p=u->fail;
                        for(; p; p = p->fail) {
                            if(p->ch[i]) {
                                u->ch[i]->fail=p->ch[i];
                                break;
                            }
                        }
                        if(!p) u->ch[i]->fail = root;
                    }
                    q[r++] = u->ch[i];
                }
        }
    }
    int query(char *w) {
        int len=strlen(w), ans=0;
        Node *p = root;
        for(int i=0;i<len;i++) {
            int j=w[i]-'a';
            while(!p->ch[j]&&p!=root) p=p->fail;
            p=p->ch[j];
            if(!p) p=root;
            Node *t=p;
            while(t!=root) {
                if(t->cnt) {
                    ans+=t->cnt;
                    t->cnt=0;
                } else break;
                t = t->fail;
            }
        }
        return ans;
    }
    void init() {
        root = new Node;
    }
} ac;
char str[N];
int main()
{
    int i,t=read(),n,ans;
    while(t--) {
        n=read();
        ac.init();
        for(i=0;i<n;i++) {
            scanf("%s", str);
            ac.insert(str);
        }
        ac.build();
        scanf("%s", str);
        printf("%d\n",ac.query(str));
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

struct SuffixAutomaton {
    struct Node {
        Node *parent, *ch[27];
        int len;
        Node() {parent=0;memset(ch,0,sizeof(ch));}
    } *root, *tail;
    
    void add(char c, int len) {
        Node *p = tail, *np = new Node;
        np->len = len;
        // 更新所有后缀，
        for(; p && !p->ch[c]; p = p->parent) p->ch[c] = np;
        tail = np;
        if (!p) np->parent = root;
        else
            if (p->ch[c]->len == p->len + 1) np->parent = p->ch[c];
            else {
                // 新转移已存在，由于不能破坏原来的转移，所以需要建立新节点
                Node *q = p->ch[c], *r = new Node;
                *r = *q;
                r->len = p->len + 1;
                q->parent = np->parent = r;
                // 将源接受态的节点改为指向新节点 
                for(; p && p->ch[c] == q; p = p->parent) p->ch[c] = r;
            }
    }

    void dfs() {
        
    }
    
    SuffixAutomaton(string s) {
        root = tail = new Node;
        root->len = 0;
        for(int i=0;i<s.length();i++)
            add(s[i]-'a',i+1);
    }
};

int main() {
    string s;
    int n;
    cin>>n>>s;
    SuffixAutomaton *sam = new SuffixAutomaton(s);


    return 0;
}
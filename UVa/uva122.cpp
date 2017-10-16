#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int N = 100005;

int l[N], r[N], vis[N], val[N];
int id; bool failed;

void add_node(int &t, int v, char *s) {
    if (t == 0) t = ++id;
    if (*s == 0 || *s == ')') {
        if (vis[t]) {
            failed = true;
        } else {
            val[t] = v;
            vis[t] = 1;
        }
        return;
    }
    if (*s == 'L') add_node(l[t], v, s + 1);
    else if (*s == 'R') add_node(r[t], v, s + 1);
}

vector<int> *bfs(int root) {
    vector<int> *res = new vector<int>();
    queue<int> q;
    q.push(root);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (!vis[u]) {
            delete res;
            return NULL;
        }
        res->push_back(val[u]);
        if (l[u]) q.push(l[u]);
        if (r[u]) q.push(r[u]);
    }
    return res;
}

int main() {
    static char node_descriptor[N], location_descriptor[N];
    int value, i, root;
    while (true) {
        id = 1; root = 0; failed = false;
        memset(vis, 0, sizeof vis);
        memset(l, 0, sizeof l);
        memset(r, 0, sizeof r);
        while (true) {
            if (scanf("%s", node_descriptor) != 1) return 0;
            if (node_descriptor[1] == ')') break;
            sscanf(node_descriptor, "(%d,%s", &value, location_descriptor);
            add_node(root, value, location_descriptor);
        }
        vector<int> *res = bfs(root);
        if (res != NULL && !failed) {
            if (res->size() > 0)
                printf("%d", (*res)[0]);
            for (i = 1; i < res->size(); ++i)
                printf(" %d", (*res)[i]);
            putchar('\n');
        } else {
            printf("not complete\n");
        }
    }
    return 0;
}
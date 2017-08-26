#include <cstdio>
const int maxn = 2e4 + 5;

int n, m, p, a[maxn], b[maxn], go[maxn], rev[maxn], res[maxn];

inline int f(int x, int y) {
    return (a[x] + b[y]) % p;
}

void cgo(int b, int e, int l, int r) {
    go[l] = 0;
    for (int i = l + 1; i <= r; i++) {
        go[i] = -1;
    }
    for (int i = b; i <= e; i++) {
        go[l] += f(i, l);
        for (int j = l + 1; j <= r; j++) {
            if (go[j - 1] > go[j]) {
                go[j] = go[j - 1];
            }
            go[j] += f(i, j);
        }
    }
}

void crev(int b, int e, int l, int r) {
    rev[r] = 0;
    for (int i = r - 1; i >= l; i--) {
        rev[i] = -1;
    }
    for (int i = e; i >= b; i--) {
        rev[r] += f(i, r);
        for (int j = r - 1; j >= l; j--) {
            if (rev[j + 1] > rev[j]) {
                rev[j] = rev[j + 1];
            }
            rev[j] += f(i, j);
        }
    }
}

void solve(int b, int e, int l, int r) {
    if (e < b) {
        return;
    } else if (b == e) {
        res[b] = l;
        return;
    } else if (l == r) {
        for (int i = b; i <= e; i++) {
            res[i] = l;
        }
        return;
    }
    int mid = (b + e) / 2;
    cgo(b, mid, l, r);
    crev(mid + 1, e, l, r);
    int mxl = -1, cl = -1, mx = -1, xl = -1, xr = -1;
    for (int i = l; i <= r; i++) {
        if (go[i] > mxl + f(mid, i)) {
            mxl = go[i];
            cl = i;
        } else {
            mxl += f(mid, i);
        }
        if (mxl + rev[i] > mx) {
            mx = mxl + rev[i];
            xl = cl;
            xr = i;
        }
    }
    res[mid] = xl;
    solve(b, mid - 1, l, xl);
    solve(mid + 1, e, xr, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];    
    }
    solve(0, n - 1, 0, m - 1);
    res[n] = m - 1;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = res[i]; j <= res[i + 1]; j++) {
            tot += f(i, j);
        }
    }
    cout << tot << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = res[i]; j < res[i + 1]; j++) {
            cout << 'S';
        }
        if (i < n - 1) {
            cout << 'C';
        }
    }
    cout << '\n';
    return 0;
}

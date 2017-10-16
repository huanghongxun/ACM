#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;
int d[1024], d2[1024];
int main() {
    int sz, n, i, j, bottom;
    string s;
    while (getline(cin, s)) {
        cout<<s<<endl;
        stringstream ss;
        ss<<s; sz = 0;
        for (n = 1; ss>>d[n]; ++n) sz = max(sz, d[n]); --n;

        bottom = n;
        memcpy(d2, d, sizeof d);
        sort(d2 + 1, d2 + n + 1);
        for (i = n; i > 1; --i) {
            for (j = i; d[j] != d2[i]; --j);
            if (i == j) continue;

            if (j != 1) {
                reverse(d + 1, d + j + 1);
                cout<<n - j + 1<<' ';
            }

            reverse(d + 1, d + i + 1);
            cout<<n - i + 1<<' ';
        }
        cout<<0<<endl;
    }

    return 0;
}
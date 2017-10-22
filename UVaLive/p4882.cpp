#include <cstdio>
#include <exception>
using namespace std;

#define FOR(i,j,k) for(i=j;i<=k;++i)
int sk[N], level[N], del[N];
char str[N];

// upperLevel: 2 - multiplication, 1 - addition, 0 - none
int process(int l, int r, int dep, int upperLevel) {
    bool parenthesis = false;
    int operation = 0;
    int i;
    if (l == r) return 0;

    if (str[l] == '(' && str[r] == ')') {
        parenthesis = true;
        // redundant nested parenthesis.
        if (r - l + 1 > 4 &&  && str[l + 1] == '(' && str[r - 1] == ')') {
            del[l] = del[r] = 1;
            return process(l + 1, r - 1, upperLevel);
        }
    }

    if (isalpha(str[l]) && str[l + 1] != '+') // multiplication, a(...) or ab
        subl = l + 1, subr = r, operation = 2;
    else if (isalpha(str[r]) && str[r - 1] != '+') // multiplication, (...)a
        subl = l, subr = r - 1, operation = 2;
    else {
        FOR(i,l,r) if (level[i] == dep) { // addition
            operation = 1; break;
        }
        if (operation == 0)
            throw exception("Cannot detect operation");
    }
}

int main() {
    int i, top;
    while (scanf("%s", s + 1) != EOF) {
        len = strlen(s + 1);

        FOR(i,1,len)
            if (s[i] == '(') sk[++top] = i;
            else if (s[i] == ')') next[sk[top--]] = i;
        
        s[0] = s[len + 1] = '+';
        FOR(i,1,len) {
            if (s[i] != '(') continue;
            int id = i - 1;
            while ()
        }
    }

    return 0;
}
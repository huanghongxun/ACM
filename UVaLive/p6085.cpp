// UVALive 6085 
#include <cstdio>
#include <cctype>
#include <cstring>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
#define foreach(it,c) for(auto it=c.begin();it!=c.end();++it)

// M - a molecule describer
// G - dense radical
// S - a partly radical
// C - a number >= 2 (1 can be omitted)
// E - a number that can have leading zero
// T - 2~9
// N - 1~9
// D - 0~9
// A - A chemical element, like P, Na, Uuv
// U - uppercase letters
// L - lowercase letters

const int N = 128;

int partner[N];

string substring(char *str, int beginIndex, int length) {
    stringstream ss;
    string res;
    for (int i = beginIndex; i < beginIndex + length; ++i)
        ss << str[i];
    ss >> res;
    return res;
}

// Returning the word length, 0 if not a right position.
int findElement(char *str, int beginIndex) {
    int i;
    if (str[beginIndex] < 'A' || str[beginIndex] > 'Z')
        return 0;
    for (i = beginIndex + 1; str[i]; ++i)
        if (str[i] < 'a' || str[i] > 'z')
            break;
    return i - beginIndex;
}

int findDigit(char *str, int beginIndex) {
    int i, res = 0;
    for (i = beginIndex; str[i] != 0 && isdigit(str[i]); ++i)
        res = res * 10 + str[i] - '0';
    return res;
}

void scanParenthesis(char *str) {
    static int sk[N];
    int top = 1, i;
    for (i = 0; str[i]; ++i) {
        if (str[i] == '(') sk[++top] = i;
        else if (str[i] == ')') partner[sk[top--]] = i;
    }
}

// Returning a map(hash -> count)
void work(map<string, int> &res, char *str, int len, int from, int to, int mul = 1) {
    if (from > to) return;
    for (int i = from; i <= to; ) {
        if (str[i] == '(') {
            int m = 1;
            if (isdigit(str[partner[i] + 1]))
                m = findDigit(str, partner[i] + 1);
            work(res, str, len, i + 1, partner[i] - 1, mul * m);
            i = partner[i] + 1;
        } else {
            int e = findElement(str, i);
            if (e == 0) { // not a valid element description.
                ++i;
                continue;
            }
            // check the subscript
            int cnt = 1;
            if (i + e < len && isdigit(str[i + e]))
                cnt = findDigit(str, i + e);
            res[substring(str, i, e)] += mul * cnt;
            i += e;
        }
    }
}

int main() {
    static char str[N];
    static pair<string, int> pairs[N];
    while (scanf("%s", str) != EOF) {
        scanParenthesis(str);

        int len = strlen(str), tot = 0;
        map<string, int> res;
        work(res, str, strlen(str), 0, len - 1);

        foreach(it, res) {
            if (it != res.begin())
                putchar('+');
            if (it->second > 1)
                printf("%d", it->second);
            printf("%s", it->first.c_str());
        }
        putchar('\n');
    }
    return 0;
}
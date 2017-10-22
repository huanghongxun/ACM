// HDU 3781, UVALive 4890
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

string ord[1001] = {
    "",
    "first",
    "second",
    "third",
    "fourth",
    "fifth",
    "sixth",
    "seventh",
    "eighth",
    "ninth",
    "tenth",
    "eleventh",
    "twelfth",
    "thirteenth",
    "fourteenth",
    "fifteenth",
    "sixteenth",
    "seventeenth",
    "eighteenth",
    "nineteenth",
    "twentieth"
};

string num[1001] = {
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
    "twenty"
};

// val < 1000
string showNum(int val) {
    string res;
    if (val >= 100) {
        res += num[val / 100] + num[100];
        val %= 100;
    }
    if (val >= 20) {
        res += num[val - val % 10];
        res += num[val % 10];
        return res;
    }
    return res + num[val];
}

// val < 1000000
string showOrd(int val) {
    string res;
    if (val >= 1000) {
        res += showNum(val / 1000);
        if (val % 1000 == 0) return res + ord[1000];
        res += num[1000];
        val %= 1000;
    }
    if (val >= 100) {
        res += showNum(val / 100);
        if (val % 100 == 0) return res + ord[100];
        res += num[100];
        val %= 100;
    }
    if (val >= 20) {
        if (val % 10 == 0) return res += ord[val];
        res += showNum(val - val % 10);
        return res + ord[val % 10];
    } else
        return res + ord[val];
}

void init() {
    ord[30] = "thirtieth";      num[30] = "thirty";
    ord[40] = "fortieth";       num[40] = "forty";
    ord[50] = "fiftieth";       num[50] = "fifty";
    ord[60] = "sixtieth";       num[60] = "sixty";
    ord[70] = "seventieth";     num[70] = "seventy";
    ord[80] = "eightieth";      num[80] = "eighty";
    ord[90] = "ninetieth";      num[90] = "ninety";
    ord[100] = "hundredth";     num[100] = "hundred";
    ord[1000] = "thousandth";   num[1000] = "thousand";
}

int countT(string s) {
    int cnt = 0;
    for (auto c : s)
        if (c == 't')
            ++cnt;
    return cnt;
}

int seq[131072];
void bfs() {
    int sum = 5, now = 11, cnt = 3;
    seq[1] = 1;
    seq[2] = 4;
    seq[3] = 11;
    queue<string> q;
    q.push(showOrd(4));
    q.push(showOrd(11));
    while (!q.empty()) {
        string str = q.front();
        q.pop();
        for (auto c : str) {
            ++now;
            if (c == 't') {
                seq[++cnt] = now;
                string ord = showOrd(now);
                if (sum < 100000)
                    q.push(ord);
                sum += countT(ord);
            }
        }
    }
}

int main() {
    int n;
    init();
    bfs();
    while (scanf("%d",&n) == 1 && n != 0)
        printf("%d\n", seq[n]);
    return 0;
}
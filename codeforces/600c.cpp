#include <cstdio>
#include <cstring>
int main() {
    int i, j, k, len, s[26]={0}, w[26]={0}, wc = 0;
    static char str[2000001];
    scanf("%s", str + 1);
    len = strlen(str + 1);
    for (i = 1; i <= len; i++)
        s[str[i] - 'a']++;
    for (i = 0; i < 26; i++)
        if (s[i] & 1) w[++wc] = i;
    for (i = 1, j = wc; i < j; i++, j--)
        s[w[j]]--, s[w[i]]++;
    if (wc & 1)
        str[len / 2 + 1] = w[wc / 2 + 1] + 'a';
    for (i = 1, j = len, k = 0; i <= j; i++, j--)
        for (; k < 26; k++)
            if (s[k] > 1) { s[k] -= 2; str[i] = str[j] = k + 'a'; break; }
    
    printf("%s", str + 1);
    return 0;
}
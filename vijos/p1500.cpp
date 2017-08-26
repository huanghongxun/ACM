#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 255;
char dic[27];
int opt,n;
int pos(char sch){
    for (int i=0;i<26;i++) {
        if (dic[i]==sch) return i;
    }
}
int min(const int &egA, const int &egB) {
    return egA>egB ? egB : egA;
}
struct String {
    char w[MAXN]; int len;
    bool operator > (const String &b) const {
        for (int i=0;i<min(b.len,len);i++){
            int t1 = pos(w[i]),t2=pos(b.w[i]);
            if (t1<t2)
                return true;
            else if (t1>t2)
                return false;
        }   
        return b.len>len;
    }
} word[1001];
bool com2(const String &a, const String &b){
    return b>a;
}
bool com1(const String &a, const String &b){
    return a>b;
}
int main(){
    scanf("%s",dic);
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%s",word[i].w);
        word[i].len = strlen(word[i].w);
    }
    scanf("%d",&opt);
    if (opt==1)
        std::sort(word,word+n,com1);
    else 
        std::sort(word,word+n,com2);

    for (int i=0;i<n;i++)
        printf("%s\n",word[i].w);
    return 0;
}
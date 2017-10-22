//UVALive 5739
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

map<string, int> v;
char s[88];
int cs;
char tmp[88];
int maxlen,n;
int main() {
    int kase = 0;
    while (scanf("%d %d",&n,&maxlen) == 2) {
        kase++;
        if (n==0&&maxlen==0) break;
        printf("Case %d\n", kase);
        v.clear();
        int ct = 0;
        char re;
        for (int k=0;k<n;k++)
        {
            scanf("%s",tmp);
            cs = 0;
            re = getchar();
            int i=0;
            while(i<strlen(tmp))
            {
                if (tmp[i]>='A'&&tmp[i]<='Z')
                {
                    s[cs++] = tmp[i]-'A'+'a';
                    break;
                }else
                if (tmp[i]>='a'&&tmp[i]<='z')
                {
                    s[cs++] = tmp[i];
                    break;
                }
                i++;
            }
            scanf("%s",tmp);
            re = getchar();
            while (re!='\n')
            {
                scanf("%s",tmp);
                re = getchar();
            }
            i=0;
            while(i<strlen(tmp)&&cs<maxlen)
            {
                if (tmp[i]>='A'&&tmp[i]<='Z')
                {
                    s[cs++] = tmp[i]-'A'+'a';
                }else
                if (tmp[i]>='a'&&tmp[i]<='z')
                {
                    s[cs++] = tmp[i];
                }
                i++;
            }
            s[cs] = '\0';
            string toj (s);
            int no = 0;
            char num[255];
            while(v[toj]==1)
            {
                no++;
                if (no==1&&cs==maxlen)
                    s[cs-1]='\0';
                if (no==10)
                {
                    if (cs==maxlen)
                        s[cs-2]='\0';
                    if (cs==(maxlen-1))
                        s[cs-1]='\0';
                }
                sprintf(num, "%d", no);
                toj = s;
                toj += num;
            }
            v[toj]++;
            printf("%s\n",toj.c_str());
        }

    }
    return 0;
}

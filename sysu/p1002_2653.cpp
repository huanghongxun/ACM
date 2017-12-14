#include <stdio.h>
#include <string.h>

char buf[1024];

int main() {
    char ch;

    while (true) {
        while (true) {
            ch = getchar();
            if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r');
            else
                break;
        }
        if (ch == EOF) break;
        ungetc(ch, stdin);
        scanf("%s", buf);
        if (strcmp(buf, "tailmon") == 0)
            printf("angewomon ");
        else
            printf("%s ", buf);
    }
    putchar('\n');

    return 0;
}
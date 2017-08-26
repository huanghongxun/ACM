#include <cstdio>
char answer[5000][5000] = {0};
int number, w[12]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
void work(int i, int j, int size)
{
    if(size == 1)
    {
        answer[i][j + 1] = answer[i + 1][j] = '/';
        answer[i][j + 2] = answer[i + 1][j + 3] = '\\';
        answer[i + 1][j + 1] = answer[i + 1][j + 2] = '_';
    }
    else
    {
        work(i, j + w[size], size - 1);
        work(i + w[size], j, size - 1);
        work(i + w[size], j + w[size], size - 1);
    }
}
int main()
{
    int i,j;
    scanf("%d", &number);
    work(0, 0, number);
    for(i = 0; i < w[number]; i++)
    {
        for(j = 0; j <= w[number] + i; j++)
        {
            if(answer[i][j] == 0) printf(" ");
            else printf("%c", answer[i][j]);
        }
        printf("\n");
    }
    return 0;
}
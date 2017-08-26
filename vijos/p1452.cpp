#include <cstdio>
int year, month, day;
bool leap(int y) {
    return y%4==0&&y%100!=0||y%400==0;
}
int main(){
    int m[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d%d%d", &year, &month, &day);
    for(int i = 1; i <= 10000; i++)
    {
    	if(leap(year))
            m[2]=29;
        else
            m[2]=28;
        day++;
        if(day >= m[month] + 1)
        {
            month++;
            day = 1;
        }
        if(month >= 13)
        {
            year++;
            month = 1;
        }
    }
    printf("%d-%d-%d\n", year, month, day);
    return 0;
}
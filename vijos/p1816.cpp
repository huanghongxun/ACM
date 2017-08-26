#include <cstdio>
#include <algorithm>
using namespace std;
int arr[300000],temp;
int main(){
    int totalNum,count=0;
    int i;
    scanf("%d",&totalNum);
    for(i=0;i<totalNum;i++)
        scanf("%ld",&arr[i]);
    sort(arr,arr+totalNum);
    temp=arr[0];
    for(i=0;i<totalNum;i++){
        if(temp==arr[i]){
            count++;
        }else{
            printf("%ld %d\n",temp,count);
            count=1;
            temp=arr[i];
        }
    }
    printf("%ld %d\n",temp,count);
    return 0;
}
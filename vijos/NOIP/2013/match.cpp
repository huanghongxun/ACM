#include <cstdio>
#include <cstdio>
#include <cstring>
#define N 100005
typedef long long ll;

int global_count;

int num = 0;
void merge(int ar[],int low,int mid,int high)
{
    int* b = new int[high + 1];
    for (int i = low;i <= high;++i)
    {
        b[i] = ar[i];
    }
    int i = low,j = mid + 1,k = low;
    while (i <= mid&&j <= high)
    {
        if (b[i] <= b[j])
        {
            ar[k++] = b[i++];
        }
        else
        {
            ar[k++] = b[j++];
            global_count += mid - i + 1; 
        }
    }
    while (i <= mid) { ar[k++] = b[i++]; }
    while (j <= high){ ar[k++] = b[j++]; }
    delete []b;
}
void merge_sort(int ar[],int low,int high)
{
    if (low < high)
    {
        int mid = low + (high - low)/2;
        merge_sort(ar,low,mid);
        merge_sort(ar,mid + 1,high);
        merge(ar,low,mid,high);
    }
}


int main() {
	int n;
	int a[N], b[N], c[N];
	int i;
	scanf("%d", &n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++) scanf("%d",&b[i]);
	global_count = 0;
	merge_sort(a,0,n-1);
	merge_sort(b,0,n-1);
	printf("%d",global_count);

	return 0;
}
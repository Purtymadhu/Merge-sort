#include <stdio.h>
void merge(int a[],int p, int q, int r);
void mergeSort(int a[], int p, int r)
{
    int q;
    if(p < r)
    {
        q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q+1, r);
        merge(a, p, q, r);
    }
}

void merge(int a[], int p, int q, int r)
{
    int b[1001];   
    int i, j, k;
    k = 0;
    i = p;
    j = q + 1;
    while(i <= q && j <= r)
    {
        if(a[i] < a[j])
        {
            b[k++] = a[i++];  
        }
        else
        {
            b[k++] = a[j++];
        }
    }
  
    while(i <= q)
    {
        b[k++] = a[i++];
    }
  
    while(j <= r)
    {
        b[k++] = a[j++];
    }
  
    for(i=r; i >= p; i--)
    {
        a[i] = b[--k];  
    } 
}

void printArray(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
 
int main()
{
	int n,i;
	printf("Enter how many elements you want:");
	scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:");
    for(i=0;i<n;i++)
    {
    	 scanf("%d",&arr[i]);
    }
    int len = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array: \n");
    printArray(arr, len);
    
    mergeSort(arr, 0, len - 1);
 
    printf("\nSorted array: \n");
    printArray(arr, len);
    return 0;
}



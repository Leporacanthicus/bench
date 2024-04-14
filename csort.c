#include <stdlib.h>
#include <stdio.h>

#define n 10000000
int arr[n];

int compare(const void *a, const void *b)
{
    const int *pa = a;
    const int *pb = b;
    if (*pa > *pb) return 1;
    if (*pa < *pb) return -1;
    return 0;
}

int main()
{
    for(int i = 0; i < n; i++)
	arr[i] = rand();

    qsort(arr, n, sizeof(arr[0]), compare);
    // Print the 10 smallest and 10 biggest numbers. 
    for(int i = 0; i < 10; i++)
	printf("Smallest=%d,  Biggest=%d\n", arr[i], arr[n-(i+1)]);
}

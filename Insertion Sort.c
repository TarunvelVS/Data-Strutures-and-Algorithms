#include<stdio.h>
#include<limits.h>


int main()
{
int arr[]  = {33, 24, 31, 15, 10, 51, 40, 55, 78, 12, 20, 16, 19, 30};

int index, size, unsorted, poi, safe, shifter;
size = sizeof(arr) / sizeof(arr[0]);

for(index = 0; index < size; printf("%d ", arr[index++]));
{
for(unsorted = 1; unsorted < size; unsorted++)
{
for(poi = 0; poi < unsorted && arr[unsorted] > arr[poi] ; poi++);
safe = arr[unsorted];
for(shifter = unsorted - 1; shifter >= poi; shifter--)
    arr[shifter+1] = arr[shifter];
    arr[poi] = safe;
    }
}



for(index = 0, printf("\n"); index < size; printf("%d ", arr[index++]));



}

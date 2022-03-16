#include<stdio.h>



void swap (int arr[], int pos1, int pos2)
{
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}
heapSort(int arr[], int size, int scope)
{

int parent;
for(scope = size -1; scope >=0; scope--)
{
for(parent = (scope - 1) / 2; parent >= 0; parent--)
      maxHeapify(arr, parent, scope);
      swap(arr, 0, scope);
}
}

maxHeapify(int arr[], int parent, int scope)
{
   int left, right;
   left = parent * 2 + 1;
   right = left + 1;
   if(left > scope) return;  // leaf Node
   if(left == scope) // single child
   {
       if(arr[left] > arr[parent])
          swap(arr, left,parent);
          return;
   }

   if(arr[parent] > arr[left] && arr[parent] > arr[right]) return;

   if(arr[left] > arr[right])
   {
       swap(arr, left, parent);
       maxHeapify(arr, left, scope);
   }
   else
   {
   swap(arr, right, parent);
       maxHeapify(arr, right, scope);
   }
}

int main()
{
int size, index, arr[] = {5,15,10,25,55,35,75,45,95,50,70,40,60,90,3}, n;
size = sizeof(arr) / sizeof(arr[0]);
n = 10;
for(index = 0; index < size; printf("%d ", arr[index++]));
heapSort(arr, size, n);
for(index = 0, printf("\n"); index < size; printf("%d ", arr[index++]));
return 0;
}

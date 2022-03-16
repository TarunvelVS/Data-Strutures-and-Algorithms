#include<stdio.h>

void swap(int arr[], int pos1, int pos2)
{
int temp;
temp = arr[pos1];
arr[pos1] = arr[pos2];
arr[pos2]= temp;
}

int arr[] = {5,15,10,25,55,35,75,45,95,50,70,40,60,90,3}, scope;

int * heapSort(int arr[] , int size)
{
    int parent, temp;
    for(scope = size-1; scope >= 0; scope--)
    {
    for(parent = scope / 2 - 1; parent >= 0; parent--)
         maxHeapify(parent);
         temp = arr[0];
         arr[0] = arr[scope];
         arr[scope] = temp;
         }
        return arr;
}

maxHeapify(int parent)
{
   int left, right;
   left = parent * 2 + 1;
   right = parent * 2 + 2;
   //
    if(left > scope) return; // CHILD
    if(left == scope) // SINGLE CHILD
    {
         if(arr[left] > arr[parent])
               swap(arr, left, parent);
          return;
    }

    if(arr[parent] > arr[left]  && arr[parent] > arr[right]) return;

    if(arr[left] > arr[right])
    {
        swap(arr, left , parent);
        maxHeapify(left);
        return;
    }
    else
    {
    swap(arr, right , parent);
        maxHeapify(right);
        return;
    }


}


int main()
{
    int index, size;
    size = sizeof(arr) / sizeof(arr[0]);
for(index = 0; index < size; printf("%d ", arr[index++]));
heapSort(arr, size);
for(index = 0, printf("\n"); index < size; printf("%d ", arr[index++]));

}

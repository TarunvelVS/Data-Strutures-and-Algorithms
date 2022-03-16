#include<stdio.h>

void swap(int arr[], int pos1, int pos2)
{
int temp;
temp = arr[pos1];
arr[pos1] = arr[pos2];
arr[pos2]= temp;
}



int  nthLargest(int arr[] , int size, int n)
{
    int parent, temp, ctr, *newArr, retVal,scope;
    newArr = (int *) malloc(sizeof(int )* size);
    for(ctr = 0; ctr < size;ctr++)
           newArr[ctr] = arr[ctr];
    for(scope = size-1, ctr = 0; scope >= 0 && ctr < n; scope--,ctr++)
    {
    for(parent = scope / 2 - 1; parent >= 0; parent--)
         maxHeapify(newArr, scope, parent);
         temp = newArr[0];
         newArr[0] = newArr[scope];
         newArr[scope] = temp;
         }
        retVal = newArr[size-n];
        free(newArr);
        return retVal;
}

maxHeapify(int arr[], int scope, int parent)
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
        maxHeapify(arr, scope, left);
        return;
    }
    else
    {
    swap(arr, right , parent);
        maxHeapify(arr, scope, right);
        return;
    }


}


int main()
{
    int arr[] = {5,15,10,25,55,35,75,45,95,50,70,40,60,90,3};
    int index, size;
    size = sizeof(arr) / sizeof(arr[0]);
for(index = 0; index < size; printf("%d ", arr[index++]));
printf("\n\n%d\n", nthLargest(arr, size, 6));
for(index = 0, printf("\n"); index < size; printf("%d ", arr[index++]));

}

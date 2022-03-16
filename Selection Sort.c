#include<stdio.h>
#include<limits.h>

int * selectionSort(int arr[],int size)
{
      int minval, minpos, temp, looper, begin;

      for(begin = 0, minval = arr[begin], minpos = begin; begin < size;
          begin++,minval = arr[begin], minpos = begin)
          {
      for(looper = begin+1;
                        looper < size; looper++)
           if(arr[looper] < minval)
           {
               minval = arr[looper];
               minpos = looper;
           }

           temp = arr[begin];
           arr[begin]= arr[minpos];
           arr[minpos] = temp;
      }

return arr;
}
int main()
{
int arr[]  = {23, 89, 45, 90, 34, 67, 12, 89, 33, 22, 77, 56, 54, 30};
//int arr[] = {1,2,3,4,5,6,7,8,10,11,12,14,9,15,16,17,18,19,20,13};
int index, size;
size = sizeof(arr) / sizeof(arr[0]);

for(index = 0; index < size; printf("%d ", arr[index++]));
selectionSort(arr, size);
for(index = 0, printf("\n"); index < size; printf("%d ", arr[index++]));



}

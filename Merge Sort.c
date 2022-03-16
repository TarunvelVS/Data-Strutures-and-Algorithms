#include<stdio.h>

int * merger(int arr[],int start, int mid, int end);
void mergeSort(int arr, int start, int end)
{
       int mid;
       if(start>=end) return;
       mid = (start+end)/2;

       mergeSort(arr, start, mid);
       mergeSort(arr, mid+1, end);
       merger(arr, start, mid, end);
}



int * merger(int arr[],int start, int mid, int end)
{
    int size, ind1, ind2, *newArr= NULL, newind=0, ind;

    size = (end - start ) + 1;
    newArr = (int * ) malloc(sizeof(int) * size);

    ind1 = start;
    ind2 = mid + 1;
    while(ind1 <= mid && ind2 <= end)
    {
    if(arr[ind1] < arr[ind2])
      newArr[newind++] = arr[ind1++];
      else
         newArr[newind++] = arr[ind2++];
         }
         while(ind1 <= mid )
             newArr[newind++] = arr[ind1++];
            while(ind2 <= end)
                     newArr[newind++] = arr[ind2++];
         for(ind=start, newind=0; newind < size; newind++, ind++)
              arr[ind] = newArr[newind];
              free(newArr);

return arr;
}


int main()
{
  int arr [] =   {96, 202, 123, 127, 3, 55,31, 6, 0, -5, 7, -17, 17, 75, 45, 80, 50};
  int start, mid, end, size, index;
  size = sizeof(arr) / sizeof(int);
start = 0;
end = size - 1;
for(index= 0; index < size; printf("%d ", arr[index++]));
mergeSort(arr, start, end);
for(index= 0, printf("\n"); index < size; printf("%d ", arr[index++]));

return 0;
}

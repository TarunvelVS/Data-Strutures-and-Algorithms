#include<stdio.h>
// 2: 58
void print(int arr[], int start, int end)
{
    int index;
    for(index= start, printf("\n"); index <= end; printf("%d ", arr[index++]));
}
void swap(int arr[], int pos1, int pos2)
{
  int temp;
  temp = arr[pos1];
  arr[pos1] = arr[pos2];
  arr[pos2] = temp;
}

void quickSort(int arr[], int start, int end)
{
int pivot, left, right, index;
if(start>=end) return; // base case
left = start;
pivot = arr[end];
right = end - 1;
// print(arr, start,end);
while(left <= right)
{
   while(left < end  && arr[left] <=pivot)
       left++;
       while(right >= start && arr[right] > pivot)
           right--;
           if(left <  right)
               swap(arr, left, right);
}
if(right < start)
    swap(arr, start, end);
else if (left!= end)
          swap(arr, left, end);

    //   print(arr, start,end);
    //   getch();
               quickSort(arr, start, left-1);
               quickSort(arr, left+1, end);
}
int main()
{
//int arr[ ]= {45, 50, 36, 10, 89, 98, 46, 38, 89, 36, 78, 67, 23, 28, 15, 89, 44, 36, 66, 39, 36};
int arr[] = {10,56,144,7,47,3,99,56,143,45,23, 100, 1, 999, 0, 55, 56, -50, -3, 47, 0};
int size, index;
size = sizeof(arr) / sizeof(int);

for(index= 0; index < size; printf("%d ", arr[index++]));
quickSort(arr, 0, size-1);
for(index= 0, printf("\n"); index < size; printf("%d ", arr[index++]));
return 0;
}

#include<stdio.h>
#define SWAPPED 1
#define NOT_SWAPPED 0
int main()
{
    int arr[] = {34, 78, 12, 45, 23, 95,11,  66, 15, 42, 51, 88, 33, 90, 47};
    int size, inner, outer, temp, ind, swap_flag= SWAPPED;
    size =sizeof(arr) / sizeof(arr[0]);
    for(ind = 0; ind < size; printf("%d ", arr[ind++]));
for(outer = 0; outer < size && swap_flag == SWAPPED  ; outer++) // optimize using flag
{
    swap_flag = NOT_SWAPPED;
    for(inner = 0; inner < size - (1 + outer) ; inner++) //  first optmization
    {
        if(arr[inner] > arr[inner+1])
        {
           temp = arr[inner];
           arr[inner] = arr[inner+1];
           arr[inner+1] = temp;
           swap_flag= SWAPPED;
        }
    }
    for(ind = 0, printf("\n"); ind < size; printf("%d ", arr[ind++]));
}
return 0;
}

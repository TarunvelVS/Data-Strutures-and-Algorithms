//Program for Binary Search

#include<stdio.h>
#include<conio.h>

void main()
{
   int f, l, m, size, i, sElement, list[50]; //int f, l ,m : First, Last, Middle
   clrscr();

   printf("Enter the size of the list: ");
   scanf("%d",&size);

   printf("Enter %d integer values : \n", size);

   for (i = 0; i < size; i++)
      scanf("%d",&list[i]);

   printf("Enter value to be search: ");
   scanf("%d", &sElement);

   f = 0;
   l = size - 1;
   m = (f+l)/2;

   while (f <= l) {
      if (list[m] < sElement)
         f = m + 1;    
      else if (list[m] == sElement) {
         printf("Element found at index %d.\n",m);
         break;
      }
      else
         l = m - 1;  
      m = (f + l)/2;
   }
   if (f > l)
      printf("Element Not found in the list.");
   system("pause");
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];

int top = -1;
int element;

void push(int);
void pop();

void display();

int main()
{
 		int ch  =1;
 		while(ch)
 		{
		 printf("\nEnter the value to be inserted in Stack : ");
		 scanf("%d",&element);
		 push(element);
		 printf("\nDo you want to insert another no: ");
		 printf("\nChoice (1/0) : ");
		 scanf("%d",&ch);
		}

		display();
		pop();
		printf("\nAfter Popping");
		display();
		
		
 		printf("\n\n");
 		system("pause");
 		return 0;
}

void push(int ele)
{
   if(top == MAX-1)
   {
	 				printf("\nStack is FULL");
	 				return;
   }
   else{
	 			++top;
	 			stack[top] = ele;
			 }
 		 
 		 
}

void pop()
{
 		 int ele;
 		 if(top == -1)
 		 {
		 				printf("\nStack is Empty.Hence can't perform Pop op\n");
		 				return;
     }
		 else
		 {
		 		 ele = stack[top];
		 		 top = top -1;
		 		 printf("\n%d Elements has been popped out\n",ele);
		 }	
}

void display()
{
 		 int i=top;
 		 while(i>=0)
 		 {
				printf("\n%d",stack[i]);
        i--;
     }
 		 
}

#include <stdio.h>
#include <stdlib.h>

struct node
{

    int val;
    struct node *next;
};

typedef struct node LList;

void DisplayList(LList *);
void *createNode();
void sortLList(LList *);
void SwapPair(LList *);
LList *revLList(LList *);

int main()
{
    LList *n=NULL, *temp=NULL, *head=NULL;
    LList *midPt=NULL;

    int ch=1;

    while(ch)
    {

        /*create new node */
        n = (LList *)createNode();

        printf("\nEnter the value: ");
        scanf("%d",&n->val);
        n->next = NULL;

        /* check if the list is new */
        if(head == NULL)
        {
            head = n;
            temp = n;
        }
        else
        {

            temp->next = n;
            temp = temp->next;
        }

            printf("\nDo you wish to add new node: ");
            scanf("%d",&ch);

    }

    temp->next = NULL;
    temp = head;

    DisplayList(head);
    //sortLList(head);
    //SwapPair(head);
    //midPt = middlenode(head);
    //printf("\n mid pt  is = %d ",midPt->val);
    head = revLList(head);
    DisplayList(head);
    return 0;
}

void *createNode()
{
    return (malloc(sizeof(LList)));
}

void DisplayList(LList *head)
{
    printf("\nList is\n");
    while(head != NULL)
    {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("\n\n");
}

void sortLList(LList *head)
{
    int min =0,tmp;
    LList *temp = head;
    LList *temp2;
    LList *temp3;

    /* main Loop */
    while(head->next != NULL)
    {
        while(temp->next !=NULL)
        {
            if(temp->val > temp->next->val)
            {
                tmp = temp->val;
                temp->val = temp->next->val;
                temp->next->val = tmp;
            }
            temp = temp->next;
        }
        head = head->next;

    }


}

void SwapPair(LList *head)
{
    LList *temp =head;
    int temp1;
    while(temp!=NULL && temp->next !=NULL)
    {
        temp1 = temp->val;
        temp->val = temp->next->val;
        temp->next->val = temp1;
        temp= temp->next->next;
    }

}

LList* middlenode(LList *head)
{
 			 LList *slow, *fast;
 			 slow = head;
 			 fast = head;

 			 while((fast!=NULL) && (fast->next != NULL))
 			 {
					slow =slow->next;
					fast = fast->next->next;
			 }
            /* middle node address returned */
			 return slow;
}

LList *revLList(LList *head)
{
 			LList *p=NULL,*c=head,*next=NULL;

 			if(head !=NULL)
 			{
			 				while(c!=NULL)
			 				{
 							  next=c->next;
 								c->next=p;
 								p=c;
 								c=next;

							}
				}
			return p;
}

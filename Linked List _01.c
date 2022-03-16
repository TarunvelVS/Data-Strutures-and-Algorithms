#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

int data;
struct DCLL
{
        int info;
        struct DCLL *rptr, *lptr;
}*start = NULL, *temp, *neww, *prev, *end = NULL;

void ins_beg_dcll();
void ins_end_dcll();
void del_beg_dcll();
void del_end_dcll();
void create_dcll();
void travers();
void insert();
void delet();
void search();
void update();

void main()
{
        int choice;
        char ch, ch2 = 'y';
        do
        {
           if (start == NULL)
            {
                do
                {
                        // clrscr();
                        printf("\nError : Linked LIst is Empty Want to Create (Y/N).. ");
                        fflush(stdin);
                        scanf("%c", &ch);
                        if (ch == 'n' || ch == 'N')
                        {
                                exit(0);
                        }
                        else if (ch == 'y' || ch == 'Y')
                        {
                                create_dcll();
                                break;
                        }
                        else
                        {
                                printf("\nError : Invalid Choice");
                        }
                } while (ch == 'y' || ch == 'Y');
          }
          else
          {
                // clrscr();
                printf("\n1. Insert");
                printf("\n2. Delete");
                printf("\n3. Traverse");
                printf("\n4. Search");
                printf("\n5. Update");
                printf("\n\nPress 0 to Exit");
                printf("\nEnter your Choice : ");
                scanf("%d", &choice);

                switch (choice)
                {
                      case 0:
                        exit(0);
                        break;
                      case 1:
                        insert();
                        travers();
                        break;
                      case 2:
                        delet();
                        travers();
                        break;
                      case 3:
                        travers();
                        break;
                      case 4:
                        search();
                        break;
                      case 5:
                        update();
                        break;
                      default:
                        printf("\nError : Invalid Choice. \n");
                }
                printf("\nWant to Continue (Y/N)... ");
                fflush(stdin);
                scanf("%c", &ch2);
           }

     }while (ch2 == 'y' || ch2 == 'Y');
}
void create_dcll()
{
        char ch;
        do
        {
                //clrscr();
                printf("\nEnter Node Info");
                printf("\n\nEnter Info : ");
                scanf("%d", &data);
                temp = (struct DCLL *)malloc(sizeof(struct DCLL));
                temp->info = data;
                temp->rptr = start;
                temp->lptr = start;

                if (start == NULL)
                {
                        start = temp;
                        end = temp;
                        start->rptr = start;
                        start->lptr = start;
                }
                else
                {
                        temp->lptr = end;
                        end->rptr = temp;
                        temp->rptr = start;
                        start->lptr = temp;
                        end = temp;
                }
                printf("\nDo you want to insert another Node (Y/N)... ");
                fflush(stdin);
                scanf("%c", &ch);
        } while (ch == 'y' || ch == 'Y');
}
void ins_beg_dcll()
{
        neww->rptr = start;
        start->lptr = neww;
        neww->lptr = end;
        end->rptr = neww;
        start = neww;
}
void ins_end_dcll()
{
        neww->lptr = end;
        end->rptr = neww;
        neww->rptr = start;
        start->lptr = neww;
        end = neww;
}
void travers()
{
        temp = start;
        if (start == NULL)
        {
                printf("\nError : Linked list is Empty");
        }
        else
        {
                if (start == end)
                {
                        printf("\n%d", temp->info);
                }
                else
                {
                        printf("\n%d", temp->info);
                        do
                        {
                                temp = temp->rptr;
                                printf("\n%d", temp->info);
                        } while (temp != end);
                }
        }
}
void insert()
{
        int pos, count = 1;
        printf("\nEnter Position : ");
        scanf("%d", &pos);
        printf("\nEnter Info :");
        scanf("%d", &data);

        neww = (struct DCLL *)malloc(sizeof(struct DCLL));
        neww->info = data;
        temp = start;

        if (pos == 1)
        {
                ins_beg_dcll();
        }
        else
        {
                while (count != pos - 1 && temp->rptr != start)
                {
                        count++;
                        temp = temp->rptr;
                }
                if (temp->rptr == start && count < pos - 1)
                {
                        printf("\nError : Invalid Position...");
                }
                else if (temp->rptr == start && count == pos - 1)
                {
                        ins_end_dcll();
                }
                else
                {
                        neww->rptr = temp->rptr;
                        neww->lptr = temp;
                        temp->rptr->lptr = neww;
                        temp->rptr = neww;
                }
        }
}
void delet()
{
        int pos, count = 1;
        printf("\nEnter Position : ");
        scanf("%d", &pos);
        temp = start;
        if (pos == 1)
        {
                del_beg_dcll();
        }
        else
        {
                while (count != pos && temp != end)
                {
                        prev = temp;
                        temp = temp->rptr;
                        count++;
                }
                if (temp == end && count < pos - 1)
                {
                        printf("\nError : Invalid Position.");
                }
                else if (temp == end && count == pos)
                {
                        del_end_dcll();
                }
                else
                {
                        prev->rptr = temp->rptr;
                        temp->rptr->lptr = prev;
                        free(temp);
                }
        }
}
void del_beg_dcll()
{
        start = start->rptr;
        start->lptr = end;
        end->rptr = start;
        free(temp);
}
void del_end_dcll()
{
        end = end->lptr;
        end->rptr = start;
        start->lptr = end;
        free(temp);
}
void search()
{
        int src, count = 1;
        printf("\nEnter Info : ");
        scanf("%d", &src);
        temp = start;
        do
        {
                prev = temp;
                if (prev->info == src)
                {
                        printf("\nSearch Value found at %d Position.", count);
                        break;
                }
                count++;
                temp = temp->rptr;
        } while (prev != end);
        if (temp == start)
        {
                printf("\nError : Search value doesn't exists.");
        }
}
void update()
{
        int pos, count = 1, dt;
        printf("\nEnter Position : ");
        scanf("%d", &pos);
        printf("\nEnter New Info : ");
        scanf("%d", &dt);
        temp = prev = start;
        do
        {
                if (count == pos && prev != end)
                {
                        prev->info = dt;
                        break;
                }
                prev = temp;
                temp = temp->rptr;
                count++;
        } while (prev != end);

        if (temp == start)
        {
                printf("\nError : Invalid Choice ");
        }
}
//self refential stucture
#include<stdio.h>
struct node
{
   int data;
   struct node *next;
};
int main()
{
    struct node n1,n2;
    n1.data = 20;
    n2.data = 90;
    n1.next = NULL;
    n2.next = NULL;
    printf("%d",n1.next);
    return 0;
}

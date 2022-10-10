/* Exchange Left and right subtree */
/* Data Structures Using C by UDIT AGARWAL */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
long num;
struct node *left;
struct node *right;
};
struct node *tree=NULL;
struct node *insert(struct node *tree,long num);
void *exchange(struct node *tree);
int select();
struct node *temp;
void main()
{
clrscr();
struct node *tree=NULL;
int choice;
long digit;
do
{
choice=select();
switch(choice)
{
case 1: puts("Enter integer: To quit enter 0");
scanf("%ld",&digit);
while(digit!=0)
{
tree=insert(tree,digit);
scanf("%ld",&digit);
}continue;
case 2: printf("%5d\n",tree->num);exchange(tree);continue;
case 3: puts("END");exit(0);
}
}while(choice!=3);
}
int select()
{
int selection;
do
{
puts("Enter 1: Insert a node");
puts("Enter 2: Exchange subtrees");
puts("Enter 3: End");
puts("Enter your choice");
scanf("%d",&selection);
if((selection<1)||(selection>3))
{puts("Wrong choice: Try again");
getchar();
}
}while((selection<1)||(selection>3));
return selection;
}
struct node *insert(struct node *tree,long digit)
{
if(tree==NULL)
{
tree=(struct node *)malloc(sizeof(struct node));
tree->left=tree->right=NULL;
tree->num=digit;
}
else
if(digit<tree->num)
tree->left=insert(tree->left,digit);
else if(digit>tree->num)
tree->right=insert(tree->right,digit);
else if(digit==tree->num)
{
puts("Duplicates Nodes: Program Exited");
getch();
exit(0);
}
return(tree);
}
void *exchange(struct node *tree)
{
if((tree->left->num!=0)&&(tree->right->num!=0))
{
temp=tree->left;
tree->left=tree->right;
tree->right=temp;
printf("%5ld\n",tree->left->num);
printf("%5ld\n",tree->right->num);
exchange(tree->left);
exchange(tree->right);
}
}

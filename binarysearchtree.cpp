#include<stdio.h>
#include<malloc.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
}*root=NULL;
void insert(int item)
{
	struct node *temp,*ptr,*parent;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->left=temp->right=NULL;
	if(root==NULL)
	{
		root = temp;
	}
	else
	{
		ptr=root;
		while(ptr!=NULL)
		{
			if(item<ptr->data)
			{
				parent = root;
				ptr=ptr->left;
			}
			else if(item>ptr->data)
			{
				parent = ptr;
				ptr=ptr->right;
			}
			else
			{
				printf("\n invalid");
			}
		}
	}
	if(item<parent->data)
	{
		parent->left=temp;
	}
	else
	{
		parent->right=temp;
	}

}

struct node *deleteElement(int item)
{
struct node *cur, *parent, *suc, *psuc, *ptr;
if(root–>left==NULL)
{
printf("\n The tree is empty ");
return(root);
}
parent = root;
cur = root–>left;
while(cur!=NULL && item!= cur–>data)
{
parent = cur;
cur = (item<cur–>data)? cur–>left:cur–>right;
}
if(cur == NULL)
{
printf("\n The value to be deleted is not present in the tree");
return(root);
}
if(cur–>left == NULL)
ptr = cur–>right;
else if(cur–>right == NULL)
ptr = cur–>left;
else
{
// Find the in–order successor and its parent
psuc = cur;
cur = cur–>left;
while(suc–>left!=NULL)
{
psuc = suc;
suc = suc–>left;
}
if(cur==psuc)
{
// Situation 1
suc–>left = cur–>right;
}
else
{
// Situation 2
suc–>left = cur–>left;
psuc–>left = suc–>right;
suc–>right = cur–>right;
}
ptr = suc;
}
// Attach ptr to the parent node
if(parent–>left == cur)
parent–>left=ptr;
else
parent–>right=ptr;
free(cur);
return root;
}

void deleteTree()
{
if(root!=NULL)
{
deleteTree(root–>left);
deleteTree(root–>right);
free(root);
}
}

int main()
{
    int option, n;
	struct node *ptr;
	clrscr();
	do
	{
	printf("\n ******MAIN MENU******* \n");
	printf("\n 1. Insert Element");
	printf("\n 2. Delete the tree");
	printf("\n\n Enter your option : ");
	scanf("%d", &option);
	switch(option)
	{
	case 1:
	printf("\n Enter the value of the new node : ");
	scanf("%d", &n);
	tree = insertElement(root, n);
	break;
	case 2:
	tree = deleteTree(root);
	break;
	}
	}while(option!=2);
	getch();
	return 0;

}

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node*right;
	struct node*left;
}node;


typedef struct tree
{
	node*root;
	
}tree;


void insert(tree *t,int data);
tree* initialize();
//void inorder(node *r);
//void postorder(node *r);
int leaves(node*r);
int nonleaves(node*r);	
int main()
{
	tree*t=initialize();
	int choice,data;
	int lea,non;
	node*r;
	while(1)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:scanf("%d",&data);
				insert(t,data);
				break;
			case 1:
				r=t->root;
				lea=leaves(r);
				printf("%d\n",lea);
				break;
			case 2:
				r=t->root;
				non=nonleaves(r);
				printf("%d\n",non);
				break;
			default:exit(0);
		}
	}
}



tree* initialize()
{
	tree*t=(tree*)malloc(sizeof(tree));
	t->root=NULL;
	return t;
}

void insert(tree*l,int data)
{
	node*temp=(node*)malloc(sizeof(node));
	node*temp1=NULL;
	if(l->root==NULL)
	{
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		//l->length=l->length+1;
		l->root=temp;
	}
	else
	{
		temp=l->root;
		while(temp!=NULL)
		{
			if(data==temp->data)
			{
				return;
			}
			
			else if(data<temp->data)
			{
				temp1=temp;
				temp=temp->left;
			}
			else
			{
				temp1=temp;
				temp=temp->right;
			}
		}
		node*temp2=(node*)malloc(sizeof(node));
		temp2->data=data;
		temp2->left=NULL;
		temp2->right=NULL;
		if(data<temp1->data)
		{
			temp1->left=temp2;
		}
		else
		{
			temp1->right=temp2;
		}
	}
}

int leaves(node*r)
{
	if(r==NULL)
	{
		return 0;
	}
	if(r->left==NULL && r->right==NULL)
	{
		return 1;
	}
	
	return leaves(r->left)+leaves(r->right);
	
}

int nonleaves(node*r)
{
	if(r==NULL)
	{
		return 0;
	}
	else if(r->left==NULL && r->right==NULL)
	{
		return 0;
	}
	return 1+nonleaves(r->left)+nonleaves(r->right);
	
	
	
}

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node*next;
	struct node*prev;
}node;

typedef struct list
{
	node*head;
	node*tail;
	int length;
}list;

list* initialize();
void displayfront(list*l);
void displayback(list*l);
void deletelast(list*l);
void insertat(list*l,int data,int p);

int main()
{
	int data,p,choice;
	list*l=initialize();
	while(1)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				scanf("%d %d",&data,&p);
				insertat(l,data,p);
				break;
			case 1:
				deletelast(l);
				break;
			case 2:
				displayback(l);
				break;
			case 3:
				displayfront(l);
				break;
			default:
				exit(0);
		}
	}
}


list* initialize()
{
	list*l=(list*)malloc(sizeof(list));
	l->head=NULL;
	l->tail=NULL;
	l->length=0;
}

void displayfront(list*l)
{
	if(l->head!=NULL)
	{
		node*temp=l->head;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

void displayback(list*l)
{
	if(l->tail!=NULL)
	{
		node*temp=l->tail;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->prev;
		}
		printf("\n");
	}
}

void deletelast(list*l)
{
	if(l->tail!=NULL)
	{
		node*temp=l->tail;
		l->tail=temp->prev;
		temp->prev->next=NULL;
		free(temp);
	}
	l->length=l->length-1;
}
/*
void insertat(list*l,int data,int p)
{
	node*temp=(node*)malloc(sizeof(node));
	temp->data=data;
	if(p>=(l->length-1) || p<0)
	{
		return ;
	}
	else if(p==0)
	{
		temp->next=NULL;
		temp->prev=NULL;
		l->head=temp;
		l->tail=temp;
	}
	else if(p==(l->length-1))
	{	
		temp->prev=l->tail;
		temp->next=NULL;
		temp->prev->next=temp;
		l->tail=temp;
	}
	else
	{
		node*temp1=l->head;
		for(int i=0;i<p-2;i++)
		{
			temp1=temp1->next;
		}
		temp->next=temp1->next;
		temp1->next->prev=temp;
		temp->prev=temp1;
		temp1->next=temp;
	}
	l->length=l->length+1;
}*/


void insertat(list*l,int data,int p)
{
	if(p<0)
	{
		return;
	}
	else if(p<=(l->length))
	{
		node*temp=(node*)malloc(sizeof(node));
		temp->data=data;
		if(p==0 && l->length==0) 
		{
			temp->next=NULL;
			temp->prev=NULL;
			l->head=temp;
			l->tail=temp;
			//puts("hi");
		}
		else if(p==0 && l->length!=0)
		{
			temp->next=l->head;
			temp->prev=NULL;
			l->head->prev=temp;
			l->head=temp;
			//puts("hello");
		}
		else if(p==(l->length))
		{	
			temp->prev=l->tail;
			temp->next=NULL;
			temp->prev->next=temp;
			l->tail=temp;
		}
		else
		{
			
			node*temp1=l->head;
			for(int i=0;i<p-2;i++)
			{
				temp1=temp1->next;
			}
			temp->next=temp1->next;
			temp1->next->prev=temp;
			temp->prev=temp1;
			temp1->next=temp;
		}
		l->length=l->length+1;
	}
}	
		
			
		
		
		

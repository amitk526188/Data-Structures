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
void insertbe(list*l,int data);

void deleteat(list*l,int p);
int main()
{
	int data,p,choice;
	list*l=initialize();
	while(1)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				scanf("%d",&data);
				insertbe(l,data);
				break;
			case 0:scanf("%d",&p);
				deleteat(l,p);
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


void insertbe(list*l,int data)
{
	node*temp=(node*)malloc(sizeof(node));
	temp->data=data;
	if(l->length==0)
	{
		temp->next=NULL;
		temp->prev=NULL;
		l->head=temp;
		l->tail=temp;
	}
	else
	{
		temp->next=l->head;
		l->head->prev=temp;
		temp->prev=NULL;
		l->head=temp;
	}
	l->length=l->length+1;
}

void deleteat(list*l,int p)
{
	node*temp;
	if((l->head==NULL)||(p<0 || p>(l->length-1)))
	{
		return ;
	}
	else if(p==0 && l->length>1)
	{
		temp=l->head;
		l->head->next->prev=NULL;
		l->head=temp->next;
		free(temp);
	}
	else if(p==0 && l->length==1)
	{
		temp=l->head;
		l->head=NULL;
		free(temp);
	}
	else if(p==(l->length-1))
	{
		temp=l->tail;
		l->tail=temp->prev;
		l->tail->next=NULL;
		free(temp);
	}
	else
	{
		temp=l->head;
		for(int i=0;i< (p-1);i++)
		{
			temp=temp->next;
		}
		node*temp1=temp->next;
		temp->next=temp1->next;
		temp1->next->prev=temp;
		free(temp1);
	}
	l->length=l->length-1;
}
		
		
		

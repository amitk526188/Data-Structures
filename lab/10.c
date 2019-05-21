#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	struct node*next;
	int data;
}node;

typedef struct list
{
	node*head;
	node*tail;
	int length;
}list;

void insertin(list*l,int data);
list* initialize();
void check(list*l);
int main()
{
	list*l=initialize();
	int data;
	scanf("%d",&data);
	for(int i=data;i>0;i--)
	{
		insertin(l,i);
	}
	check(l);
	printf("\n");

}


list* initialize()
{
	list*l=(list*)malloc(sizeof(list));
	l->head=NULL;
	l->length=0;
}

void insertin(list*l,int data)
{
	node*temp=(node*)malloc(sizeof(node));
	temp->data=data;
	if(l->length==0)
	{
		temp->next=temp;
		l->tail=temp;
		l->head=temp;
	}
	else
	{
		temp->next=l->head;
		l->head=temp;
		l->tail->next=l->head;
	}
	l->length=l->length+1;
}


void check(list*l)
{
	if(l->length==1)
	{
		return;
	}
	else
	{
		node*temp=l->head;
		node*temp1;
		while(l->length!=1)
		{
			
			temp1=temp->next;
			temp->next=temp1->next;
			temp=temp->next;
			printf("%d ",temp1->data);
			free(temp1);
			l->length=l->length-1;
		}
	}
}
			
			
			
		

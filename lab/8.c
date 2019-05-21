#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	struct node*next;
}node;

typedef struct queue
{
	node*head;
	node*tail;
	int length;
}queue;

queue* initialize();
void insertq(queue*q,int data);
void deleteq(queue*q);
void pee(queue*q);
int main()
{
	int data,choice;
	queue*q=initialize();
	while(1)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 0: scanf("%d",&data);
				insertq(q,data);
				break;
			case 1:deleteq(q);
				break;
			case 2:pee(q);
				break;
			default:exit(0);
		}
	}
				
}

queue* initialize()
{
	queue*q=(queue*)malloc(sizeof(queue));
	q->head=NULL;
	q->tail=NULL;
	q->length=0;
	return q;
}

void insertq(queue*q,int data)
{
	node*temp=(node*)malloc(sizeof(node));
	temp->data=data;
	if(q->length==0)
	{
		temp->next=NULL;
		q->head=temp;
		q->tail=temp;
	}
	else
	{
		q->tail->next=temp;
		temp->next=NULL;
		q->tail=temp;
	}
	q->length=q->length+1;
}

void deleteq(queue*q)
{
	
	if(q->length<=0)
	{
		puts("Underflow");
		return;
	}
	if(q->length==1)
	{
		node*temp=q->head;
		q->head=NULL;
		q->tail=NULL;
		free(temp);
		q->length=q->length-1;
	}
	else
	{
		node*temp=q->head;
		q->head=temp->next;
		free(temp);
		q->length=q->length-1;
	}
	
}

void pee(queue*q)
{
	if(q->length==0)
	{
		puts("Empty Queue");

	}
	else
	{
		printf("%d\n",q->head->data);
	}
}
	

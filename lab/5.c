#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	struct node*next;
}node;

typedef struct stack
{
	node*head;
	int length;
}stack;


stack* initialize();
void push(stack*s,int data);
void peek(stack*s);
void pop(stack*s);
int main()
{
	int data,choice;
	stack*s=initialize();
	while(1)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				scanf("%d",&data);
				push(s,data);
				break;
			case 1:
				pop(s);
				break;
			case 2:
				peek(s);
				break;
			default:exit(0);
		}
	}
}

stack* initialize()
{
	stack*s=(stack*)malloc(sizeof(stack));
	s->head=NULL;
	s->length=0;
	return s;
}

void push(stack*s,int data)
{
	node*temp=(node*)malloc(sizeof(node));
	temp->data=data;
	if(s->length==0)
	{
		temp->next=NULL;
		s->head=temp;
	}
	else
	{
		temp->next=s->head;
		s->head=temp;
	}
	s->length=s->length+1;
}

void peek(stack*s)
{
	if(s->head==NULL)
	{
		puts("Empty Stack");
	}
	else
	{
		printf("%d\n",s->head->data);
	}
}

void pop(stack*s)
{
	if(s->length==0)
	{
		puts("Underflow");
	}
	else if(s->length==1)
	{
		node*temp=s->head;
		s->head=NULL;
		free(temp);
	}
	else
	{
		node*temp=s->head;
		s->head=temp->next;
		free(temp);
	}
	s->length=s->length-1;
}
	 
	
	

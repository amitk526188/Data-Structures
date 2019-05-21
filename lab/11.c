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
	node*tail;
	int length;
}stack;

stack* initialize();
void pushs(stack*p,int data);
int pops(stack*s);
int isempty(stack*s);
void deque(stack*s,stack*s1);
void pri(stack*s);


int main()
{
	stack*s=initialize();
	stack*s1=initialize();
	int choice,data;
	int count=0;
	while(1)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:scanf("%d",&data);
				if(count==0)
				{
					pushs(s,data);
				}
				else
				{
					pushs(s,data);
					deque(s1,s);
				}
				break;
			case 1:
				deque(s,s1);
				count=1;
				break;
			case 2:
				
					if(isempty(s)==1 && isempty(s1)==1)
					{
						puts("empty queue");
					}
					else
					{
						if(isempty(s)==1)
						{
							printf("%d\n",s1->head->data);
						}
						else
						{
							printf("%d\n",s->tail->data);
						}
					}
				
				/*else
				{
					if(isempty(s1)==1 && isempty(s1)==1)
					{
						puts("empty queue");
					}
					else
					{
						printf("%d\n",s->head->data);
					}
				}*/
				break;

			case 3:
				pri(s);
				break;
			case 4:pri(s1);
				break;
			default:
				exit(0);
		}
	}
}

stack *initialize()
{
	stack*s=(stack*)malloc(sizeof(stack));
	s->head=NULL;
	s->length=0;
}

void pushs(stack*p,int data)
{
	node*temp=(node*)malloc(sizeof(node));
	if(data==-1)
	{
		return;
	}
	temp->data=data;
	if(p->length==0)
	{
		temp->next=NULL;
		p->head=temp;
		p->tail=temp;
	}
	else
	{
		temp->next=p->head;
		p->head=temp;
	}
	p->length=p->length+1;
}


int pops(stack*s)
{
	node*temp=s->head;
	if(s->length==0)
	{
		s->head=NULL;
		free(temp);
		s->length=s->length-1;
		return -1;
	}
	else
	{
		int x;
		x=s->head->data;
		s->head=temp->next;
		free(temp);
		s->length=s->length-1;
		return x;
	}

}


int isempty(stack*s)
{
	if(s->head==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void deque(stack*s,stack*s1)
{
	int n;
	while(isempty(s)!=1)
	{
		n=pops(s);
		//printf("%d",n);
		pushs(s1,n);
	}
	node*temp;
	if(s1->head==NULL)
	{
		puts("Underflow");
	}
	else
	{
		pops(s1);
	}
}

void pri(stack*s)
{
	node*temp=s->head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}


	
	

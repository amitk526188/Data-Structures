#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node*next;
}node;

typedef struct list
{
	int length;
	node*head;
}list;
void insertat(list*l,int data,int p);
list *initialize();
void dis(list*l);
void reverselist(list*l);
void deleteend(list*l);
int main()
{
	int data,p,choice;
	list*l=initialize();
	while(1)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:scanf("%d %d",&data,&p);
				insertat(l,data,p);
				break;
			case 1: deleteend(l);	
				break;
			case 2:
				reverselist(l);
				break;
			case 3:
				dis(l);
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
	l->length=0;
}


void insertat(list*l,int data,int p)
{
	node*temp=(node*)malloc(sizeof(node));
	temp->data=data;
	if(l->length==0)
	{
		temp->next=NULL;
		l->head=temp;
	}
	else if(p>(l->length-1))
	{
		return ;
	}
	else if(p==0)
	{
		temp->next=l->head;
		l->head=temp;
	}
	else if(p==(l->length-1))
	{
		node*temp1=l->head;
		node*temp2=temp1;
		while(temp1->next!=NULL)
		{
			temp2=temp1;
			temp1=temp1->next;
		}
		temp->next=temp1;
		temp2->next=temp;
	}
		
	else
	{
		node*temp1=l->head;
		for(int i=0;i<p-1;i++)
		{
			temp1=temp1->next;
		}
		temp->next=temp1->next;
		temp1->next=temp;
	}
	l->length=l->length+1;
}

void reverselist(list*l)
{
	if(l->head==NULL || l->length==1)
	{
		return;
	}
	else if(l->length==2)
	{
		node*temp;
		node*temp1;
		temp=l->head;
		temp1=l->head->next;
		l->head=temp1;
		temp1->next=temp;
		temp->next=NULL;
	}
	else
	{
		node*temp;
		node*temp1;
		node*temp2;
		temp=l->head;
		temp1=temp->next;
		temp2=temp1->next;
		temp->next=NULL;
		temp1->next=temp;
		temp=temp1;
		while(temp2!=NULL)
		{
			temp1=temp2;
			temp2=temp2->next;
			temp1->next=temp;
			temp=temp1;
		}
		l->head=temp1;
	}
}

void deleteend(list*l)
{
	if(l->head!=NULL)
	{
		node*temp=l->head;
		
		if(l->length==1)
		{
			free(temp);
			l->head=NULL;
		}
		else
		{
			for(int i=0;i<(l->length-2);i++)
			{
				temp=temp->next;
			}
			node*temp1=temp->next;
				
			temp->next=NULL;
			free(temp1);
		}
		l->length=l->length-1;
	}
}


void dis(list*l)
{
	node*temp;
	if(l->head !=NULL)
	{
		temp=l->head;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
	printf("\n");
}
			
		
		

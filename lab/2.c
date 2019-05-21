#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node*next;
}node;

typedef struct list
{
	int lenght;
	node*head;
}list;

list* initialize();
void insertlist(list*l,int data);
void dis(list*l);
void reverse(list*l);
void deleteat(list*l,int p);
int main()
{
	int choice;
	list *l=initialize();
	int data,p;
	while(1)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 0: scanf("%d",&p);
				deleteat(l,p);
				break;
			case 1:
				scanf("%d",&data);
				insertlist(l,data);
				break;
			case 2:
				reverse(l);
				break;
			case 3: dis(l);
				break;
			default:
				exit(0);
		}
	}

}


list* initialize()
{
	list *l=(list*)malloc(sizeof(list));
	l->lenght=0;
	l->head=NULL;
	return l;
}


void insertlist(list*l,int data)
{
	node*temp=(node*)malloc(sizeof(node));
	
	temp->data=data;
	if(l->lenght==0)
	{
		temp->next=NULL;
		l->head=temp;
	}
	else
	{
		temp->next=l->head;
		l->head=temp;
	}
	l->lenght=l->lenght+1;
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


void reverse(list*l)
{
	if(l->head==NULL || l->lenght==1)
	{
		return;
	}
	else if(l->lenght==2)
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

void deleteat(list*l,int p)
{
	node*temp;
	if(p<0 || p>=(l->lenght))
	{
		return ;
	}
	else if(p==0)
	{	
		temp=l->head;
		l->head=temp->next;
		free(temp);
		
	}
	else if(p==(l->lenght-1))
	{
		temp=l->head;
		node*temp1;
		temp1=temp;
		temp=temp->next;
		while(temp->next!=NULL)
		{
			temp1=temp->next;
			temp=temp->next;
		}
		temp1->next=NULL;
		free(temp);
	}
	else
	{
		temp=l->head;
		for(int i=0;i<p;i++)
		{
			temp=temp->next;
		}
		node*temp1;
		temp1=temp->next;
		temp->next=temp1->next;
		free(temp1);
	}
	l->lenght=l->lenght-1;
}	
		


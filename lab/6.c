#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char data;
	struct node*next;
	}node;

typedef struct Stack{
	node* top;
	int length;
	}stack;


stack* initialize();
void pushs(stack*s,char data);
void pops(stack*s);
char peek(stack*s);
int isempty(stack*s);


int main()
{
	stack*s=initialize();
	char b[100];
	scanf("%s",b);
	char ch;
	int i=0;
	ch=b[i];
	while(ch!='\0')
	{
		ch=b[i];
		switch(ch)
		{

			case '(':pushs(s,ch);
				break;
			case '{':pushs(s,ch);
				break;
			case '[':pushs(s,ch);
				break;
			case ')':if(isempty(s)!=1  && s->top->data=='(')
				{
					pops(s);
					//puts("hello");
				}
				else
				{
					puts("NO");
					//printf("%c",s->top->data);
					exit(0);
				}
				break; 
			case '}':if(isempty(s)!=1  && s->top->data=='{')
				{
					pops(s);
				}
				else
				{
					puts("NO");
					exit(0);
				}
				break; 
			case ']':if(isempty(s)!=1  && s->top->data=='[')
				{
					pops(s);
				}
				else
				{
					puts("NO");
					exit(0);
				}
				break;
		}
		i=i+1;
	}

	if(isempty(s)==1)
	{
		puts("YES");
	}
	else
	{

		puts("NO");
	}
	
	


}

stack* initialize()
{
	stack*l=(stack*)malloc(sizeof(stack));
	l->length=0;
	l->top=NULL;
	return l;
}


void pushs(stack*s,char data)
{
	node*temp=(node*)malloc(sizeof(node));
	temp->data=data;
	if(isempty(s)==1)
	{
		
		temp->next=NULL;
		s->top=temp;
	}
	else
	{
		
		temp->next=s->top;
		s->top=temp;
	}
	s->length=s->length+1;
}

void pops(stack*s)
{
	if(isempty(s)!=1)
	{	

		node*temp;
		temp=s->top;
		if(s->length==0)
		{
			s->top=NULL;
			free(temp);
		}
		else
		{
			s->top=temp->next;
			free(temp);
		}
		s->length=s->length-1;
	}
}
		

char peek(stack*s)
{
	if(isempty(s)!=1)
	{
		char x;
		x=s->top->data;
		return x;
	}
	else
	{
		return '#';
	}

}


int isempty(stack*s)
{
	if(s->top==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}


		

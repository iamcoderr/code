#include<stdio.h>
#include<stdlib.h>
void create(struct node **start);
void add(struct node **k,int d,struct node *start);
void showq(struct node *start);
void shows(struct node *start);
void atpos(struct node **start,int p,int d);
void remove(struct node **start,int p);
void reverse(struct node **start);
struct node
{
	int data;
	struct node *back;
	struct node *front;
};
int main()
{
	int choice,d,pos;
	struct node *start,*k;
	d=0;pos=0;
	create(&start);
	start->back=NULL;
	k=start;
	printf("1.To Enter Data\n2.Display(Queue)\n3.Display(Stack)\n4.Add at position\n5.Remove From position\n6.Reverse List\n");
	while(1)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter element :");
				scanf("%d",&d);
				add(&k,d,start);
				break;
			case 2:
			    showq(start);	
			    break;
			case 3:
			   shows(start);
			   break;    
			case 4:
			   printf("Enter the position :");
			   scanf("%d",&pos);
			   printf("Enter the element :");
			   scanf("%d",&d);
			   atpos(&start,pos,d);
			   break;
			case 5:
			   printf("Enter the position :");
			   scanf("%d",&pos);
			   remove(&start,pos);
			   break;
			case 6:
			   reverse(&start);   
		}
	}
	return 0;
}
void add(struct node **k,int d,struct node *start)
{
	static int i=0;
	if((*k)==start&&i==0)
	{
		(*k)->data=d;
		(*k)->back=NULL;
		i++;
	}
	else
	{
		(*k)->front=(struct node *)malloc(sizeof(node));
		(*k)->front->data=d;
		(*k)->front->back=(*k);
		(*k)->front->front=NULL;
		(*k)=(*k)->front;
	}
}
void showq(struct node *start)
{
	struct node *temp;
	temp=start;
	if(temp->front==NULL&&temp->back==NULL)
	{
		printf("No elements\n");
		return ;
	}
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->front;
	}
	printf("\n");
}
void shows(struct node *start)
{
	struct node *temp;
	temp=start;
	while(temp->front!=NULL)
	{
		temp=temp->front;
	} 
	while(temp!=NULL)
    {
	  printf("%d ",temp->data);
      temp=temp->back;
	}
	printf("\n");
}
void atpos(struct node **start,int p,int d)
{
	struct node *temp=(struct node *)malloc(sizeof(node)),*k;
	k=*start;
	if(p==1)
	{
		temp->front=(*start);
		temp->back=NULL;
		temp->data=d;
		*start=temp;
	}
	else
	{
		int count=2;
		while(count!=p&&k!=NULL)
		{
			count++;
		 k=k->front;
	    }
		if(k==NULL)
		{
			printf("Error!!\n");
			return ;
		} 
		else
		{
			temp->data=d;
			temp->back=k;
			temp->front=k->front;
			k->front->back=temp;
			k->front=temp;
			
		}
	}
}
void remove(struct node **start,int p)
{
	struct node *k;
	if(p==1)
	{
		*start=(*start)->front;
		free((*start)->back);
		(*start)->back=NULL;
	}
	else
	{
		k=*start;
		p--;
		while(p--)
		{
			k=k->front;
		}
		((k->back)->front)=k->front;
		((k->front)->back)=k->back;
	}
}
void reverse(struct node **start)
{
   struct node *temp;
   do
   {
   	 temp=(*start)->front;
	 (*start)->front=(*start)->back;
	 (*start)->back=temp;	  
	 (*start)=(*start)->back;
   } while((*start)->front!=NULL);
}
void create(struct node **start)
{
   char c;
   int d,i=0;
   struct node *temp;
   printf("Press ! to stop entering :");
   scanf(" %c",&c);
   	while(c!='!')
   	{
   		printf("Eneter :");
   		scanf("%d",&d);
   		temp=(struct node *)malloc(sizeof(node));
   		if(i==0)
   		{
   		 (*start)=temp;
   		 i++;
   		 (*start)->data=d;
   		 (*start)->front=NULL;
   		 (*start)=(*start)->front;
   	    }
   	    else
   	    {
   	    	temp->data=d;
   	    	temp->front=NULL;
   	    	temp=temp->front;
		}
   		scanf(" %c",&c);
	}
}

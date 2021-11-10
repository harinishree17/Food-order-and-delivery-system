#include<stdio.h>
#include<stdlib.h>
void ordering();
void adminlogin();
void deleteorder();
typedef struct ll
{
	int quant,price,ic;
	struct ll *nxt;
}ll;
ll *p,*r;
typedef struct queue
{
	int total;
	char name[50];
	long int phno;
	char add[100];
	long int ph;
	char na[50];
	int ordno;
	struct ll *st;
	struct queue *next;
}queue;
queue *qu,*top,*now,*k,*u,*newtemp;
ll* createnode()
{
	ll *temp;
	temp=(ll*)malloc(sizeof(struct ll));
	temp->ic=0;
	return(temp);
}
queue* createqnode()
{
	queue *temp;
	temp=(queue*)malloc(sizeof(struct queue));
	temp->total=0;
	return(temp);
}
int main()
{
	int ch,c,paw,kk;
	qu=createqnode();
	top=createqnode();
	now=createqnode();
	k=createqnode();
	u=createqnode();
	newtemp=createqnode();
	now=top;
	while(1)
	{
		printf("\n--------------------------------------------------------------------------------------------------------------");
		printf("\n	                  ***********************WELCOME TO GSHADE KITCHEN****************************               ");
		printf("\n--------------------------------------------------------------------------------------------------------------");
		printf("\n                   ********** MENU *********   ");
		printf("\n\n 		1)Food Order\n\n		2)Delete a order\n\n                3)Admin Login\n\n		4)Exit\n\nEnter your option: ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				if(qu->total==0)
        	    {
		           top=qu;
		           now=qu;
		           qu->ordno=1;
		           kk=1;
           	    }
	            else
                {
    				qu->next=createqnode();
    				qu=qu->next;
    				qu->ordno=kk+1;
				}
				printf("\n--------------------------------------------------------------------------------------------------------------");
				printf("\n	                         ***********************FOOD ORDER****************************                      ");
				printf("\n--------------------------------------------------------------------------------------------------------------");
				printf("\n Enter your name: ");
				scanf("%s",qu->name);
				printf("\n Enter the phone number: ");
				scanf("%ld",&qu->phno);
				printf("\n Enter the address: ");
				scanf("%s",qu->add);
				ordering();
				printf("\n Thanks for ordering!!\n\n          Once your order is recieved by the restaurant you will recieve a call!!!\n                 HAPPY EATING!!");
				printf("\n--------------------------------------------------------------------------------------------------------------");
				break;
			case 3:
				printf("\n--------------------------------------------------------------------------------------------------------------");
				printf("\n	                         ***********************ADMIN LOGIN****************************                     ");
				printf("\n--------------------------------------------------------------------------------------------------------------");
			    printf("\n Enter the password: ");
			    scanf("%d",&paw);
			    if(paw==1890)
				{		
				  printf("\n You've logged in successfully");
				adminlogin();
			    }
			    else
			    {
			    	printf("\n The password was incorrect");
				}
			    break;
			case 4:
				printf("\n--------------------------------------------------------------------------------------------------------------");
				printf("\n	                        ***********************THANK YOU !!****************************                     ");
				printf("\n--------------------------------------------------------------------------------------------------------------");
				printf("\n Thanks for visiting GSHADE KITCHEN !!!!!");
				exit(0);
			    break;
			case 2:
				printf("\n--------------------------------------------------------------------------------------------------------------");
				printf("\n	                        ***********************DELETE ORDER****************************                     ");
				printf("\n--------------------------------------------------------------------------------------------------------------");
			    deleteorder();
			    break;
			default:printf("\n The choice u entered is wrong!!");
    	}
    }
    return(0);
}
void ordering()
{
	int o;
	p=createnode();
	qu->st=p;
	printf("\n*******************---------------------FOOD MENU------------------*************************");
	printf("\n--------------------------------------------------------------------------------------------");
	printf("\n|	  1)Idli	 |	 2)Roast	|	3)Uthapam	|	4)Parotta  |");
	printf("\n|	     20	 	 |		25   	|	   25   	|	   30	   |");
	printf("\n--------------------------------------------------------------------------------------------");
	printf("\n--------------------------------------------------------------------------------------------");
	printf("\n|	  5)Chapathi     |    6)Fried rice      |	7)Noodles	|   8)Sandwich     |");
	printf("\n|	     30	         |     	     40         |	   35   	|      50          |");
	printf("\n--------------------------------------------------------------------------------------------");
	printf("\n--------------------------------------------------------------------------------------------");
	printf("\n|	 9)Romali roti   |    10)Meals          | 11)Seasonal Juice	|   12)Custard     |");
	printf("\n|       55               |       60             |	       40     	|         35       |");
	printf("\n--------------------------------------------------------------------------------------------");
	while(1)
	{
		printf("\n\n Enter the item number: ");
		scanf("%d",&p->ic);
		while(p->ic>12||p->ic<0)
		{
			printf("\n Enter the correct option!!!");
			printf("\n Enter the item number: ");
	 		scanf("%d",&p->ic);
		}
		printf("\n Enter the quantity: ");
		scanf("%d",&p->quant);
		while(p->quant<0)
		{
			printf("\n Enter the correct quantity!!!");
			printf("\n Enter the quantity: ");
	    	scanf("%d",&p->quant);
		}
		switch(p->ic)
		{
			case 1:
				p->price=20*p->quant;
				break;
			case 2:
				p->price=25*p->quant;
				break;
			case 3:
				p->price=25*p->quant;
				break;
			case 4:
				p->price=30*p->quant;
				break;
			case 5:
				p->price=30*p->quant;
				break;
			case 6:
				p->price=40*p->quant;
				break;
			case 7:
				p->price=35*p->quant;
				break;
			case 8:
				p->price=50*p->quant;
				break;
			case 9:
				p->price=55*p->quant;
				break;
			case 10:
				p->price=60*p->quant;
				break;
			case 11:
				p->price=40*p->quant;
				break;
			case 12:
				p->price=35*p->quant;
				break;
		}
		qu->total=qu->total+p->price;
		printf("\n Enter 1 to continue ordering  ............To stop press any other: ");
		scanf("%d",&o);
		if(o==1)
		{
			r=createnode();
			p->nxt=r;
			p=p->nxt;
		}
		else
		{
			break;
		}
	}
	printf("\n--------------------------------------------------------------------------------------------------------------");
	printf("\n	                        ***********************ORDER SUMMARY****************************                    ");
	printf("\n--------------------------------------------------------------------------------------------------------------");
	printf("\nBill total: %d",qu->total);
	printf("\n Your Order number is: %d",qu->ordno);
}
void adminlogin()
{
	int op,i=1;
	printf("\n Welcome to the admin page!!");
	while(1)
	{
		printf("\n\n 			MENU:");
		printf("\n--------------------------------------------------------------------------------------------------------------");
		printf("\n\n 			1)Orders already delivered");
		printf("\n\n 			2)Orders to be delivered");
		printf("\n\n 			3)Delivery assigning");
		printf("\n\n 			4)Exit");
		printf("\n\n Enter the choice option: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				k=top;
				i=1;
				if(k==now)
			    {
			    	printf("\n No orders delivered yet!");
			    	printf("\n--------------------------------------------------------------------------------------------------------------\n");
				}
				else if(k->total==0)
				{
				 printf("\n No orders delivered yet!");
				 printf("\n--------------------------------------------------------------------------------------------------------------\n");
				}
				else
				{
				 while(k!=now)
				 {
				    printf("\n Order priority:%d\n Order number:%d\nCustomer name: %s\nCustomer address: %s\nCustomer phone number: %ld\nBill total: %d",i,k->ordno,k->name,k->add,k->phno,k->total);
					printf("\n Delivery done by: %s",k->na);
					printf("\n Phone number of the delivery executive: %ld",k->ph);
					printf("\n--------------------------------------------------------------------------------------------------------------\n");
					k=k->next;
					i=i+1;
				  }
			   }
			   break;
			case 2:
				k=now;
				i=1;
				if(k->total==0)
				{
				 printf("\n No orders yet!");
				 printf("\n--------------------------------------------------------------------------------------------------------------\n");
				}
				else
				{
				 while(k!=NULL)
				 {
					printf("\n Order priority:%d\n Order number:%d\nCustomer name: %s\nCustomer address: %s\nCustomer phone number: %ld\nBill total: %d",i,k->ordno,k->name,k->add,k->phno,k->total);
					printf("\nDelivery executive to be assigned");
					printf("\n--------------------------------------------------------------------------------------------------------------\n");
					k=k->next;
					i=i+1;
				 }
			    }
				break;
			case 3:
				if(now->total==0)
				{
					printf("\n No orders are left to be delivered");
					printf("\n--------------------------------------------------------------------------------------------------------------\n");
				}
				else
				{
				printf("\n Enter the name of the delivery executive:");
				scanf("%s",now->na);
				printf("\n Enter the phone number of the delivery executive:");
				scanf("%ld",&now->ph);
				printf("\n Delivery has been successfully assigned!!!");
				now=now->next;
				printf("\n--------------------------------------------------------------------------------------------------------------\n");
			   }
				break;
			case 4:
				break;
			default:printf("\n Please enter a valid option");
		}
		if(op==4)
		{
			break;
			printf("\n--------------------------------------------------------------------------------------------------------------\n");
		}
	}
}
	void deleteorder()
{
	long int phoneno, jack=0, pp=0;
	k=now;
	printf("\n Enter your phone number: ");
	scanf("%ld",&phoneno);
	printf("\n Enter the order number:");
	scanf("%d",&pp);
	while(k->total!=0)
	{
		if(k->phno==phoneno&&k->ordno==pp)
		{
			printf("\nCustomer name: %s\nCustomer address: %s\nCustomer phone number: %ld\nBill total: %d",k->name,k->add,k->phno,k->total);
			if(k==top)
			{
				now=k->next;
				top=top->next;
			}
		    else
			{
				newtemp->next=k->next;
			}
			printf("\n Your order has been successfully deleted !!!\n Wish to see you again !!!");
			jack=1;
			printf("\n--------------------------------------------------------------------------------------------------------------\n");
			break;
		}
		newtemp=k;
		k=k->next;
	}
	if(jack==0)
	{
		printf("\n There was no such order placed!!!");
		printf("\n--------------------------------------------------------------------------------------------------------------\n");
	}
}

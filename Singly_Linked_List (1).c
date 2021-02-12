#include<stdio.h> 
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}Node;
Node* header=NULL;
int size=1;
void traverse(void);//display linked list
void insertfront(void);
void insertend(void);
void insertany(void);
void deletefront(void);
void deleteend(void);
void deleteany(void);
void Exit(void);

void main(){
	int choice;
	printf("--------------Singly Linked List--------------");//+18------------------
	do{
		printf("\n----------------------------------------------\n");
		printf("1,Traverse\n");
		printf("2.Insert Front\n");
		printf("3.Insert End\n");
		printf("4.Insert Any\n");
		printf("5.Delete Front\n");
		printf("6.Delete End\n");
		printf("7.Delete Any\n");
		printf("8.Exit\n");
		printf(">");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				traverse();
				break;
			case 2:
				insertfront();
				break;
			case 3:
				insertend();
				break;
			case 4:
				insertany();
				break;
			case 5:
				deletefront();
				break;
			case 6:
				deleteend();
				break;
			case 7:
				deleteany();
				break;
			case 8:
				Exit();
				break;
			default:
				printf("\n----------------------------------------------\n");
				printf("Invalid Choice!!!\nTry Again");
				printf("\n----------------------------------------------\n");
		}
	}while(choice!=8);
}


void insertfront(){
	printf("\n----------------------------------------------\n");
	int item;
	Node* ins;
	printf("Enter an element:");
	scanf("%d",&item);
	ins = (Node *)malloc(sizeof(Node));
	if(ins==NULL){
		printf("Insufficient Memory!!!");
		printf("\n----------------------------------------------\n");
		return;
	}
	else
		size++;
	ins->data=item;
	ins->next=header;
	header=ins;
	printf("\n----------------------------------------------\n");
	traverse();
}


void insertend(){
	printf("\n----------------------------------------------\n");
	int item;
	Node *ins,*front;
	printf("Enter an element:");
	scanf("%d",&item);
	ins = (Node *)malloc(sizeof(Node));
	if(ins==NULL){
		printf("Insufficient Memory!!!");
		printf("\n----------------------------------------------\n");
		return;
	}
	else
		size++;
	ins->data=item;
	ins->next=NULL;
	if(header==NULL){
		header=ins;
	}
	else
	{
		front=header;
		while(front->next!=NULL){
			front=front->next;
		}
		front->next=ins;
	}
	printf("\n----------------------------------------------\n");
	traverse();
}


void insertany(){
	printf("\n----------------------------------------------\n");
	int item,pos=0;
	Node *ins,*tra;
	printf("Enter position to place element:");
	scanf("%d",&pos);
	
	if(!((pos>0)&&(pos<=size))){
		printf("Position not present!!!");
		printf("\n----------------------------------------------\n");
		return;
	}
	
	printf("Enter an element:");
	scanf("%d",&item);
	ins = (Node *)malloc(sizeof(Node));
	
	if(ins==NULL){
		printf("Insufficient Memory!!!");
		printf("\n----------------------------------------------\n");
		return;
	}
	else
		size++;
	ins->data=item;
	ins->next=NULL;
	if(header==NULL)
	{
		header=ins;
		printf("\n----------------------------------------------\n");
		traverse();
		return;
		
	}
	tra=header;
	int count=1;
	
	if(pos==1)	
	{
		ins->next=header;
		header=ins;
		printf("\n----------------------------------------------\n");
		traverse();
		return;
	}
	
	while(count<pos-1){
		tra=tra->next;
		count++;
	}
	ins->next=tra->next;
	tra->next=ins;
	printf("\n----------------------------------------------\n");
	traverse();
}


void deletefront(){
	printf("\n----------------------------------------------\n");
	if(header==NULL)
	{
		printf("List is empty.");
		printf("\n----------------------------------------------\n");
		return;
	}
	Node* del;
	del=header;
	header=header->next;
	printf("Removed %d from list.",del->data);
	free(del);
	size--;
	printf("\n----------------------------------------------\n");
	traverse();
}

void deleteend(){
	printf("\n----------------------------------------------\n");
	if(header==NULL)
	{
		printf("List is empty.");
		printf("\n----------------------------------------------\n");
		return;
	}
	Node *front,*del,*ptr;
	ptr=header;
	front=ptr->next;
	if(front==NULL)
	{
		header=NULL;
		printf("List is empty.");
		free(ptr);
		printf("\n----------------------------------------------\n");
		return;
	}
	else 
		size--;
	while(front->next!=NULL){
		ptr=ptr->next;
		front=front->next;
	}
	ptr->next=NULL;
	printf("Removed %d from list.",front->data);
	free(front);
	printf("\n----------------------------------------------\n");
	traverse();
}


void deleteany(){
	printf("\n----------------------------------------------\n");
	if(header==NULL)
	{
		printf("List is empty.");
		printf("\n----------------------------------------------\n");
		return;
	}
	int item,pos=0,count=1;
	Node *del,*tra;
	printf("Enter position to remove element:");
	scanf("%d",&pos);
	tra=header;
	if(!((pos>0)&&(pos<=size))){
		printf("Position not present!!!");
		printf("\n----------------------------------------------\n");
		return;
	}
	else
		size--;
	
	if(pos==1){
		del=tra;
		header=tra->next;
		printf("Removed %d from list.",del->data);
		free(del);
		printf("\n----------------------------------------------\n");
		traverse();
		return;
	}
	while(count<pos-1){
		tra=tra->next;
		count++;
	}
	del=tra->next;
	tra->next=tra->next->next;
	printf("Removed %d from list.",del->data);
	free(del);
	printf("\n----------------------------------------------\n");
	traverse();
}


void traverse(){
	Node* tra;
	tra=header;
	printf("\n----------------------------------------------\n");
	if(header==NULL)
	{
		printf("List is empty.");
		printf("\n----------------------------------------------\n");
		return;
	}
	printf("List:");
	while(tra!=NULL){
		printf("%d ",tra->data);
		tra=tra->next;
	}
	printf("\n----------------------------------------------\n");
}
void Exit(){
	if(header==NULL)
	{
		printf("------------------Thank You-------------------\n");
		return;
	}
	while(header!=NULL){
		Node* ex;
		ex=header;
		header=header->next;
		free(ex);
		size--;
	}
	printf("------------------Thank You-------------------\n");
}
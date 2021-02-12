#include<stdio.h>
int queue[20],front,rear,size,choice;


void c_enqueue(void);
void c_dequeue(void);
void display(void);
void change_size(void);


void main(){
	printf("----------Circular Queue----------\n");
	change_size();
	do{
		printf("1.Insert\n");
		printf("2.Remove\n");
		printf("3.Display\n");
		printf("4.Change Size\n");
		printf("5.Exit\n");
		printf(">");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				c_enqueue();
				break;
			case 2:
				c_dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				change_size();
				break;
			case 5:
				printf("------------Thank you-------------\n");
				break;
			default:
				printf("----------------------------------\n");
				printf("Invlaid Choice!!!\nTry Again\n");
				printf("----------------------------------\n");
		}
	}while(choice!=5);
}


void change_size(){
	printf("\n----------------------------------\n");
	printf("Enter the size of Queue:");
	scanf("%d",&size);
	printf("----------------------------------\n");
}


void c_enqueue(){
	printf("\n----------------------------------\n");
	if(rear-front==size-1){
		printf("Queue is full.\n");
		printf("----------------------------------\n");
		return;
	}
	else
	{
		printf("Enter the element:");
		if(front==-1&&rear==-1){
			front=rear=0;
			scanf("%d",&queue[rear]);
		}
		else if(front>0&&rear==size-1){
			front--;
			scanf("%d",&queue[front]);
		}
		else{
			scanf("%d",&queue[rear]);
			rear++;
		}	
	}
	display();
	printf("----------------------------------\n");
}


void c_dequeue(){
	printf("\n----------------------------------\n");
	if(front==-1&&rear==-1){
		printf("Queue is empty.\n");
		printf("----------------------------------\n");
		return;
	}
	else
	{
		printf("Deleted element %d.\n",queue[front++]);
		if(front==rear){
			printf("Queue is empty.\n");
			front=rear=-1;
		}
		else
			display();
		
	}
	printf("----------------------------------\n");
}


void display(){
	printf("\n----------------------------------\n");
	printf("Queue (Capacity %d):",size);
	for(int i=front;i<rear;i++)
		printf("%d ",queue[i]);
	printf("\n----------------------------------\n");
}
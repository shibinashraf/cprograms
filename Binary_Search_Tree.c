//A Binary Search Tree with all Tree Operations

#include<stdio.h>
#include<stdlib.h>
typedef struct BST{
	int data;
	struct BST* left; 
	struct BST* right;
}Node;
Node *root=NULL;
int count=0;
Node* getNode();
Node* insert(Node *,Node *);
void inorder(Node *);
void preorder(Node *);
void delete(Node *);
void postorder(Node *);
Node* search(Node *,int);
void Insert(void);
void Search(void);
void Traverse(void);
void Delete(void);
void Exit(void);
void main(){
	printf("----------Binary Search Tree----------");//+18------------------
	char choice;
	do{
		printf("\n--------------------------------------\n");
		printf("1.Insert\n");
		printf("2.Search\n");
		printf("3.Transversal\n");
		printf("4.Exit\n");
		printf(">");
		scanf(" %c",&choice);
		printf("--------------------------------------\n");
		switch(choice){
			case '1':
				Insert();
				break;
			case '2':
				Search();
				break;
			case '3':
				Traverse();
				break;
			case '4':
				break;
			default:
				printf("\n--------------------------------------\n");
				printf("Invalid Choice!!!\nTry Again");
				printf("\n--------------------------------------\n");
		}
	}while(choice!='4');
	printf("---------------Thank You--------------\n");
}


Node* getNode(){
	Node *n;
	n=(Node *)malloc(sizeof(Node));
	n->left=NULL;
	n->right=NULL;
	return n;
}

void Insert(){
	printf("\n---------------Insertion--------------\n");
	int element;
	Node *temp;
	temp=getNode();
	if(temp==NULL){
		printf("Out of Memeory!!!");
		printf("\n--------------------------------------\n");
		return;
	}
	printf("Enter the element:");
	scanf("%d",&element);
	temp->data=element;
	if(root==NULL)
	{
		root=temp;
		root->left=NULL;
		root->right=NULL;
	}
	else
		root=insert(root,temp);
	printf("\n--------------------------------------\n");
}


Node* insert(Node *tree,Node *leaf){
	if(leaf->data<=tree->data){
		if(tree->left==NULL){
			tree->left = leaf;
		}
		else
			insert(tree->left,leaf);
	}
	if(leaf->data>tree->data){
		if(tree->right==NULL)
			tree->right = leaf;
		else
			insert(tree->right,leaf);
	}
	return tree;
}


void preorder(Node *temp){
	if(temp!=NULL){
		printf("%d ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}


void postorder(Node *temp){
	if(temp!=NULL){
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ",temp->data);		
	}
}


void inorder(Node *temp){
	if(temp!=NULL){
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}


void Traverse(){
	printf("\n---------------Traversal--------------\n");
	printf("\n----------Pre-Order Traversal---------\n");
	printf("Tree:");
	preorder(root);
	printf("\n--------------------------------------\n");
	printf("\n-----------In-Order Traversal---------\n");
	printf("Tree:");
	inorder(root);
	printf("\n--------------------------------------\n");
	printf("\n---------Post-Order Traversal---------\n");
	printf("Tree:");
	preorder(root);
	printf("\n--------------------------------------\n");
	printf("\n--------------------------------------\n");
}


Node* search(Node *tree,int x){
	if(tree==NULL||tree->data==x)
		return tree;
	else if(tree->data>x)
		return search(tree->left,x);
	else
		return search(tree->right,x);
}


void Search(){
	Node *tmp;
	int search_element;
	printf("\n-----------------Search---------------\n");
	printf("Enter item to be searched:");
	scanf("%d",&search_element);
	tmp = search(root,search_element);
	if(tmp==NULL)
		printf("Element not found.");
	else
		printf("%d found.",tmp->data);
	printf("\n--------------------------------------\n");
}

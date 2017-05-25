#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
//allocate new node

void push(struct node **head_ref,int new_data)
{
	//store 
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
void insert_after(struct node *prev_node,int new_data)
{ 
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	if(prev_node->next==NULL)
	{
		printf("prev node cannot be null");
		exit(0);
	}
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}
void insert_end(struct node **head_ref, int new_data)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	struct node *last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	if(*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}
	while(last->next!=NULL)
	{
		last=last->next;
		last->next = new_node;
		return;
	}
}
void printNode(struct node *node)
{
	while(node!=NULL)
	{
	printf("%d->",node->data);
	node = node->next;
	}
}
int main()
{
	int ch,data;
	struct node *head = NULL;
	do{
	printf("Enter your choice\n : \t(1)Add nodes from front \n\t(2)Add nodes in between\n \t(3)Add nodes in the last\n \t(4)Print the nodes\n \t(5)Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		printf("\tEnter your value to be inserted\n");
		scanf("%d",&data);
		push(&head,data);
		break;
		case 2:
		printf("\tEnter your value to be inserted\n");
		scanf("%d",&data);
		insert_after(head->next,data);
		break;
		case 3:
		printf("\tEnter your value to be inserted\n");
		scanf("%d",&data);
		insert_end(&head,data);
		break;
		case 4:
		printNode(head);
		break;
		default:printf("\tWrong choice\n");
		break;
	}
	}
	while(ch!=5);

}

	









		
	
	 
	

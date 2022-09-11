#include <stdio.h>

typedef struct node{
	int value;
	struct node *next;
}Node, *p_Node;

p_Node head = NULL;

//Á´±í²åÈë 
void Node_Insert(p_Node new_Node)
{
	p_Node last = NULL;
	if( head == NULL )
	{
		new_Node->next = NULL;
		head = new_Node;
	}
	else
	{
		last = head;
		while(last)
		{
			if(last->next==NULL)
				break;
			else
				last=last->next;
		}
		last->next = new_Node;
		new_Node->next = NULL;
	}
}

//Á´±íÉ¾³ý 
void Node_Delete(p_Node old_Node)
{
	if(head==old_Node)
	{
		head=old_Node->next;
	}
	else
	{
		p_Node pre_Node=head;
		while(pre_Node)
		{
			if(pre_Node->next==old_Node)
			{
				pre_Node->next=old_Node->next;
			}
			else
			{
				pre_Node=pre_Node->next;
			}
		}
	}
}

int main()
{
	Node A = {100,NULL};
	Node B = {101,NULL};
	Node C = {102,NULL};
	Node D = {103,NULL};
	Node_Insert(&A);
	Node_Insert(&B);
	Node_Insert(&C);
	Node_Insert(&D);
	Node_Delete(&A);
	while(head)
	{
		printf("val:%d\r\n",head->value);
		head=head->next;
	}
	return 0;
}

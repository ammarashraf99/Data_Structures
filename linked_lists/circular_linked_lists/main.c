#include <stdio.h>
#include <stdlib.h>

struct C_ListNode{
	int data;
	struct C_ListNode* next;
};

typedef struct C_LIST{
	struct C_ListNode* head;
	int size;
} C_LIST;



C_LIST* clist_init()
{
	C_LIST* newlist = malloc(sizeof(C_LIST));
	newlist->head = NULL;
	int size = 0;
	return newlist;
}



int get_clist_length(C_LIST** list)
{
	struct C_ListNode* walk = (*list)->head;
	int k=0;
	if((*list)->head == NULL)
		return 0;

	do{
		walk = walk->next;
		++k;
	}while( walk != (*list)->head );

	return k;
}



void print_clist(C_LIST* list)
{
	struct C_ListNode* walk = list->head;
	if(walk == NULL)
		printf("empty list \n");

	do{
		printf("%d ==> ",walk->data );
		walk = walk->next;
	}while( walk != list->head );
	printf("\n");
}


void insert_node_at_end(C_LIST** list, int data)
{
	/* walk pointer at the head */
	struct C_ListNode* walk = (*list)->head;

	/* creatint the new node*/
	struct C_ListNode* newNode = (struct C_ListNode*) malloc(sizeof(struct C_ListNode));
	if(newNode == NULL)
	{
		printf("Memory Error\n");
		return;}

	/* adding the data to the new node */
	newNode->data = data;

	/* checking if the list is empty */
	if((*list)->head == NULL)
	{
		newNode->next = newNode;// new node points to itself because it is going to be the only one in the list
		(*list)->head = newNode;// head of the list points to the new node (only node)
	}else{
	/* Here at least there is one node */
		/* while condition checks if walk pointer is on the last element of the list */
		while(walk->next != (*list)->head)
		{
			walk = walk->next;	// moving one step
		}
		walk->next = newNode;	// last element points to the new node
		newNode->next = (*list)->head;	// new element becomes the last element and points back to the head of the list
	}

	(*list)->size += 1;	// increamenting the size of the list
}


void insert_node_at_first(C_LIST** list, int data)
{
	struct C_ListNode* newNode = (struct C_ListNode*)malloc(sizeof(struct C_ListNode));
	if(newNode == NULL)
	{
		printf("Memory Error\n");
		return;
	}

	newNode->data = data;

	struct C_ListNode* walk = (*list)->head;
	if((*list)->head == NULL)
	{
		newNode->next = newNode;
		(*list)->head = newNode;

	}else{
		while(walk->next != (*list)->head)
		{
			walk = walk->next;
		}
		newNode->next = (*list)->head;
		(*list)->head = newNode;
		walk->next = (*list)->head;
	}
	(*list)->size += 1;

}








int main()
{
	C_LIST* myclist = clist_init();
	insert_node_at_first(&myclist, 99);
	insert_node_at_end(&myclist, 50);
	insert_node_at_end(&myclist, 40);
	insert_node_at_end(&myclist, 30);
	insert_node_at_end(&myclist, 20);


	print_clist(myclist);

	printf("%d \n" , get_clist_length(&myclist));


	return 0;
}

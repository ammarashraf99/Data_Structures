#include <stdio.h>
#include <stdlib.h>



struct D_ListNode{
	int data;
	struct D_ListNode* next;
	struct D_ListNode* prev;
};

typedef struct D_LIST{
	struct D_ListNode* head;
	struct D_ListNode* tail;
	int size;
} D_LIST;


void dlist_init(D_LIST* list)
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}



void delete_node(D_LIST* list, int position)
{
	if(list->head == NULL)
		return;
	struct D_ListNode* walk;
	if(list->head == list->tail)	// one element only
	{
		walk = list->head;
		list->head =	NULL;
		list->tail = NULL;
		free(walk);
	}else if( position == 0 ){
		walk = list->head;
		list->head = list->head->next;
		list->head->prev = NULL;
		free(walk);
	}else if( position >= list->size-1 ){
		walk = list->tail;
		list->tail = list->tail->prev;
		list->tail->next = NULL;
		free(walk);
	}else{
		int k = 0;
		if( position <  (list->size / 2 ) )
		{
			walk = list->head;
			while( k < position )
			{
				walk = walk->next;
				++k;
			}
		}else{
			int new_pos = list->size - position - 1;
			walk = list->tail;
			while( k < new_pos )
			{
				walk = walk->prev;
				++k;
			}
		}
		walk->prev->next = walk->next;
		walk->next->prev = walk->prev;
		free(walk);
	}
	list->size -= 1;
}









void insert_node(D_LIST* list, int data, int position)
{
	struct D_ListNode* newNode = (struct D_ListNode*)malloc(sizeof(struct D_ListNode));
	if(newNode==NULL){
		printf("Memory Error \n");
		return;
	}
	newNode->data = data;
	if(list->head == NULL)		// empty case
	{
		list->head = newNode;
		list->tail = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}else if( position == 0 )		// insert at first
	{

			newNode->next = list->head;
			list->head->prev = newNode;
			newNode->prev = NULL;
			list->head = newNode;
	}else if(position >= list->size)
	{
		newNode->prev = list->tail;
		list->tail->next = newNode;
		newNode->next = NULL;
		list->tail = newNode;
	}else {		// insert in the middle
		struct D_ListNode *walk;
		int k = 0;
		if( position <  (list->size / 2 ) ){
			walk = list->head;
			while( k<position )
			{
				walk = walk->next;
				++k;
			}
		}else{
			int new_pos = list->size - position - 1;
			walk = list->tail;
			while( k < new_pos )
			{
				walk = walk->prev;
				++k;
			}
		}
		newNode->next = walk;
		newNode->prev = walk->prev;
		walk->prev->next = newNode;
		walk->prev = newNode;
	}

	list->size += 1;
}




void print_list(D_LIST* list)
{
	printf("head => ");
	while(list->head)
	{
		printf("%d => ", list->head->data);
		list->head = list->head->next;
	}
	printf("NULL\n");
}




int main()
{
	D_LIST * mydlist = malloc(sizeof(D_LIST));
	dlist_init(mydlist);

	insert_node(mydlist, 10, 0);
	insert_node(mydlist, 20, 1);
	insert_node(mydlist, 30, 2);
	insert_node(mydlist, 15, 1);

	insert_node(mydlist, 79, 4);

	delete_node(mydlist, 0 );
	delete_node(mydlist, 0 );

	print_list(mydlist);


	return 0;
}













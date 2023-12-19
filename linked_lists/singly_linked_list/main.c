#include <stdio.h>
#include <stdlib.h>

struct ListNode{
	int data;
	struct ListNode* next;
};



typedef struct LIST{
	struct ListNode* head;
	struct ListNode* tail;
	int size;
} LIST;




LIST* list_init()
{
	LIST* mylist = malloc(sizeof(LIST));
	mylist->head = NULL;
	mylist->tail = NULL;
	mylist->size = 0;
	return mylist;
}

void delete_node(LIST* list, int position)
{
	if( (list->tail == NULL) && (list->head == NULL) )	// list is empty
		return;
	struct ListNode* walk;
	struct ListNode* late;
	int k = 0;
	walk = list->head;
	if(position == 0)
	{
		if( (list->head) == (list->tail) ){		// one element left
			free(list->head);
			list->head = NULL;
			list->tail = NULL;
		}else{
			list->head = list->head->next;
			free(walk);
		}
	}
	else{ 	/// continue here and remember that you have to traverse to insert at the end.
		while( walk->next && k<position )
		{
			late = walk;
			walk = walk->next;
			++k;
		}
		if(walk->next == NULL)
		{
			list->tail = late;
			late->next = NULL;
			free(walk);
		}else{
		late->next = walk->next;
		free(walk);
		}
	}

	list->size -= 1;
}



void insert_node(LIST* list, int data, int position)
{
	int k = 0;
	struct ListNode* newNode;	// The new node to insert
	struct ListNode* walk;		// This pointer will be the one standing on the position of insertion
	struct ListNode* late;		// This pointer will be the one standing on the previos position of insertion

	newNode = (struct ListNode*)malloc(sizeof(struct ListNode));	//dynamically allocating the node

	if(newNode == NULL){
		printf("Memory Error\n");
		return;
	}

	newNode->data = data;	// assigning the data to the new node
	if( (list->tail == NULL) && (list->head == NULL) ){		//list is empty
		list->tail = newNode;
		list->head = newNode;
		newNode->next = NULL;
	}else if(position == 0){		//inserting at the beginning
		newNode->next = list->head;
		list->head = newNode;
	}
	else if(position >= list->size){		// inserting at the end of the list
		list->tail->next = newNode;
		list->tail = newNode;
		list->tail->next = NULL;
	}
	else {	//traverse the list until the position where we want to insert
		walk = list->head;		//starting the walk pointer at the beginning
		while( (walk!=NULL) && (k<position) ){
			++k;
			late = walk;
			walk = walk->next;
		}
	late->next = newNode;
	newNode->next = walk;
	}

	list->size += 1;
}


void print_list(LIST* list)
{
	printf("head => ");
	while(list->head)
	{
		printf("%d => ", list->head->data);
		list->head = list->head->next;
	}
	printf("NULL\n");
}




void insert_at_first(LIST* list, int data)
{
	insert_node(list, data, 0);
}

void insert_at_end(LIST* list, int data)
{
	insert_node(list, data, list->size);

}

void delete_at_first(LIST* list)
{
	delete_node(list, 0);
}
void delete_at_end(LIST* list)
{
	delete_node(list, list->size);
}



int main()
{
	LIST* mylist = list_init();

	insert_node(mylist, 10, 0);
	insert_node(mylist, 20, 10);
	insert_node(mylist, 5, 0);
	insert_node(mylist, 30, 4);
	insert_node(mylist, 1, 0);

	delete_at_first(mylist);
	delete_at_end(mylist);


	print_list(mylist);
	return 0;
}



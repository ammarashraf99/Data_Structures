#include<stdio.h>
#include<stdlib.h>

struct DynArrayStack{
	int top;
	int capacity;
	int *array;
};

struct DynArrayStack* CreateStack()
{
	struct DynArrayStack* S = (struct DynArrayStack*) malloc(sizeof(struct DynArrayStack));
	if(!S)
		return NULL;
	S->capacity = 1;
	S->top = -1;
	S->array = malloc(S->capacity * sizeof(int));
	if(! S->array)
		return NULL;
	return S;
}

int IsFullStack(struct DynArrayStack* S)
{
	return ( S->top == S->capacity-1 );
}

void DoubleStack(struct DynArrayStack* S)
{
	S->capacity *= 2;
	S->array = realloc(S->array, S->capacity * sizeof(int));
}

void Push(struct DynArrayStack* S, int data)
{
	if(IsFullStack(S))
		DoubleStack(S);
	S->array[++S->top] = data;
}

int IsEmptyStack(struct DynArrayStack* S)
{
	return (S->top == -1);
}

int Top(struct DynArrayStack* S)
{
	if(IsEmptyStack(S))
		return -9999;
	return S->array[S->top];
}

int Pop(struct DynArrayStack* S)
{
	if(IsEmptyStack(S))
		return -9999;
	return S->array[S->top--];
}

void DeleteStack(struct DynArrayStack* S)
{
	if(S)
	{
		if(S->array)
			free(S->array);
		free(S);
	}
}



int main()
{
	struct DynArrayStack* mydstack = CreateStack();
	Push(mydstack, 50);
	Push(mydstack, 40);
	Push(mydstack, 30);
	Push(mydstack, 20);

	printf("The top is %d \n", Top(mydstack));

	printf("%d\n",Pop(mydstack));
	printf("%d\n",Pop(mydstack));
	printf("%d\n",Pop(mydstack));
	printf("%d\n",Pop(mydstack));
	printf("%d\n",Pop(mydstack));
	printf("%d\n",Pop(mydstack));

	DeleteStack(mydstack);

	return 0;
}

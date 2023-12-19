#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10


struct ArrayStack{
	int top;
	int capacity;
	int *array;
};

struct ArrayStack* CreateStack(){
	struct ArrayStack* S = malloc(sizeof(struct ArrayStack));
	if(!S)
		return NULL;
	S->capacity = MAXSIZE;
	S->top = -1;
	S->array = malloc(S->capacity*sizeof(int));
	if(!S->array)
		return NULL;
	return S;
}

int IsEmptyStack(struct ArrayStack* S)
{
	return (S->top == -1);	//if the condition is true then 1 is returned, else 0 is returned
}

int IsFullStack(struct ArrayStack* S)
{
	return (S->top == S->capacity-1);
}

void Push(struct ArrayStack* S, int data)
{
	if(IsFullStack(S))
		printf("Stack overflow!\n");
	else
		S->array[++S->top] = data;
	//            ^
	//            |
	//            |
	// This means first increament the top, then take the output of that increament to the exprestion
}

int Pop(struct ArrayStack* S)
{
	if(IsEmptyStack(S)){
		printf("Stack Underflow!\n");
		return -999;
	}else{
		return (S->array[S->top--]);
//							^
//							|
//							|
// This means first make the expression output with old top, then decrement top
//
	}
}

void DeleteStack(struct ArrayStack* S)
{
	if(S){
		if(S->array)
			free(S->array);
		free(S);
	}
}








int main()
{
	struct ArrayStack* mystack = CreateStack();

	Push(mystack, 21);
	Push(mystack, 32);
	Push(mystack, 38);
	Push(mystack, 99);

	for(int i=0; i<5; i++)
	{
		printf("%d\n", Pop(mystack));
	}





	return 0;
}

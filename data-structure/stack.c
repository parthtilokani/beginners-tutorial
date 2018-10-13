// Program for implementing static and dynamic stack using array

#include <stdio.h>
#include <stdlib.h>

static int staticPointer;
static int DynamicPointer;

struct Stack{
	int *stackPointer;
	int length;
	char *stackType;
}stack,stack1;

struct Stack *s = &stack;
struct Stack *s1 = &stack1;

int *push(struct Stack *s, int num){
	s -> length = sizeof(s -> stackPointer)/sizeof(int);
	if(s -> stackType == "Static"){		
		if(staticPointer < s -> length){
			s -> stackPointer[staticPointer] = num;
			staticPointer++;
			printf("push %d\n", num);
		}else{
			printf("%s\n","Stack overflow");
		}
		return s -> stackPointer;
	}
	if(s -> stackType == "Dynamic"){
		if(DynamicPointer >= s -> length){
			s -> stackPointer = (int*)realloc(s -> stackPointer,  (DynamicPointer+1) * sizeof(int));
			s -> stackPointer[DynamicPointer] = num;
			s -> length++; 
			DynamicPointer++;
			printf("push %d\n", num);
			return s -> stackPointer;
		}else{
			s -> stackPointer[DynamicPointer] = num;
			DynamicPointer++;
			printf("push %d\n", num);
		}
		return s -> stackPointer;
	}
}

int pop(struct Stack *s){
	if(s -> stackType == "Static"){
		if(staticPointer-1 >= 0){
			printf("pop %d\n", s -> stackPointer[staticPointer-1]);
			s -> stackPointer[staticPointer-1] = 0;
			staticPointer--;
		}else{
			printf("%s\n","Stack Underflow");
		}
	}
	if(s -> stackType == "Dynamic"){
		if(DynamicPointer-1 >= 0){
			printf("pop %d\n", s -> stackPointer[DynamicPointer-1]);
			s -> stackPointer[DynamicPointer-1] = 0;
			DynamicPointer--;
		}else{
			printf("%s\n", "Stack Underflow");
		}
	}	
}

int main(int argc, char const *argv[])
{
	s -> stackPointer = (int*)calloc(2, sizeof(int));
	s -> stackType = "Dynamic";
	s -> stackPointer = push(s, 1);
	s -> stackPointer = push(s, 2);
	s -> stackPointer = push(s, 3);
	s -> stackPointer = push(s, 4);
	for (int i = 0; i <= DynamicPointer-1; i++){
		printf("stack %d\n", s -> stackPointer[i]);
	}
	pop(s);
	pop(s);
	pop(s);
	pop(s);
	pop(s);

	printf("\n");
	s1 -> stackPointer = (int*)calloc(2, sizeof(int));
	s1 -> stackType = "Static";
	s1 -> stackPointer = push(s1, 1);
	s1 -> stackPointer = push(s1, 2);
	s1 -> stackPointer = push(s1, 3);
	s1 -> stackPointer = push(s1, 4);
	for (int i = 0; i <= staticPointer-1; i++){
		printf("stack %d %d\n", s1 -> stackPointer[i],i);
	}
	pop(s1);
	pop(s1);
	pop(s1);
	pop(s1);
	pop(s1);
	free(s -> stackPointer);
	free(s1 -> stackPointer);
	return 0;
}
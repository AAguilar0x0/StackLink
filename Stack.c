#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Stack newStack() {
	Stack stack;
	stack = (Stack) malloc(sizeof(STACK_HEAD));
	stack->count = 0;
	stack->top = NULL;
	return stack;
}

void freeStack(Stack stack) {
	Nodeptr temp;
    while(stack->top != NULL) {
		temp = stack->top->next;
		free(stack->top);
		stack->top = temp;
	}
    free(stack);
}

Nodeptr createNode(int item) {
	Nodeptr ptr;
	ptr = (Nodeptr) malloc(sizeof(STACK_NODE));
	ptr->data = item;
	ptr->next = NULL;
	return ptr;
}

void push(Stack stack, stackItem item) {
	Nodeptr temp = createNode(item);
	temp->next = stack->top;
	stack->top = temp;
	stack->count++;
}

void pop(Stack stack) {
	Nodeptr temp;
	temp = stack->top;
	stack->top = temp->next;
	temp->next = NULL;
	free(temp);
	stack->count--;
}

void display(Stack stack) {
	Nodeptr ptr = stack->top;
    int i = 0;
	while(ptr != NULL) {
		printf("%c%s",ptr->data,
            i < stack->count - 1 ? "->" : "");
		ptr = ptr->next;
        i++;
	}
}

int isEmpty(Stack stack) {
	return stack->top == NULL;
}

stackItem stackTop(Stack stack) {
    return stack->top->data;
}

char getReverseBracket(char data) {
    if(data == '(' || data == ')')
		return data += data == '(' ? 1 : -1;
    if(data == '[' || data == '{')
		return data += 2;
    if(data == ']' || data == '}')
		return data -= 2;
    return 0;
}

int isLeftBracket(char data) {
    char leftBracket[] = {'(', '[', '{'};
    char* proxy = (char*)&leftBracket;
    while(*proxy) if(data == *(proxy++)) return 1;
    return 0;
}

int isValid(char symbols[]){
	Stack stack = newStack();
	int i, valid = 1;
	for(i = 0; symbols[i] != '\0'; i++) {
		if(isLeftBracket(symbols[i]))
			push(stack,symbols[i]);
		else {
			if(isEmpty(stack)) {
				valid = 0;
				break;
			} else if(getReverseBracket(symbols[i]) == stackTop(stack))
				pop(stack);
		}
	}
	valid = isEmpty(stack) && valid;
    free(stack);
    return valid;
}

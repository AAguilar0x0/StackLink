# Stack Link

A Stack is a last-in-first-out (LIFO data Structure)
```c
// data structure LIFO
typedef char stackItem;
Stack newStack();
void freeStack(Stack *s);
// insert at the top - push
void push(Stack s,stackItem item);
// deleting the top element - pop
void pop(Stack s);
// returns the top item
stackItem stackTop(Stack s);
bool isEmpty(Stack s);
void display(Stack s);
```

1. Implement a Stack using a linked-list.
2. Use the stack in making a program that will check whether a string contains balance symbols [], {}, (). The algorithm works like this – an open symbol -- ( , { , [ -- is pushed on the stack. When a closed symbol -- ], }, ) – is encountered, check the top of the stack to see if the matching open symbol is there, if yes, pop the stack, otherwise, mismatch. At the end of the string, the stack should be empty.
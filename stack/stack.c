#include <stdio.h>
#include <stdlib.h>
#define STACK_OVERFLOW -1
#define STACK_UNDERFLOW -2
#define MAX_SIZE 10

typedef struct Stack {
  int items[MAX_SIZE];
  int top;
} stack;

stack *initialize_stack() {
  stack *newstack = (stack *)malloc(sizeof(stack));
  newstack->top = -1;
  return newstack;
}
void push(stack *s, int value) {
  if (s->top >= MAX_SIZE - 1) {
    fprintf(stderr, "Stackoverflow, pop before adding more elements");
    exit(STACK_OVERFLOW);
  }
  s->top += 1;
  s->items[s->top] = value;
}

int pop(stack *s) {
  if (s->top < 0) {
    fprintf(stderr, "Stackunderflow, add before poping");
    exit(STACK_UNDERFLOW);
  }
  int value = s->items[s->top];
  s->top -= 1;
  return value;
}
int peek(stack *s) { return s->items[s->top]; }

int main(void) {
  stack *mystack = initialize_stack();
  pop(mystack);
  push(mystack, 10);
  push(mystack, 20);
  push(mystack, 30);
  while (mystack->top >= 0) {
    printf("this is the %d in the top\n", mystack->items[mystack->top]);
    mystack->top -= 1;
  }

}

#include "./hanoi.h"
#include <stdio.h>
#include <stdlib.h>

void hanoi_tower_recursive(size_t n_disks, char rod_A, char rod_B, char rod_C) {
  if (n_disks == 0) {
    return;
  }
  hanoi_tower_recursive(n_disks - 1, rod_A, rod_C, rod_B);
  printf("Move %c to %c\n", rod_A, rod_C);
  hanoi_tower_recursive(n_disks - 1, rod_B, rod_A, rod_C);
}

void hanoi_tower_stack(size_t n_disk) {

  HanoiStack stack = hanoi_stack_create();
  hanoi_stack_push(&stack, hanoi_stack_create_element(n_disk, 'A', 'B', 'C'));

  while (stack.top != -1) {
    hanoi_stack_display(stack);
    HanoiStackElement element = hanoi_stack_pop(&stack);

    char source = element.source;
    char aux = element.aux;
    char dest = element.dest;

    n_disk = element.disk;

    hanoi_stack_push(&stack,
                     hanoi_stack_create_element(n_disk - 1, aux, source, dest));
    hanoi_stack_push(&stack, hanoi_stack_create_element(1, source, aux, dest));
    hanoi_stack_push(&stack,
                     hanoi_stack_create_element(n_disk - 1, source, dest, aux));
  }
}

HanoiStackElement hanoi_stack_create_element(size_t disk, char source, char aux,
                                             char dest) {
  return (HanoiStackElement){
      .disk = disk, .source = source, .aux = aux, .dest = dest};
}

HanoiStack hanoi_stack_create(void) {
  HanoiStack stack;
  stack.top = -1;
  return stack;
}

void hanoi_stack_push(HanoiStack *stack, HanoiStackElement element) {
  if (stack->top == MAX_STACK_CAPACITY - 1) {
    fprintf(stderr, "Hanoi StackOverflow");
    exit(-1);
  }

  stack->top += 1;
  stack->elements[stack->top] = element;
}

HanoiStackElement hanoi_stack_pop(HanoiStack *stack) {
  if (stack->top == HANOI_STACK_EMPTY) {
    fprintf(stderr, "Hanoi StackUnderflow");
    exit(-1);
  }

  HanoiStackElement element = stack->elements[stack->top];
  stack->top -= 1;

  return element;
}

void hanoi_stack_display(HanoiStack stack) {
  for (int i = stack.top; i >= 0; --i) {
    HanoiStackElement element = stack.elements[i];

    if (i == stack.top && element.disk == 1) {
      printf("|%zu|%c|%c|%c|\t Move %c to %c\n", element.disk, element.source,
             element.aux, element.dest, element.source, element.dest);
    } else {
      printf("|%zu|%c|%c|%c|\n", element.disk, element.source, element.aux,
             element.dest);
    }
  }
  printf("\n");
}

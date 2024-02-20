#ifndef HANOI_H_
#define HANOI_H_

#include <stdint.h>
#include <stdio.h>

#define MAX_STACK_CAPACITY 1024
#define HANOI_STACK_EMPTY -1

typedef struct {
  size_t disk;
  char source;
  char aux;
  char dest;
} HanoiStackElement;

typedef struct {
  HanoiStackElement elements[MAX_STACK_CAPACITY];
  int top;
} HanoiStack;

HanoiStack hanoi_stack_create(void);
void hanoi_stack_push(HanoiStack *stack, HanoiStackElement element);
HanoiStackElement hanoi_stack_pop(HanoiStack *stack);
void hanoi_stack_display(HanoiStack stack);
void hanoi_tower_recursive(size_t n_disks, char rod_A, char rod_B, char rod_C);
HanoiStackElement hanoi_stack_create_element(size_t disk, char source, char aux,
                                             char dest);
void hanoi_tower_stack(size_t n_disk);
#endif // HANOI_H_

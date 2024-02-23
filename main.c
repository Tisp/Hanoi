
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "hanoi.h"

int main(int argc, char **argv) {
  int opt;
  bool recursive = false;
  bool stack = false;
  size_t n_disks = 0;

  if (argc <= 1) {
    printf("Add arguments!\n");
    exit(1);
  }

  while ((opt = getopt(argc, argv, ":n:rs")) != -1) {
    switch (opt) {
    case 'r':
      recursive = true;
      break;
    case 's':
      stack = true;
      break;
    case 'n':
      n_disks = (size_t)atoi(optarg);
      break;
    case ':':
      printf("option %c needs a value\n", optopt);
      exit(-1);
    case '?':
      printf("unknown option : %c\n", optopt);
      exit(-1);
    }
  }
  printf("%zu\n", n_disks);
  if (n_disks <= 0) {
    printf("-n is mandatory!\n");
    exit(-1);
  }

  if (recursive && stack) {
    printf("Need to choose only one algorithm (Recursive[-r] or Stack[-s])!\n");
    exit(-1);
  }

  if (recursive) {
    hanoi_tower_recursive(n_disks, 'A', 'B', 'C');
  } else {
    hanoi_tower_stack(n_disks);
  }

  return 0;
}

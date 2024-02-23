
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "hanoi.h"

void print_help(void);

int main(int argc, char **argv) {
  int opt;
  bool recursive = false;
  bool stack = false;
  int n_disks = 0;

  if (argc <= 1) {
    printf("Add arguments!\n");
    exit(1);
  }

  while ((opt = getopt(argc, argv, ":n:rsh")) != -1) {
    switch (opt) {
    case 'r':
      recursive = true;
      break;
    case 's':
      stack = true;
      break;
    case 'n':
      n_disks = atoi(optarg);
      break;
    case 'h':
      print_help();
      exit(0);
    case ':':
      printf("option %c needs a value\n", optopt);
      print_help();
      exit(-1);
    case '?':
      printf("unknown option : %c\n", optopt);
      print_help();
      exit(-1);
    }
  }
  if (n_disks <= 0) {
    printf("-n is mandatory and greater than 1!\n");
    exit(-1);
  }

  if (recursive && stack) {
    printf("Need to choose only one algorithm (Recursive[-r] or Stack[-s])!\n");
    print_help();
    exit(-1);
  }

  if (recursive) {
    hanoi_tower_recursive(n_disks, 'A', 'B', 'C');
  } else {
    hanoi_tower_stack(n_disks);
  }

  return 0;
}

void print_help(void) {
  printf("\nHanoi Tower solution!\n");
  printf("\t-r Use recursive algorithm\n");
  printf("\t-s Use stack algorithm and shows the stack\n");
  printf("\t-n Number of disks\n");
  printf("\t-h Show help\n");
}

CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic

hanoi: main.c hanoi.c hanoi.h
	$(CC) $(CFLAGS) -o hanoi main.c hanoi.c

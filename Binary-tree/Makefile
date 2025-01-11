CC = gcc
CFLAGS = -Wall -Wextra -g

all: test_inorder

binary_tree.o: binary_tree.c binary_tree.h
	$(CC) $(CFLAGS) -c binary_tree.c

test_inorder.o: test_inorder.c binary_tree.h
	$(CC) $(CFLAGS) -c test_inorder.c

test_inorder: binary_tree.o test_inorder.o
	$(CC) $(CFLAGS) -o test_inorder binary_tree.o test_inorder.o

run_tests: test_inorder
	./test_inorder

clean:
	rm -f *.o test_inorder

.PHONY: all run_tests clean

CC = gcc
CFLAGS = -Werror -Wunused -g

usage: usage.c vector.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f usage
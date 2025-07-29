CC = gcc
CFLAGS = -Werror -g -std=c11

usage: usage.c vector.c
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f usage
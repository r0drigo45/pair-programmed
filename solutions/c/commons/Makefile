CC      := gcc
CFLAGS  := -std=gnu11 -Wall -Wextra -I.

SRCS    := slice_tu.c
OBJS    := $(SRCS:.c=.o)
TARGET  := dummy

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c slice.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: bear clean
bear:
	rm -f compile_commands.json
	bear -- make all

clean:
	rm -f $(OBJS) $(TARGET) compile_commands.json


# ── Toolchain & flags ──────────────────────────────────────────────
CC      := gcc
CFLAGS  := -std=gnu11 -Wall -Wextra -I. -I../commons

# ── Sources & target ───────────────────────────────────────────────
SRCS    := main.c
OBJS    := $(SRCS:.c=.o)
TARGET  := app

# ── Default build ─────────────────────────────────────────────────
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# ── Compile main.c; rebuild if any header changes ─────────────────
# student.h and students.h live here; slice.h lives in ../commons
%.o: %.c student.h app.h ../commons/slice.h
	$(CC) $(CFLAGS) -c $< -o $@

# ── Generate compile_commands.json via Bear ───────────────────────
.PHONY: bear
bear:
	bear -- make --no-print-directory all

# ── Clean up ───────────────────────────────────────────────────────
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) compile_commands.json


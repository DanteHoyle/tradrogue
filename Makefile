BIN = build/tradrogue
SANITIZE = -fsanitize=address,undefined
CFLAGS = -Wall -Wextra -Wpedantic -std=c23 -MMD -MP -g $(SANITIZE)
LDFLAGS += $(SANITIZE)
LDLIBS = -lncurses

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:src/%.c=build/%.o)
DEPS = $(OBJS:.o=.d)

$(BIN): $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build

-include $(DEPS)
.PHONY: clean

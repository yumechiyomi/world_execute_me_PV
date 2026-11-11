ifeq ($(OS),Windows_NT)
    BIN := world_execute_me.exe
    RM  := del /F /Q
    # Định nghĩa giả lập các tín hiệu POSIX không có sẵn trên Windows để tránh lỗi biên dịch
    CFLAGS ?= -O2 -std=gnu11 -Wall -Wextra -Wpedantic -Wshadow -DSIGWINCH=28 -DSIGPIPE=13
else
    BIN := start
    RM  := rm -f
    CFLAGS ?= -O2 -std=gnu11 -Wall -Wextra -Wpedantic -Wshadow
endif

LDLIBS  ?= -lm

SRC := src/main.c src/term.c src/gfx.c src/lyrics.c src/scenes.c \
       src/fx_world.c src/fx_love.c src/audio.c src/sprites.c
OBJ := $(SRC:.c=.o)
HDR := $(wildcard src/*.h)

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDLIBS)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(BIN)
	./$(BIN)

clean:
	$(RM) $(subst /,\,$(OBJ)) $(BIN)

.PHONY: all run clean

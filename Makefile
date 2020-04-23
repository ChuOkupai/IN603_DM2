CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
NAME	:= primtest
LDFLAGS	:= -lgmp

all: $(NAME)

clean:
	rm -rf $(NAME) src/*.o

re: clean all

src/%.o: src/%.c inc/%.h
	$(CC) $(CFLAGS) -c -I./inc $< -o $@

$(NAME): src/main.c src/$(NAME).o inc/$(NAME).h
	$(CC) $(CFLAGS) -I./inc $^ -o $@ $(LDFLAGS)

.PHONY: all clean re

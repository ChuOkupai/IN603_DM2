CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
LDFLAGS	:= -lgmp
SRC		:= primality
NAME	:= isprime

all: $(NAME)

clean:
	rm -rf $(NAME) src/*.o

re: clean all

src/%.o: src/%.c inc/%.h
	$(CC) $(CFLAGS) -c -I./inc $< -o $@

$(NAME): src/main.c src/$(SRC).o inc/$(SRC).h
	$(CC) $(CFLAGS) -I./inc $^ -o $@ $(LDFLAGS)

.PHONY: all clean re

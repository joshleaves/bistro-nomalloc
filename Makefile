CC      := gcc
CFLAGS  := -Wall -Wextra -Werror
SRC     := $(wildcard *.c)
OBJ     := $(SRC:.c=.o)
TARGET  := bistromathique

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all
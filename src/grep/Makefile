CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = s21_grep

SRCS = main.c parser.c output.c

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -rf $(TARGET)

rebuild: 
	make clean
	make all
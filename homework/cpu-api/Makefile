CC = clang
CFLAGS = -Wall -Wextra 
TARGET = $(basename $(SRC)) 
SRC = one.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

.PHONY: clean
clean:
	rm -f $(TARGET)

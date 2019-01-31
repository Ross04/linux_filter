CC = gcc

CFLAGS = -Wall

TARGET = install

all: $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
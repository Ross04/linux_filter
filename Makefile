CC = gcc

CFLAGS = -Wall

TARGET = install

all: $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

.PHONY: install
install: $(TARGET)
	install -m700 $(TARGET) /usr/local/bin

.PHONY: uninstall
unistall:
	rm -f /usr/local/bin/install

clean:
	$(RM) $(TARGET)
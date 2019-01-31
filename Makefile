CC = gcc

CFLAGS = -Wall

TARGET = install

all: $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

.PHONY: install
install: install
	cp install /usr/local/bin/install

.PHONY: uninstall
unistall:
	rm -f /usr/local/bin/install

clean:
	$(RM) $(TARGET)
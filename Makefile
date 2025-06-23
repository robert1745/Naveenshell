# Makefile for NaveenShell

CC = gcc
CFLAGS = -Wall -g
TARGET = naveenshell
SRCS = main.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

clean:
	rm -f $(TARGET)

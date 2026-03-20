CC = gcc
SRCS = main.c autolink.c check_peg.c intersection.c winner.c 
TARGET = project

all:
	$(CC) $(SRCS) -o $(TARGET)

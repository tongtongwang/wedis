APP      = main

CC=gcc
CFLAGS=-Wall -mwindows -Wwrite-strings -B include

TARGET=output/wedis
RESOURCE=output/main.res
SRCS=callbacks.c \
	main.c \
	config.c \
	view.c \
	exception.c \
	redis.c \
	connection.c

OBJS = $(SRCS:.c=.o)

$(TARGET):$(OBJS) $(RESOURCE)
	$(CC) $(CFLAGS) -o $@ $^ -lcomctl32 -lwsock32

$(RESOURCE):resource/res.rc
	windres -i resource/res.rc -O COFF -o $(RESOURCE)

clean:
	rm output/*.res output/*.exe *.o
src = $(wildcard *.cc)
targets = $(patsubst %.cc, %, $(src))

CC = g++
CFLAGS = -g -Wall -lpthread -m32 

all:$(targets)

$(targets):%:%.cc
	$(CC) $< -o $@ $(CFLAGS)

.PHONY:clean all
clean:
	-rm -rf $(targets) 

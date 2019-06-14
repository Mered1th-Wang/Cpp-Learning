src = $(wildcard *.cc)
targets = $(patsubst %.cc, %, $(src))

CC = g++
CFLAGS = -g -llog4cpp -lpthread 

all:$(targets)

$(targets):%:%.cc
	$(CC) $< -o $@ $(CFLAGS)

.PHONY:clean all
clean:
	-rm -rf $(targets) 


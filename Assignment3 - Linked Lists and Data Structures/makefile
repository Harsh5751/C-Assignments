CC = gcc
CFLAGS = -Wall -g 
OBJS  = main.o list.o listAns.o
DUMPS = core* vgcore*

main:  $(OBJS)
	$(CC) -o $@ $?

clean:
	rm -rf $(OBJS)	 main *~ 
	rm -rf $(DUMPS)

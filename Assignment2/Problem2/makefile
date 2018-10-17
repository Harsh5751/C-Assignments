OBJS = gendata.o linsolve.o checkresult.o gettime.o main.o
CFLAGS = -Wall -O3 
linsolve: $(OBJS)
	$(CC) -o $@ ${OBJS}
gendata.o: gendata.c
	$(CC) $(CFLAGS) -c $?
linsolve.o: linsolve.c
	$(CC) $(CFLAGS) -c $?
checkresult.o: checkresult.c
	$(CC) $(CFLAGS) -c $?
gettime.o: gettime.c
	$(CC) $(CFLAGS) -c $?
main.o: main.c
	$(CC) $(CFLAGS) -c $?
clean:
	rm $(OBJS) linsolve

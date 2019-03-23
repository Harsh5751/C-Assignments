OBJS = gendata.o linsolve.o checkresult.o main.o
linsolve: $(OBJS)
	$(CC) -o $@ ${OBJS}
gendata.o: gendata.c
	$(CC) -c $?
linsolve.o: linsolve.c
	$(CC) -c $?
checkresult.o: checkresult.c
	$(CC) -c $?
main.o: main.c
	$(CC) -c $?
clean:
	rm $(OBJS) linsolve

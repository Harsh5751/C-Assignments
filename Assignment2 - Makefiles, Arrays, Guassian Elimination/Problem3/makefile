OBJS = sinc.o main.o
sinc: $(OBJS) 
	$(CC) -o $@ ${OBJS} -lm
sinc.o: sinc.c 
	$(CC) -c $? -lm
main.o: main.c 
	$(CC) -c $? -lm
clean:
	rm $(OBJS) sinc

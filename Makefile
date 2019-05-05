UTILS=utils/timestamp.c utils/timestamp.h utils/purchase.c utils/purchase.h
OBJS=main.o timestamp.o purchase.o


budget: $(OBJS)
	gcc -o budget $^

main.o: main.c $(UTILS)
	gcc -c main.c

purchase.o: utils/purchase.c utils/purchase.h
	gcc -c utils/purchase.c 

timestamp.o: utils/timestamp.c utils/timestamp.h
	gcc -c utils/timestamp.c
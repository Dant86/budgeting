budgeting: ll.o budgeting.o iohandler.o
	gcc -o budgeting ll.o budgeting.o iohandler.o

budgeting.o: budgeting.c
	gcc -c budgeting.c

iohandler.o: iohandler.c iohandler.h
	gcc -c iohandler.c

ll.o: ll.c ll.h
	gcc -c ll.c

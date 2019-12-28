budgeting: ll.o budgeting.o
	gcc -o budgeting ll.o budgeting.o

budgeting.o: budgeting.c
	gcc -c budgeting.c

ll.o: ll.c ll.h
	gcc -c ll.c

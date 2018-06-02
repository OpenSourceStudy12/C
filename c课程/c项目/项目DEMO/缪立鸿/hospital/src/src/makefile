OBJECT:= common.o patient.o main.o menu.o doctor.o nurse.o admin.o tooler.o shared.o
INC:=-I ../inc
test:$(OBJECT)
	gcc -Wall -g $(OBJECT) -o test
common.o:common.c
	gcc -Wall -c common.c $(INC) -o common.o
patient.o:patient.c
	gcc -Wall -c patient.c $(INC) -o patient.o
main.o:main.c
	gcc -Wall -c main.c $(INC) -o main.o
menu.o:menu.c
	gcc -Wall -c menu.c $(INC) -o menu.o
doctor.o:doctor.c
	gcc -Wall -c doctor.c $(INC) -o doctor.o
nurse.o:nurse.c
	gcc -Wall -c nurse.c $(INC) -o nurse.o
admin.o:admin.c
	gcc -Wall -c admin.c $(INC) -o admin.o
tooler.o:tooler.c
	gcc -Wall -c tooler.c $(INC) -o tooler.o
shared.o:shared.c
	gcc -Wall -c shared.c $(INC) -o shared.o
clean:
	rm -f ./*.o

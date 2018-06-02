OBJECT:=admin.o tea.o stu.o menu.o tooler.o main.o
INC:=-I ../inc/ \
      -I /usr/include/ \
	-I ../include/
install:$(OBJECT)
	gcc $(OBJECT) -o install
admin.o:admin.c
	gcc -c $(INC) admin.c -o admin.o -g
tea.o:tea.c
	gcc -c $(INC)  tea.c -g
stu.o:stu.c
	gcc -c $(INC) stu.c -g 
menu.o:menu.c
	gcc -c $(INC) menu.c -g 
tooler.o:tooler.c
	gcc -c $(INC) tooler.c -g 
main.o:
	gcc -c $(INC) main.c -g
clear:
	rm -f *.o

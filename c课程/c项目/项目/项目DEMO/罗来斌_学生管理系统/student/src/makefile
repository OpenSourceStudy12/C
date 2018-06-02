OBJECT :=menu.o adm.o stu_main.o teacher_main.o check.o input.o manager_stu.o manage_teacher.o link.o term.o
INC :=../include/
install:$(OBJECT)
	gcc  $(OBJECT) -o install
menu.o:menu.c
	gcc   -I$(INC) -c menu.c -o menu.o
adm.o:adm.c
	gcc -I$(INC) -c adm.c -o adm.o
stu_main.o:stu_main.c
	gcc -I$(INC) -c stu_main.c -o stu_main.o
teacher_main.o:teacher_main.c
	gcc -I$(INC) -c teacher_main.c -o teacher_main.o
input.o:input.c 
	gcc -I$(INC) -c input.c -o input.o
manager_stu.o:manager_stu.c
	gcc -I$(INC) -c manager_stu.c -o manager_stu.o
manage_teacher.o:manage_teacher.c
	gcc -I$(INC) -c manage_teacher.c -o manage_teacher.o
link.o:link.c 
	gcc -I$(INC) -c  link.c -o link.o
check.o:check.c
	gcc -I$(INC) -c  check.c -o check.o
term.o:term.c
	gcc -I$(INC) -c  term.c -o term.o
	
clear:
	rm -f *.o


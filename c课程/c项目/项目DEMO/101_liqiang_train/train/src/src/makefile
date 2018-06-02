install:admin.o common.o menu.o train.o user.o
	gcc  admin.o common.o menu.o  train.o user.o -o install
admin.o:admin.c
	gcc -c -I ../inc -g admin.c 
common.o:common.c
	gcc -c -I ../inc -g common.c
menu.o:menu.c
	gcc -c -I ../inc -g menu.c
train.o:train.c
	gcc -c -I ../inc -g train.c
user.o:user.c
	gcc -c -I ../inc -g user.c
clean:
	rm -rf *.o install

OBJ = -c -I ../inc -g
OPJ = main.o menu.o user.o admin.o train.o data_deal.o

CROSS_COMPAILE = arm-linux-
CC = $(CROSS_COMPAILE)gcc

exe:$(OPJ)
	$(CC) $^  -o $@
	echo "CC = $(CC)"
%.o:%.c
	$(CC) $(OBJ) $^  -o $@

#menu.o:menu.c
#	$(CC) $(OBJ) menu.c  -o menu.o
#user.o:user.c
#	$(CC) $(OBJ) user.c  -o user.o
#admin.o:admin.c
#	$(CC) $(OBJ) admin.c -o admin.o
#train.o:train.c
#	$(CC) $(OBJ) train.c -o train.o
#data_deal.o:data_deal.c
#	$(CC) $(OBJ) data_deal.c -o data_deal.o

clean:
	rm -rf *.o *.swp *.swo

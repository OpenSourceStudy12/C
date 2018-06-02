OBJECT:=trainnu.o customer.o ticket.o cbuy.o main.o view.o tool.o maintool.o	
PATH1:=-I ../inc/
main:$(OBJECT)
	gcc $(OBJECT) -o main
trainnu.o:trainnu.c
	gcc $(PATH1) -c trainnu.c -o trainnu.o -g
customer.o:customer.c
	gcc $(PATH1) -c customer.c -o customer.o -g 
ticket.o:ticket.c
	gcc $(PATH1) -c ticket.c -o ticket.o -g
cbuy.o:cbuy.c
	gcc $(PATH1) -c cbuy.c -o cbuy.o -g
view.o:view.c
	gcc $(PATH1) -c view.c -o view.o -g
main.o:main.c
	gcc $(PATH1) -c main.c -o main.o -g	
tool.o:tool.c
	gcc $(PATH1) -c tool.c -o tool.o -g
maintool.o:maintool.c
	gcc $(PATH1) -c maintool.c -o maintool.o -g
clean:
	rm -f *.o

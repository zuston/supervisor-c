zout:main.o zdb.o zstr.o
	gcc -o zout main.o zdb.o zstr.o

main.o:main.c zdb.h zstr.h zdebug.h
	gcc -c main.c

zdb.o:zdb.h zdebug.h zstr.h
	gcc -c zdb.c

zstr.o:zstr.h
	gcc -c zstr.c

clean:
	rm -rf zdb.o main.o zstr.o zout


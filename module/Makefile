executable=secret
secret: secret.h secret.o
	gcc secret.o main.c -o secret
secret.o: secret.h
	gcc -c secret.c -o secret.o
clean:
	rm $(executable) *.o

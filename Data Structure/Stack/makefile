CC = g++
CFLAGS = -Wall -g
 
stack.test.exe: stack.test.o
	$(CC) $(CFLAGS) stack.test.cpp  -o stack.test.exe
 
stack.test.o: stack.test.cpp
	$(CC) $(CFLAGS) -c stack.test.cpp

clean:
	del -f *.o stack.test.exe
CC = g++
CFLAGS = -Wall -g
 
node.test.exe: node.test.o
	$(CC) $(CFLAGS) node.test.cpp  -o node.test.exe
 
node.test.o: node.test.cpp
	$(CC) $(CFLAGS) -c node.test.cpp

clean:
	del -f *.o node.test.exe
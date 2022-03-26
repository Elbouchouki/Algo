CC = g++
CFLAGS = -Wall -g
 
queue.test.exe: queue.test.o
	$(CC) $(CFLAGS) queue.test.cpp  -o queue.test.exe
 
queue.test.o: queue.test.cpp
	$(CC) $(CFLAGS) -c queue.test.cpp

clean:
	del -f *.o queue.test.exe
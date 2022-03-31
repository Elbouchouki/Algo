CC = g++
CFLAGS = -Wall -g
 
deque.test.exe: deque.test.o
	$(CC) $(CFLAGS) deque.test.cpp  -o deque.test.exe
 
deque.test.o: deque.test.cpp
	$(CC) $(CFLAGS) -c deque.test.cpp

clean:
	del -f *.o deque.test.exe
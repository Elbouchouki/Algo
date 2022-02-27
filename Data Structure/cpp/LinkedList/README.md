## Complexities

 ```sh
**queue**

enqueue()      = O(1)
dequeue()      = O(1)
first()        = O(1)
last()         = O(1)

**stack**

push()         = O(1)
top()          = O(1)
pop()          = O(1)

**search**

first_index()  = {
    best  case :  O(1)
    worst case :  O(n)
}

last_index()   = {
    best  case :  O(n)
    worst case :  O(n)
}

**suppression**

delete_first() = {
    best  case :  O(1)
    worst case :  O(n)
}
delete_all()   = {
    best  case :  O(n)
    worst case :  O(n)
}

**sort**

sort()         = O(n^2)
swap()         = O(1)

**other**

display()      = O(n)
reverse()      = O(n)
```

## Usage

- Clone project : 
  
 ```console
Elbouchouki:~$ git clone https://github.com/Elbouchouki/Algorithms.git
Elbouchouki:~$ cd Algorithms/Data Structure/cpp/LinkedList/
```

- Compile program : 
  
 ```console
Elbouchouki:~$ g++ linkedList.cpp -o linkedList
```

- Execute program : 
  
 ```console
Elbouchouki:~$ ./inkedList.exe
```
class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next


class Queue:
    def __init__(self):
        self.head = None
        self.tail = None
        self._size = 0

    def push(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        self._size += 1

    def pop(self):
        if self.head is None:
            print("Error")
        else:
            val = self.head.value
            self.head = self.head.next
            if self.head is None:
                self.tail = None
            self._size -= 1
            print (val)

    def get(self):
        if self.head is None:
            print("Error")
        else:
            val = self.head.value
            print (val)

    def size(self):
        print(self._size)


n = int(input())
Q = Queue()

for i in range(n):
    s = input().split()
    match s[0]:
        case "push":
            Q.push(s[1])
        case "pop":
            Q.pop()
        case "get":
            Q.get()
        case "size":
            Q.size()




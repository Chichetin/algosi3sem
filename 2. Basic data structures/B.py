class Node:
    def __init__(self, value, prev=None, next=None, ):
        self.value = value
        self.prev = prev
        self.next = next


class Queue:
    def __init__(self):
        self.head = None
        self.tail = None
        self._size = 0

    def push_back(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node
        self._size += 1

    def push_front(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
        self._size += 1

    def pop_back(self):
        if self.tail is None:
            print("Error")
        else:
            val = self.tail.value
            self.tail = self.tail.prev
            if self.tail is not None:
                self.tail.next = None
            if self.tail is None:
                self.head = None
            self._size -= 1
            print (val)

    def pop_front(self):
        if self.head is None:
            print("Error")
        else:
            val = self.head.value
            self.head = self.head.next
            if self.head is not None:
                self.head.prev = None
            if self.head is None:
                self.tail = None
            self._size -= 1
            print (val)

    def get_back(self):
        if self.tail is None:
            print("Error")
        else:
            val = self.tail.value
            print (val)

    def get_front(self):
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
            if s[1] == "front":
                Q.push_front(s[2])
            else:
                Q.push_back(s[2])
        case "pop":
            if s[1] == "front":
                Q.pop_front()
            else:
                Q.pop_back()
        case "get":
            if s[1] == "front":
                Q.get_front()
            else:
                Q.get_back()
        case "size":
            Q.size()




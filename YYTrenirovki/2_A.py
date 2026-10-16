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
        print("ok")

    def pop(self):
        if self.head is None:
            print("error")
        else:
            val = self.head.value
            self.head = self.head.next
            if self.head is None:
                self.tail = None
            self._size -= 1
            print (val)


    def get(self):
        if self.head is None:
            print("error")
        else:
            val = self.head.value
            print (val)
    def size(self):
        print(self._size)

    def clear(self):
        self.head = None
        self.tail = None
        self._size = 0
        print("ok")


def main():
    q = Queue()

    while True:
        s = input().split()
        match s[0]:
            case "push":
                q.push(s[1])
            case "pop":
                q.pop()
            case "front":
                q.get()
            case "size":
                q.size()
            case "clear":
                q.clear()
            case "exit":
                print("bye")
                break


if __name__ == "__main__":
    main()
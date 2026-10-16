import sys


class Heap:
    def __init__(self):
        self.data = []

    def insert(self, k):
        self.data.append(k)
        # поднимаем новый элемент, пока он больше родителя
        i = len(self.data) - 1
        while i > 0 and self.data[(i - 1) // 2] < self.data[i]:
            parent = (i - 1) // 2
            self.data[i], self.data[parent] = self.data[parent], self.data[i]
            i = parent

    def extract(self):
        top = self.data[0]
        last = self.data.pop()
        if len(self.data) == 0:
            return top

        # последний элемент ставим в корень и опускаем, меняя с большим из сыновей
        self.data[0] = last
        i = 0
        while True:
            left = 2 * i + 1
            right = 2 * i + 2
            big = i
            if left < len(self.data) and self.data[left] > self.data[big]:
                big = left
            if right < len(self.data) and self.data[right] > self.data[big]:
                big = right
            if big == i:
                break
            self.data[i], self.data[big] = self.data[big], self.data[i]
            i = big

        return top


def main():
    data = sys.stdin.buffer.read().split()

    n = int(data[0])
    heap = Heap()
    ans = []

    pos = 1
    for _ in range(n):
        cmd = data[pos]
        pos += 1
        match cmd:
            case b"0":
                heap.insert(int(data[pos]))
                pos += 1
            case b"1":
                ans.append(str(heap.extract()))

    sys.stdout.write('\n'.join(ans))


if __name__ == '__main__':
    main()

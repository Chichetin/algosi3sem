import sys
from collections import deque


def main():
    data = sys.stdin.buffer.read().split()

    n = int(data[0])
    first = deque()   # начало очереди, тут лежит половина с округлением вверх
    second = deque()  # хвост очереди, середина всегда на стыке деков
    ans = []

    pos = 1
    for _ in range(n):
        cmd = data[pos]
        pos += 1
        match cmd:
            case b"+":
                second.append(int(data[pos]))
                pos += 1
            case b"*":
                second.appendleft(int(data[pos]))
                pos += 1
            case b"-":
                ans.append(str(first.popleft()))

        # после каждого запроса выравниваем половины
        if len(first) < len(second):
            first.append(second.popleft())
        elif len(first) > len(second) + 1:
            second.appendleft(first.pop())

    sys.stdout.write('\n'.join(ans))


if __name__ == '__main__':
    main()

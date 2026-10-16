import sys
from collections import deque


def main():
    data = sys.stdin.buffer.read().split()

    n = int(data[0])
    commands = deque(map(int, data[1:1 + n]))
    leader = max(commands)

    # пока самая сильная команда не добралась до начала очереди, матчи не повторяются - запоминаем их
    matches = []
    while commands[0] != leader:
        p1 = commands.popleft()
        p2 = commands.popleft()
        matches.append((p1, p2))
        if p1 > p2:
            commands.appendleft(p1)
            commands.append(p2)
        else:
            commands.appendleft(p2)
            commands.append(p1)

    q = int(data[1 + n])
    ans = []
    for i in range(q):
        k = int(data[2 + n + i])
        if k <= len(matches):
            p1, p2 = matches[k - 1]
        else:
            # дальше лидер бьет всех подряд, очередь крутится с периодом n - 1
            k = (k - len(matches) - 1) % (n - 1)
            p1 = leader
            p2 = commands[k + 1]
        ans.append(str(p1) + ' ' + str(p2))

    sys.stdout.write('\n'.join(ans))


if __name__ == '__main__':
    main()

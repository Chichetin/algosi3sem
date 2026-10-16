import sys
from math import inf


def main():
    data = sys.stdin.buffer.read().split()

    # читаем подряд четыре массива и каждый сразу сортируем
    arrays = []
    pos = 0
    for i in range(4):
        n = int(data[pos])
        arrays.append(sorted(map(int, data[pos + 1:pos + 1 + n])))
        pos += 1 + n

    idx = [0] * 4
    best = inf
    ans = []
    while True:
        cur = [arrays[i][idx[i]] for i in range(4)]
        mn = min(cur)
        mx = max(cur)
        if mx - mn < best:
            best = mx - mn
            ans = cur

        # сдвигаем указатель самого светлого элемента, только так разница может уменьшиться
        k = cur.index(mn)
        idx[k] += 1
        if idx[k] == len(arrays[k]):
            break

    print(' '.join(map(str, ans)))


if __name__ == '__main__':
    main()

import sys


# сливаем a и b в res, идем сразу тремя указателями
def merge(a, b, res):
    i = 0
    j = 0
    k = 0
    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            res[k] = a[i]
            i += 1
        else:
            res[k] = b[j]
            j += 1
        k += 1

    while i < len(a):
        res[k] = a[i]
        i += 1
        k += 1

    while j < len(b):
        res[k] = b[j]
        j += 1
        k += 1


def main():
    data = sys.stdin.buffer.read().split()

    n = int(data[0])
    a = list(map(int, data[1:1 + n]))
    m = int(data[1 + n])
    b = list(map(int, data[2 + n:2 + n + m]))

    res = [0] * (n + m)
    merge(a, b, res)

    sys.stdout.write(' '.join(map(str, res)))


if __name__ == '__main__':
    main()

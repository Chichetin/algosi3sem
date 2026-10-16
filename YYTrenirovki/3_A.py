import sys


# разбиваем arr[left:right] по предикату и возвращаем конец подходящей части
def partition(arr, left, right, pred):
    k = left  # в arr[left:k] уже лежат элементы, для которых предикат верен
    for i in range(left, right):
        if pred(arr[i]):
            arr[i], arr[k] = arr[k], arr[i]
            k += 1
    return k


def main():
    data = sys.stdin.buffer.read().split()

    n = int(data[0])
    arr = list(map(int, data[1:1 + n]))
    x = int(data[1 + n])

    k = partition(arr, 0, n, lambda value: value < x)
    print(k)
    print(n - k)


if __name__ == '__main__':
    main()

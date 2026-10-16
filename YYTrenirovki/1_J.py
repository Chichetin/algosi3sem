import sys

ans = []


def move(n, x, y):
    if n == 0:
        return
    z = 6 - x - y  # третий стержень, номера всегда дают в сумме 6
    # сначала снимаем верхние n - 1 дисков на запасной стержень
    move(n - 1, x, z)
    ans.append(str(n) + ' ' + str(x) + ' ' + str(y))
    # и возвращаем их обратно уже поверх самого большого диска
    move(n - 1, z, y)


def main():
    n = int(input())
    move(n, 1, 3)
    sys.stdout.write('\n'.join(ans))


if __name__ == '__main__':
    main()

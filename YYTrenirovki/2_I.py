import sys
import heapq


def main():
    data = sys.stdin.buffer.read().split()

    n = int(data[0])
    nums = list(map(int, data[1:1 + n]))
    heapq.heapify(nums)

    # каждый раз складываем два самых маленьких - тогда большие числа реже попадают в промежуточные суммы
    total = 0
    for i in range(n - 1):
        a = heapq.heappop(nums)
        b = heapq.heappop(nums)
        heapq.heappush(nums, a + b)
        total += a + b

    # 5% считаем в центах, чтобы не ловить погрешность float
    cents = total * 5
    print(str(cents // 100) + '.' + str(cents % 100).zfill(2))


if __name__ == '__main__':
    main()

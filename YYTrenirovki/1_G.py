import sys
from collections import deque


def main():
    """
    Пример ввода и вывода числа n, где -10^9 < n < 10^9:
    n = int(input())
    print(n)
    """
    n = int(input())
    arr = list(map(int, input().split()))
    ans = [-1] * n

    stack = deque()
    for i in range(len(arr)):
        while len(stack) > 0 and arr[stack[-1]] > arr[i]:
            ans[stack[-1]] = i
            stack.pop()
        stack.append(i)
    for a in ans:
        print(a, end=" ")







if __name__ == '__main__':
    main()

import sys
from collections import deque
def main():
    prices = list(map(int, sys.stdin.buffer.read().split()))
    n = len(prices)
    ans = [-1] * n

    stack = deque()

    for i in range(n):
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()
        if len(stack) == 0:
            ans[i] = i + 1
        else:
            ans[i] = i +1  - (stack[-1] + 1)
        stack.append(i)

    sys.stdout.write(' '.join(map(str, ans)))


if __name__ == "__main__":
    main()
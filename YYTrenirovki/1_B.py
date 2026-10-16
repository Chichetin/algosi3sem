from collections import deque
import sys

def get_paired(left: str):
    dictinoray = {
        "(": ")",
        "{": "}",
        "[": "]"
    }
    return dictinoray[left]

def main():
    n = int(input())
    order = input()
    string = input() #начальная строка

    # из string создаем уже какой-то стек
    stack = deque()
    for s in string:
        if s in "({[":
            stack.append(s)
        else:
            stack.pop()

    while len(stack) < n - len(string):
        for br in order:
            if br in "({[":
                string = string + br
                stack.append(br)
                break
            else:
                if len(stack) > 0 and get_paired(stack[-1]) == br:
                    stack.pop()
                    string = string + br
                    break

    while len(stack) != 0:
        string = string + get_paired(stack.pop())

    print(string)
if __name__ == '__main__':
    main()

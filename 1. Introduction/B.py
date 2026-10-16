n, m = map(int, input().split())
str = ""
arr = list(input())
for i in range(n):
    str = str + arr[i]
    print(int(str) % m, end=" ")
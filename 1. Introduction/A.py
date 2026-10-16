def move_in_dir(i, j, dir):
    match dir:
        case 0:
            i -= 1
        case 1:
            j += 1
        case 2:
            i += 1
        case 3:
            j -= 1

    if (0 <= i < n) and (0 <= j < m) and (used[i][j] == 0):
        return i, j
    else:
        return -1


global n
global m
n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
used = [[0] * m for _ in range(n)]

i = 0
j = 0
dir = 0
cnt = 0
while cnt != n * m - 1 :
    print(arr[i][j], end=" ")
    used[i][j] = 1
    cnt += 1


    while move_in_dir(i, j, dir) == -1:
        dir = (dir + 1)% 4

    i, j = move_in_dir(i, j, dir)
print(arr[i][j], end=" ")
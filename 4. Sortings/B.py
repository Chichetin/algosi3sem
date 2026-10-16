ans = 0

def merge(arr1: list, arr2: list):
    arr_merged = []
    global ans

    if len(arr2) == 1:
        if len(arr1) == 1:
            if arr1[0] <= arr2[0]:
                return [arr1[0], arr2[0]]
            else:
                ans += 1
                return [arr2[0], arr1[0]]
        else:
            return [arr2[0]]


    arr1 = merge(arr1[:len(arr1) // 2], arr1[len(arr1) // 2:])
    arr2 = merge(arr2[:len(arr2) // 2], arr2[len(arr2) // 2:])

    i = 0
    j = 0
    while i < len(arr1) and j < len(arr2):
        if arr1[i] <= arr2[j]:
            arr_merged.append(arr1[i])
            i += 1
        else:
            arr_merged.append(arr2[j])
            ans += len(arr1) - i
            j += 1

    for k in range(i, len(arr1)):
        arr_merged.append(arr1[k])
    for k in range(j, len(arr2)):
        arr_merged.append(arr2[k])

    return arr_merged


def main():
    n = int(input())
    arr =  list(map(int, input().split()))

    merge(arr[:n//2], arr[n//2:])
    global ans

    print(ans)

if __name__ == "__main__":
    main()

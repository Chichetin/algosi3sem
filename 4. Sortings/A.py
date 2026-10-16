def main():
    n, m = list(map(int, input().split()))
    arr1 =  list(map(int, input().split()))
    arr2 =  list(map(int, input().split()))

    ans = []

    i = 0
    j = 0
    while i < len(arr1) and j < len(arr2):
        if arr1[i] <= arr2[j]:
            ans.append(arr1[i])
            i += 1
        else:
            ans.append(arr2[j])
            j += 1

    for k in range(i, len(arr1)):
        ans.append(arr1[k])
    for k in range(j, len(arr2)):
        ans.append(arr2[k])

    print(" ".join(map(str, ans)))


if __name__ == "__main__":
    main()
N, K = map(int, raw_input().split())

arr = raw_input().split()
arr = [int(i) for i in arr]

def cnstrt_boat(boat, K, index, count): 
    if K == 0:
        print count
        return 
    else:
        for i in range(index, len(arr)):
            if boat == []:
                boat.append(arr[i])
                index = i+1
                cnstrt_boat(boat, K-1, index, count+1)
            elif arr[i] != boat[-1]:
                boat.append(arr[i])
                index = i+1
                cnstrt_boat(boat, K-1, index, count+1)


cnstrt_boat([], K, 0, 0)

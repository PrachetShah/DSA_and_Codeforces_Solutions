# finding pivot element in rotated array

arr = [7, 9, 2, 4, 6]
arr2 = [6,7,8,9,1,2,3,4,5]

def findPivoteElement(arr):
    print(arr)
    start, end = 0, len(arr)-1
    while(start < end):
        mid = (start) + (end-start)//2

        if arr[mid] >= arr[0]:
            start = mid+1
        else:
            end = mid
    print("Pivot is: ", arr[start])
    return start

findPivoteElement(arr)
findPivoteElement(arr2)
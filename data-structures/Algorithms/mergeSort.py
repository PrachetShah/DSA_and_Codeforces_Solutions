def merge(nums, low, mid, high):
    temp = []
    left = low
    right = mid+1
    while(left <=mid and right<=high):
        if nums[left] <= nums[right]:
            temp.append(nums[left])
            left += 1
        else:
            temp.append(nums[right])
            right += 1
    
    while(left <= mid):
        temp.append(nums[left])
        left += 1
    
    while(right <= high):
        temp.append(nums[right])
        right += 1
    
    # inserting from temp to original array
    for i in range(low, high+1):
        nums[i] = temp[i-low]

def mergeSort(nums, low, high):
    if low >= high:
        return
    
    mid = (low+high)//2
    mergeSort(nums, low, mid)
    mergeSort(nums, mid+1, high)
    merge(nums, low, mid, high)



nums = [5,2,6,4,3,1]
mergeSort(nums, 0, len(nums)-1)

nums2 = [324,1342,354,34,34,3243,545,0]
mergeSort(nums2, 0, len(nums2)-1)
print(nums2)
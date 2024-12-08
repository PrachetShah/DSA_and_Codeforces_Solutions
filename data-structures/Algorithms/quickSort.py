def partition(nums, low, high):
    pivot = nums[low]

    i, j = low, high
    while i < j:
        while nums[i] <= pivot and i<=high-1:
            i += 1
        while nums[j] > pivot and j>= low+1:
            j -= 1
        if i < j:
            nums[i], nums[j] = nums[j], nums[i]
    nums[low], nums[j] = nums[j], nums[low]
    return j

def quickSort(nums, low, high):
    if low >= high:
        return
    # find partition index
    partitionIndex = partition(nums, low, high)
    # call recursively on two subarrays
    quickSort(nums, low, partitionIndex-1)
    quickSort(nums, partitionIndex+1, high)

nums = [5,2,3,3,5,4,1]
quickSort(nums, 0 ,len(nums)-1)
print(nums)

nums2 = [324,1342,354,34,34,3243,545,0]
quickSort(nums2, 0, len(nums2)-1)
print(nums2)
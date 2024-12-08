### Dutch National Flag Problem

Asked Problems and Concepts

- Sort 0s 1s and 2s in array or LL
- Make sure 3 colors, with each color being adjacent to each other

TC: O(n), SC: O(1)

### Algorithm:

- Keep 3 pointers low, mid, high
- Traverse over the array till mid <= hi, according to the value of arr[mid] we can have three cases:
- arr[mid] = 0, then swap arr[lo] and arr[mid] and increment lo by 1 because all the zeros are till index lo – 1 and move to the next element so increment mid by 1.
- arr[mid] = 1, then move to the next element so increment mid by 1.
- arr[mid] = 2, then swap arr[mid] and arr[hi] and decrement hi by 1 because all the twos are from index hi + 1 to N – 1. Now, we don’t move to the next element because the element which is now at index mid can be a 0 and therefore needs to be checked again.

Basically a three pointers approach rather than two pointer one

```python
def sort_colors(arr) -> None:
low = 0
mid = arr[len(arr)//2]
high = len(arr)-1

    while mid <= high:
        if arr[mid] == 0:
            arr[low], arr[mid] = arr[mid], arr[low]
            low += 1
            mid += 1
        elif arr[mid] == 1:
            mid += 1
        else:
            arr[mid], arr[high] = arr[high], arr[mid]
            high -=1

arr = [0,1,2,2,1,1,0,0,2]
print(arr)
sort_colors(arr)
print(arr)
```
